#include "function.h"

extern ofstream gout;


extern ofstream oout;
Function_type::Function_type()
{
	totalArgSize = 0;
	totalParamSize = 0;
}
void Function_type::enter(AST_node* t)
{



	

	funcSymbol_p = symbolExtractor_type::getFuncSymbol(t);
	Scope_type::declare(funcSymbol_p);
	Scope_type::enter();
	
	/*
	for (auto rit = funcSymbol_p->argList.rbegin(); rit != funcSymbol_p->argList.rend(); rit++)
	{
		auto argSymbol_p = *rit;
		Scope_type::declare(argSymbol_p);
	}
	*/



	for (auto argSymbol_p : funcSymbol_p->argList)
	{

		Scope_type::declare(argSymbol_p);
		// here deals all the arguments.
		// the standard calling function can be complex when dealing struct argument,
		// so here I just push all the args into stack
		auto stackMemory_p = new stackMemory_type();
		stackMemory_p->offset1 = totalArgSize + 16;
		stackMemory_p->size = argSymbol_p->type_p->getSize();
		stackMemory_p->base = &(Register_type::Reg_RBP);
		
		stackMemory_p->offset2 = nullptr;
		stackMemory_p->offset3 = 0;
		totalArgSize += stackMemory_p->size;
		argSymbol_p->memory_p = stackMemory_p;



	}

	
	CFG_p = new CFG_type();
	
	//CFG_p->CFGEntry_p->exit.defaultEgress_p = CFG_p->CFGExit_p;
	cur_p = CFG_p->CFGEntry_p;
	for (auto child: t->child[2]->child)
	{
		walk(child);
	}
	CFG_p->optimize();
	CFG_p->offset = -totalParamSize;
}



void Function_type::leave()
{
	Scope_type::leave();
}




void Function_type::walk(AST_node *t)
{


	cerr << ASTNode_dic[t->get_nodeType()] << endl;
	if (t->get_nodeType() == SHOW_STAB)
	{

		Scope_type::print();
	}
	
	else if (t->get_nodeType() == STRUCT_DECL)
	{

		auto structSymbol_p = symbolExtractor_type::getStructSymbol(t);
		if (nullptr != structSymbol_p)
		{
			Scope_type::declare(structSymbol_p);
			symbolExtractor_type::addStructField(structSymbol_p, t);
		}

	}
	else if (t->get_nodeType() == VAR_DECL)
	{
		for (auto varSymbol_p: *(symbolExtractor_type::getVarSymbolList(t)))
		{

			Scope_type::declare(varSymbol_p);
			auto stackMemory_p = new stackMemory_type();


			stackMemory_p->size = varSymbol_p->type_p->getSize();
			totalParamSize += stackMemory_p->size;

			//cerr << totalParamSize << endl;
			stackMemory_p->base = &(Register_type::Reg_RBP);

			if (varSymbol_p->name == "array")
			{

				cerr << "size: " << varSymbol_p->type_p->getSize() << " " << totalParamSize << endl;
			}

			stackMemory_p->offset1 = -(totalParamSize);

			varSymbol_p->memory_p = stackMemory_p;

		}

	}
	else if (t->get_nodeType() == COMPOUND_STMT)
	{
		Scope_type::enter();
		for (auto child: t->child)
		{
			walk(child);
		}
		Scope_type::leave();
	}
	else if (t->get_nodeType() == SELECTION_STMT)
	{
		if (t->child.size() == 2)
		{
			// for IF statement such as IF (A) {B} C
			// translate A into current basic block, and here comes its end.
			// set the exit of the current bb, a conditional one
			// if condition, in representation of value of A, is matched,
			// go to B as a new bb,
			// otherwise in default go to C, as a new bb

			auto A_p = cur_p;
			auto B_p = CFG_p->startBasicBlock();
			//basicBlock_type *C_p;
			auto C_p = CFG_p->startBasicBlock();
			/*
			if (A_p->exit.defaultEgress_p != nullptr)
			{
				C_p = A_p->exit.defaultEgress_p;
				
			}
			else
			{
				C_p = CFG_p->startBasicBlock();
				A_p->exit.defaultEgress_p = C_p;
			}*/

			C_p->exit.defaultEgress_p = A_p->exit.defaultEgress_p;
			
			B_p->exit.defaultEgress_p = C_p;
			quadTranslator::transExpr(static_cast<Expression_node*>(t->child[0]), &(cur_p->quadList));


			A_p->exit.condEgress_p = B_p;
			A_p->exit.condExpr_p = A_p->quadList.back();


			cur_p = B_p;
			walk(t->child[1]);
			cur_p = C_p;

		}
		else if (t->child.size() == 3)
		{
			// IF (A) {B} ELSE {C} D
			// similar, just use your brain
			// it's just a expansion of graph node.

			auto A_p = cur_p;
			auto B_p = CFG_p->startBasicBlock();
			auto C_p = CFG_p->startBasicBlock();
			//basicBlock_type *D_p;

			auto D_p = CFG_p->startBasicBlock();
			
			/*
			if (A_p->exit.defaultEgress_p != nullptr)
			{
				D_p = A_p->exit.defaultEgress_p;
			}
			else
			{
				D_p = CFG_p->startBasicBlock();
			}
			*/

			D_p->exit.defaultEgress_p = A_p->exit.defaultEgress_p;
			
			
			quadTranslator::transExpr(static_cast<Expression_node*>(t->child[0]), &(cur_p->quadList));
			A_p->exit.condEgress_p = B_p;
			A_p->exit.condExpr_p = A_p->quadList.back();
			A_p->exit.defaultEgress_p = C_p;

			B_p->exit.defaultEgress_p = D_p;
			C_p->exit.defaultEgress_p = D_p;
			
			cur_p = B_p;
			walk(t->child[1]);
			cur_p = C_p;
			walk(t->child[2]);
			cur_p = D_p;
		}

	}
	else if (t->get_nodeType() == EXPRESSION_STMT)
	{


		if (t->child.size() != 0)
		{

			quadTranslator::transExpr(static_cast<Expression_node*>(t->child[0]), &(cur_p->quadList));
			
		}
	}

	else if (t->get_nodeType() == JUMP_STMT)
	{
		auto jumpStmt_p = static_cast<jumpStmt_node*>(t);
		if (jumpStmt_p->jump_type == jumpStmt_node::RETURN)
		{
			// whenever a RETURN statement shows up,
			// you should directly end the current bb, and set the egress link to the 
			// exit bb of the function.

			cur_p->exit.defaultEgress_p = CFG_p->CFGExit_p;
			if (jumpStmt_p->child.size() == 1)
			{
				auto expr_p = static_cast<Expression_node*>(jumpStmt_p->child[0]);
				quadTranslator::transExpr(expr_p, &(cur_p->quadList));


				if (!(*(expr_p->type_p) ==  *(funcSymbol_p->type_p)))
				{
					cerr << "wrong return type of function " << funcSymbol_p->name << endl;
				}
			}
			cur_p = CFG_p->startBasicBlock();
		}


	}
	
	else if (t->get_nodeType() == ITERATION_STMT)
	{
		if (t->child.size() == 2)
		{

			// WHILE
			auto iterationStmt_p = static_cast<iterationStmt_node*>(t);
			auto A_p = cur_p;
			auto B_p = CFG_p->startBasicBlock();
			auto C_p = CFG_p->startBasicBlock();
			auto D_p = CFG_p->startBasicBlock();
			//basicBlock_type *D_p;

			/*
			if (A_p->exit.defaultEgress_p != nullptr)
			{
				D_p = A_p->exit.defaultEgress_p;
			}
			else
			{
				D_p = CFG_p->startBasicBlock();
			}
			*/
			D_p->exit.defaultEgress_p = A_p->exit.defaultEgress_p;
			A_p->exit.defaultEgress_p = B_p;

			auto expr_p = static_cast<Expression_node*>(t->child[0]);
			quadTranslator::transExpr(expr_p, &(B_p->quadList));
			B_p->exit.condEgress_p = C_p;
			B_p->exit.condExpr_p = B_p->quadList.back();
			B_p->exit.defaultEgress_p = D_p;
			C_p->exit.defaultEgress_p = B_p;
			cur_p = C_p;
			walk(t->child[1]);
			cur_p = D_p;			
		}
		

	}
	

}



void Function_type::print()
{
	gout << "function: " << funcSymbol_p->name << endl;

	CFG_p->print();
}


void Function_type::transASM()
{
	oout << ".type\t" << funcSymbol_p->name << ", @function" << endl;
	oout << ".text\t" << endl;
	
	for (auto bb_p: CFG_p->CFG)
	{
		bb_p->offset = -totalParamSize;
	}

	entryRoutine();
	CFG_p->transASM();

	
}



void Function_type::entryRoutine()
{
	oout << funcSymbol_p->name << ":" << endl;

	oout << "\tpushq\t" << "%rbp" << endl;
	oout << "\tmovq\t" << "%rsp, %rbp" << endl;

}