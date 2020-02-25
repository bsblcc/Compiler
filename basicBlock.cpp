#include "basicBlock.h"

extern ofstream gout;
extern ofstream oout;
/*
uncExit_type::uncExit_type()
{
	exitType = Exit_type::UNC;
}
condExit_type::condExit_type()
{
	exitType = Exit_type::COND;
}*/


int basicBlock_type::count = 0;

basicBlock_type::basicBlock_type()
{
	id = ++count;
	exit.condEgress_p = nullptr;
	exit.condExpr_p = nullptr;
	exit.defaultEgress_p = nullptr;
	reachable = false;

	varSSATable_p = new map<varSymbol_type*, Expression_node*> ();

	locationMap_p = new map<Expression_node*, Location_type*> ();

	
	//registerList.push_back(&Register_type::Reg_RAX);
	registerList.push_back( (&Register_type::Reg_RBX));
	registerList.push_back( (&Register_type::Reg_RSI));
	registerList.push_back( (&Register_type::Reg_RDI));
	registerList.push_back( (&Register_type::Reg_R8));
	registerList.push_back( (&Register_type::Reg_R9));
	registerList.push_back( (&Register_type::Reg_R10));
	registerList.push_back( (&Register_type::Reg_R11));
	registerList.push_back( (&Register_type::Reg_R12));
	registerList.push_back( (&Register_type::Reg_R13));
	registerList.push_back( (&Register_type::Reg_R14));
	//registerList.push_back( (&Register_type::Reg_R15));


}

void basicBlock_type::print()
{
	gout << "bb#" << id << endl;
	for (auto expr_p: quadList)
	{
		expr_p->printQuad();
	}
	gout << "egress links:" << endl;

	if (exit.condEgress_p != nullptr)
	{
		gout << "goto BB#" << exit.condEgress_p->id << " in condition of Quad#" << exit.condExpr_p->id << endl;		
	}
	if (exit.defaultEgress_p != nullptr)
	{
		gout << "goto BB#" << exit.defaultEgress_p->id << " on default" << endl;
	}

	gout << "used vars:" << endl;
	
	for (auto i: *varSSATable_p)
	{
		gout << i.first->name << endl;
	}

	gout << endl << endl;
}

void basicBlock_type::getVarList()
{
	
	for (auto expr_p: quadList)
	{
		if (expr_p->get_nodeType() == PRIMARY_EXPR)
		{
			auto primaryExpr_p = static_cast<primaryExpr_node*>(expr_p);
			if (primaryExpr_p->valueType == primaryExpr_node::ID)
			{
				auto var_p = Scope_type::find_varSymbol(primaryExpr_p->primaryValue);
				if (nullptr != var_p)
				{
					(*varSSATable_p)[var_p] = nullptr;
				}
			}
		}

		for (auto c : expr_p->child)
		{
			static_cast<Expression_node*>(c)->usage++;
		}
	}
	
}


void basicBlock_type::transPrimary(primaryExpr_node *primaryExpr_p)
{
	if (primaryExpr_p->valueType == primaryExpr_node::ID)
	{



		
		auto varSymbol_p = Scope_type::find_varSymbol(primaryExpr_p->primaryValue);
		if (varSymbol_p == nullptr)
		{
			return;
		}

		cerr << varSymbol_p->name << endl;
		/*if (varSymbol_p->register_p != nullptr)
		{

			(*locationMap_p)[primaryExpr_p] = varSymbol_p->register_p;
		}
		else*/
		{

			(*locationMap_p)[primaryExpr_p] = varSymbol_p->memory_p;

		}
	}

	else if (primaryExpr_p->valueType == primaryExpr_node::INT)
	{
		auto immediate_p = new Immediate_type();
		stringstream ss;
		ss << primaryExpr_p->primaryValue;
		ss >> immediate_p->value;

		(*locationMap_p)[primaryExpr_p] = immediate_p;
	}
}

void basicBlock_type::transPostfix(postfixExpr_node *postfixExpr_p)
{
	if (postfixExpr_node::FUNC_CALL_OP == postfixExpr_p->expr_operator)
	{

		
		for (auto reg_p : registerList)
		{
			if (reg_p->expr_p == nullptr)
			{
				continue;
			}
			if (reg_p->expr_p->usage > 0)
			{
				flushRegister(reg_p);
			}
		}
		

		auto reg_p = selectRegister();
		//int sum = 0;

		for (auto rit = postfixExpr_p->child[1]->child.rbegin(); rit != postfixExpr_p->child[1]->child.rend(); rit++)
		{

			auto e = static_cast<Expression_node*>(*rit);
			auto tmp1 = locationMap_p->find(e)->second;

			if (tmp1->locationType == Location_type::MEMORY)
			{

				auto tmp2 = static_cast<Memory_type*>(tmp1);
				auto x = new stackMemory_type();
				
				
				if (tmp2->memoryType == Memory_type::STACK)
				{
					auto tmp3 = static_cast<stackMemory_type*>(tmp2);
					auto y = new stackMemory_type(tmp3);
					
					offset -= tmp3->size;
					//sum += tmp3->size;
					x->offset1 = offset;

					for (int i = 0; i < tmp3->size; i += 8)
					{

						cerr << (tmp3->getStr()) << endl;
						ASMTranslator_type::transMov(y, reg_p);
						ASMTranslator_type::transMov(reg_p, x);
						y->offset1 -= 8;
						x->offset1 -= 8;
					}
				}
			}
			else 
			{
				offset -= 8;
				auto x = new stackMemory_type();
				x->offset1 = offset;
				x->offset2 = nullptr;
				ASMTranslator_type::transMov(tmp1, x);

			}
		}


		auto immediate_p = new Immediate_type();
		immediate_p->value = -offset;
		//ASMTranslator_type::transSub(immediate_p, &(Register_type::Reg_RSP));
		oout << "\tsubq\t" << immediate_p->getStr() << ", " << "%rsp" << endl;
		oout << "\tcall\t" << static_cast<primaryExpr_node*>(postfixExpr_p->child[0])->primaryValue << endl;


		oout << "\taddq\t" << immediate_p->getStr() << ", " << "%rsp" << endl;


		auto resReg_p = selectRegister();
		ASMTranslator_type::transMov(&(Register_type::Reg_RAX), resReg_p);
		(*locationMap_p)[postfixExpr_p] = resReg_p;

		resReg_p->expr_p = postfixExpr_p;

	}
	else if (postfixExpr_node::SUBSCRIPT_OP == postfixExpr_p->expr_operator)
	{
		auto arg1 = static_cast<Expression_node*>(postfixExpr_p->child[0]);
		auto arg2 = static_cast<Expression_node*>(postfixExpr_p->child[1]);

		auto loc1 = locationMap_p->find(arg1)->second;
		auto loc2 = locationMap_p->find(arg2)->second;

		// assume that the array is always on stack

		auto stackMemory_p = static_cast<stackMemory_type*>(loc1);

		
		Register_type *reg_p;

		//ASMTranslator_type::transMov(loc2, reg_p);
		/*
		oout << "\txor\t" << reg_p->getStr() << ", " << reg_p->getStr() << endl;
		oout << "\tmovq\t" << loc2->getStr() << ", " << reg_p->getStr() << endl;
		*/

		

		if (loc2->locationType != Location_type::REGISTER)
		{
			reg_p = replaceRegister(arg2);
		}
		else
		{
			reg_p = static_cast<Register_type*>(loc2);
		}



		auto subType_p = new Type_type(arg1->type_p);
		subType_p->specifierList.pop_front();
		int typeSize = subType_p->getSize();
		auto immediate_p = new Immediate_type();

		immediate_p->value = typeSize;


		ASMTranslator_type::transMul(immediate_p, reg_p);

		auto resLoc_p = new stackMemory_type();
		resLoc_p->offset1 = stackMemory_p->offset1;


		resLoc_p->offset2 = reg_p;
		resLoc_p->offset3 = 1;

		resLoc_p->size = typeSize;

		stackMemory_p->base = &(Register_type::Reg_RBP);


		(*locationMap_p)[postfixExpr_p] = resLoc_p;
		reg_p->expr_p = postfixExpr_p;

	}

	else if (postfixExpr_node::DOT_OP == postfixExpr_p->expr_operator)
	{

		
		auto arg1 = static_cast<Expression_node*>(postfixExpr_p->child[0]);
		auto structType_p = static_cast<structType_type*>(arg1->type_p->baseType_p);

		int offset;
		int typeSize;
		for (auto field_p : structType_p->fieldList)
		{
			if (field_p->name == postfixExpr_p->memberName)
			{
				offset = field_p->offset;
				typeSize = field_p->type_p->getSize();
				break;
			}
		}
		// also assume that struct vars are always on the stack

		auto loc1 = static_cast<stackMemory_type*>(locationMap_p->find(arg1)->second);

		//cerr << loc1->getStr() << endl;
		auto resLoc_p = new stackMemory_type(loc1);

		
		resLoc_p->offset1 += offset;
		resLoc_p->size = typeSize;
		(*locationMap_p)[postfixExpr_p] = resLoc_p;

		resLoc_p->base->expr_p = postfixExpr_p;

		if (resLoc_p->offset2 != nullptr)
		{
			resLoc_p->offset2->expr_p = postfixExpr_p;

		}
		
	}

	else if (postfixExpr_node::AR_OP == postfixExpr_p->expr_operator)
	{
		auto arg1 = static_cast<Expression_node*>(postfixExpr_p->child[0]);
		auto structType_p = static_cast<structType_type*>(arg1->type_p->baseType_p);

		int offset;
		int typeSize;
		for (auto field_p : structType_p->fieldList)
		{
			if (field_p->name == postfixExpr_p->memberName)
			{
				offset = field_p->offset;
				typeSize = field_p->type_p->getSize();
				break;
			}
		}


		auto loc1 = locationMap_p->find(arg1)->second;

		//Register_type *reg_p = &(Register_type::Reg_EDI);
		Register_type *reg_p;
		if (loc1->locationType != Location_type::REGISTER)
		{
			reg_p = replaceRegister(arg1);
		}
		else
		{
			reg_p = static_cast<Register_type*>(loc1);
		}
		
		/*
		oout << "\txor\t" << reg_p->getStr() << ", " << reg_p->getStr() << endl;
		oout << "\tmovq\t" << loc1->getStr() << ", " << reg_p->getStr() << endl;
		*/

		auto resLoc_p = new stackMemory_type();

		resLoc_p->base = reg_p;
		resLoc_p->offset1 = offset;
		resLoc_p->offset2 = nullptr;

		resLoc_p->size = typeSize;

		(*locationMap_p)[postfixExpr_p] = resLoc_p;

		reg_p->expr_p = postfixExpr_p;

	}
	else if (postfixExpr_node::INC_OP == postfixExpr_p->expr_operator)
	{


		auto arg1 = static_cast<Expression_node*>(postfixExpr_p->child[0]);

		auto immediate_p = new Immediate_type();

		auto reg_p = selectRegister();

		if (arg1->type_p->specifierList.size() == 0)
		{
			immediate_p->value = 1;
		}
		else
		{
			auto subType_p = new Type_type(arg1->type_p);
			subType_p->specifierList.pop_front();
			immediate_p->value = subType_p->getSize();
		}
		

		auto loc1 = locationMap_p->find(arg1)->second;

		auto tmp = static_cast<stackMemory_type*>(loc1);
		
		ASMTranslator_type::transAdd(immediate_p, loc1);

		ASMTranslator_type::transMov(loc1, reg_p);

		reg_p->expr_p = postfixExpr_p;
		(*locationMap_p)[postfixExpr_p] = reg_p;
	}

	else if (postfixExpr_node::DEC_OP == postfixExpr_p->expr_operator)
	{
		auto arg1 = static_cast<Expression_node*>(postfixExpr_p->child[0]);

		auto immediate_p = new Immediate_type();

		auto reg_p = selectRegister();

		if (arg1->type_p->specifierList.size() == 0)
		{
			immediate_p->value = 1;
		}
		else
		{
			auto subType_p = new Type_type(arg1->type_p);
			subType_p->specifierList.pop_front();
			immediate_p->value = subType_p->getSize();
		}
		

		auto loc1 = locationMap_p->find(arg1)->second;


		ASMTranslator_type::transSub(immediate_p, loc1);
		ASMTranslator_type::transMov(loc1, reg_p);

		reg_p->expr_p = postfixExpr_p;
		(*locationMap_p)[postfixExpr_p] = reg_p;
	}
}

void basicBlock_type::transUnary(unaryExpr_node *unaryExpr_p)
{
	if (unaryExpr_p->expr_operator == unaryExpr_node::INC_OP)
	{
		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto immediate_p = new Immediate_type();

		if (arg1->type_p->specifierList.size() == 0)
		{
			immediate_p->value = 1;
		}
		else
		{
			auto subType_p = new Type_type(arg1->type_p);
			subType_p->specifierList.pop_front();
			immediate_p->value = subType_p->getSize();
		}


		auto loc1 = locationMap_p->find(arg1)->second;

		ASMTranslator_type::transAdd(immediate_p, loc1);

		(*locationMap_p)[unaryExpr_p] = loc1;
	}

	else if (unaryExpr_p->expr_operator == unaryExpr_node::DEC_OP)
	{
		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto immediate_p = new Immediate_type();

		if (arg1->type_p->specifierList.size() == 0)
		{
			immediate_p->value = 1;
		}
		else
		{
			auto subType_p = new Type_type(arg1->type_p);
			subType_p->specifierList.pop_front();
			immediate_p->value = subType_p->getSize();
		}


		auto loc1 = locationMap_p->find(arg1)->second;

		ASMTranslator_type::transSub(immediate_p, loc1);

		(*locationMap_p)[unaryExpr_p] = loc1;
	}
	else if (unaryExpr_p->expr_operator == unaryExpr_node::REF_OP)
	{


		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto resReg_p = selectRegister();

		auto loc1 = locationMap_p->find(arg1)->second;

		ASMTranslator_type::transLea(loc1, resReg_p);
		
		(*locationMap_p)[unaryExpr_p] = resReg_p;
		resReg_p->expr_p = unaryExpr_p;

	}
	else if (unaryExpr_p->expr_operator == unaryExpr_node::IDR_OP)
	{

		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		//auto resReg_p = selectRegister();

		auto loc1 = locationMap_p->find(arg1)->second;

		Register_type *reg_p;

		if (loc1->locationType != Location_type::REGISTER)
		{
			reg_p = replaceRegister(arg1);
		}
		else
		{
			reg_p = static_cast<Register_type*>(loc1);
		}

		auto resLoc_p = new stackMemory_type();

		resLoc_p->base = reg_p;

		(*locationMap_p)[unaryExpr_p] = resLoc_p;
		reg_p->expr_p = unaryExpr_p;
	}

	else if (unaryExpr_p->expr_operator == unaryExpr_node::MINUS_OP)
	{
		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto loc1 = locationMap_p->find(arg1)->second;

		auto resReg_p = selectRegister();


		ASMTranslator_type::transMov(loc1, resReg_p);
		ASMTranslator_type::transNeg(resReg_p);

		(*locationMap_p)[unaryExpr_p] = resReg_p;
		resReg_p->expr_p = unaryExpr_p;
	}
	else if (unaryExpr_p->expr_operator == unaryExpr_node::CMPL_OP)
	{
		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto loc1 = locationMap_p->find(arg1)->second;

		auto resReg_p = selectRegister();

		auto immediate_p = new Immediate_type();
		immediate_p->value = 0;

		ASMTranslator_type::transMov(loc1, resReg_p);
		ASMTranslator_type::transCmp(immediate_p, resReg_p);
		ASMTranslator_type::transSete(resReg_p);

		(*locationMap_p)[unaryExpr_p] = resReg_p;
		resReg_p->expr_p = unaryExpr_p;
	}
	else if (unaryExpr_p->expr_operator == unaryExpr_node::PRINT_OP)
	{

		auto arg1 = static_cast<Expression_node*>(unaryExpr_p->child[0]);

		auto loc1 = locationMap_p->find(arg1)->second;

		auto rsi = &(Register_type::Reg_RSI);
		auto rdi = &(Register_type::Reg_RDI);

		ASMTranslator_type::transMov(loc1, rsi);
		oout << "\tmovq\t$string1, %rdi" << endl;
		oout << "\tcall\tprintf" << endl;

		(*locationMap_p)[unaryExpr_p] = loc1;
	}
	
}

void basicBlock_type::transMul(multiplicativeExpr_node *mulExpr_p)
{
	if (mulExpr_p->expr_operator == multiplicativeExpr_node::MUL_OP)
	{
		auto arg1 = static_cast<Expression_node*>(mulExpr_p->child[0]);
		auto arg2 = static_cast<Expression_node*>(mulExpr_p->child[1]);
		auto loc1 = locationMap_p->find(arg1)->second;
		auto loc2 = locationMap_p->find(arg2)->second;

		auto resReg_p = selectRegister();

		ASMTranslator_type::transMov(loc1, resReg_p);
		ASMTranslator_type::transMul(loc2, resReg_p);

		(*locationMap_p)[mulExpr_p] = resReg_p;
		resReg_p->expr_p = mulExpr_p;


	}
	else if (mulExpr_p->expr_operator == multiplicativeExpr_node::DIV_OP)
	{

	}
}

void basicBlock_type::transAdd(additiveExpr_node *addExpr_p)
{
	if (addExpr_p->expr_operator == additiveExpr_node::ADD_OP)
	{
		auto arg1 = static_cast<Expression_node*>(addExpr_p->child[0]);
		auto arg2 = static_cast<Expression_node*>(addExpr_p->child[1]);
		auto loc1 = locationMap_p->find(arg1)->second;
		auto loc2 = locationMap_p->find(arg2)->second;

		auto resReg_p = selectRegister();

		ASMTranslator_type::transMov(loc1, resReg_p);
		ASMTranslator_type::transAdd(loc2, resReg_p);
		(*locationMap_p)[addExpr_p] = resReg_p;
		resReg_p->expr_p = addExpr_p;


	}
	else if (addExpr_p->expr_operator == additiveExpr_node::SUB_OP)
	{
		auto arg1 = static_cast<Expression_node*>(addExpr_p->child[0]);
		auto arg2 = static_cast<Expression_node*>(addExpr_p->child[1]);
		auto loc1 = locationMap_p->find(arg1)->second;
		auto loc2 = locationMap_p->find(arg2)->second;


		auto resReg_p = selectRegister();



		ASMTranslator_type::transMov(loc1, resReg_p);
		ASMTranslator_type::transSub(loc2, resReg_p);
		(*locationMap_p)[addExpr_p] = resReg_p;
		resReg_p->expr_p = addExpr_p;

	}

}

void basicBlock_type::transAssign(assignExpr_node *assignExpr_p)
{

	auto arg1 = static_cast<Expression_node*>(assignExpr_p->child[0]);
	auto arg2 = static_cast<Expression_node*>(assignExpr_p->child[1]);
	auto loc1 = locationMap_p->find(arg1)->second;
	auto loc2 = locationMap_p->find(arg2)->second;


	cerr << loc1->getStr() << endl;
	auto reg_p = selectRegister();

	cerr << loc1->getStr() << endl;

	if (loc2->locationType == Location_type::MEMORY)
	{

		auto tmp1 = static_cast<Memory_type*>(loc2);
		if (tmp1->memoryType == Memory_type::STACK)
		{

			auto tmp2 = static_cast<stackMemory_type*>(tmp1);
			auto y = new stackMemory_type(tmp2);

			auto x = new stackMemory_type(static_cast<stackMemory_type*>(loc1));
			for (int i = 0; i < y->size; i += 8)
			{
				
				ASMTranslator_type::transMov(y, reg_p);
				ASMTranslator_type::transMov(reg_p, x);
				y->offset1 += 8;
				x->offset1 += 8;

			}
		}
	}
	else
	{

		ASMTranslator_type::transMov(loc2, loc1);
	}
	

	(*locationMap_p)[assignExpr_p] = loc1;
}

void basicBlock_type::transRelation(relationalExpr_node *relExpr_p)
{
	auto arg1 = static_cast<Expression_node*>(relExpr_p->child[0]);
	auto arg2 = static_cast<Expression_node*>(relExpr_p->child[1]);
	auto loc1 = locationMap_p->find(arg1)->second;
	auto loc2 = locationMap_p->find(arg2)->second;

	auto r15 = &(Register_type::Reg_R15);
	ASMTranslator_type::transXor(r15, r15);
	ASMTranslator_type::transMov(loc2, r15);
	ASMTranslator_type::transCmp(loc1, r15);

	if (relExpr_p->expr_operator == relationalExpr_node::L_OP)
	{
		ASMTranslator_type::transSetl(r15);
	}
	else if (relExpr_p->expr_operator == relationalExpr_node::LE_OP)
	{
		ASMTranslator_type::transSetle(r15);
	}
	else if (relExpr_p->expr_operator == relationalExpr_node::G_OP)
	{
		ASMTranslator_type::transSetg(r15);
	}
	else if (relExpr_p->expr_operator == relationalExpr_node::GE_OP)
	{
		ASMTranslator_type::transSetge(r15);
	}

	auto resReg_p = selectRegister();
	oout << "\tmovzbq\t%r15b, " << resReg_p->getStr() << endl;
	(*locationMap_p)[relExpr_p] = resReg_p;
	resReg_p->expr_p = relExpr_p;
}


void basicBlock_type::transEquality(equalityExpr_node *eqlExpr_p)
{
	auto arg1 = static_cast<Expression_node*>(eqlExpr_p->child[0]);
	auto arg2 = static_cast<Expression_node*>(eqlExpr_p->child[1]);
	auto loc1 = locationMap_p->find(arg1)->second;
	auto loc2 = locationMap_p->find(arg2)->second;
	
	auto r15 = &(Register_type::Reg_R15);
	ASMTranslator_type::transXor(r15, r15);
	ASMTranslator_type::transMov(loc2, r15);
	ASMTranslator_type::transCmp(loc1, r15);

	if (eqlExpr_p->expr_operator == equalityExpr_node::EQ_OP)
	{
		ASMTranslator_type::transSete(r15);
	}
	else if (eqlExpr_p->expr_operator == equalityExpr_node::NE_OP)
	{
		ASMTranslator_type::transSetne(r15);
	}
	auto resReg_p = selectRegister();
	oout << "\tmovzbq\t%r15b, " << resReg_p->getStr() << endl;
	(*locationMap_p)[eqlExpr_p] = resReg_p;
	resReg_p->expr_p = eqlExpr_p;
	
}





void basicBlock_type::transASM(Expression_node *e)
{


	
	if (e->get_nodeType() == PRIMARY_EXPR)
	{
		auto primaryExpr_p = static_cast<primaryExpr_node*>(e);
		transPrimary(primaryExpr_p);
	}

	else  if (e->get_nodeType() == POSTFIX_EXPR)
	{
		auto postfixExpr_p = static_cast<postfixExpr_node*>(e);
		transPostfix(postfixExpr_p);
	}

	else if (e->get_nodeType() == UNARY_EXPR)
	{
		auto unaryExpr_p = static_cast<unaryExpr_node*>(e);
		transUnary(unaryExpr_p);

	}
	else if (MULTIPLICATIVE_EXPR == e->get_nodeType())
	{

		auto mulExpr_p = static_cast<multiplicativeExpr_node*>(e);
		transMul(mulExpr_p);
	}

	else if (ADDITIVE_EXPR == e->get_nodeType())
	{
		auto addExpr_p = static_cast<additiveExpr_node*>(e);
		transAdd(addExpr_p);

	}

	else if (ASSIGN_EXPR == e->get_nodeType())
	{
		auto assignExpr_p = static_cast<assignExpr_node*>(e);
		transAssign(assignExpr_p);
	}

	else if (EQUALITY_EXPR == e->get_nodeType())
	{
		auto eqlExpr_p = static_cast<equalityExpr_node*>(e);
		transEquality(eqlExpr_p);
	}
	else if (RELATIONAL_EXPR == e->get_nodeType())
	{
		auto relExpr_p = static_cast<relationalExpr_node*>(e);
		transRelation(relExpr_p);
	}

	cerr << e->id << endl;
	
	for (auto c : e->child)
	{
		static_cast<Expression_node*>(c)->usage--;
	}
}

varSymbol_type * basicBlock_type::getVarSymbol(Expression_node *e)
{
	if (e == nullptr)
	{
		return nullptr;
	}
	if (e->get_nodeType() == PRIMARY_EXPR)
	{
		auto primaryExpr_p = static_cast<primaryExpr_node*>(e);
		if (primaryExpr_p->valueType == primaryExpr_node::ID)
		{
			auto varSymbol_p = Scope_type::find_varSymbol(primaryExpr_p->primaryValue);

			return varSymbol_p;
		}
	}

	return nullptr;
}

void basicBlock_type::entryRoutine()
{
	for (auto reg_p : registerList)
	{
		reg_p->expr_p = nullptr;
	}
	oout << "BB" << id << ":" << endl;
}

void basicBlock_type::exitRoutine()
{

	for (auto reg_p : registerList)
	{

		auto varSymbol_p = getVarSymbol(reg_p->expr_p);
		if (varSymbol_p != nullptr)
		{
			
			flushRegister(reg_p);
			
		}
	}
	if (exit.condEgress_p != nullptr)
	{
		auto immediate_p = new Immediate_type();
		auto loc = locationMap_p->find(exit.condExpr_p)->second;
		immediate_p->value = 1;
		ASMTranslator_type::transCmp(immediate_p, loc);
		ASMTranslator_type::transJe(exit.condEgress_p->id);
	}

	if (exit.defaultEgress_p != nullptr)
	{
		

		if (exit.defaultEgress_p->exit.defaultEgress_p == nullptr)
		{
			// indicate that it's RETURN statement

			auto loc = locationMap_p->find(quadList.back())->second;

			ASMTranslator_type::transMov(loc, &(Register_type::Reg_RAX));
		}
		ASMTranslator_type::transJmp(exit.defaultEgress_p->id);
	}
	else
	{
		// end of function

		oout << "\tleave\t" << endl;
		oout << "\tret\t" << endl;


	}

}	

void basicBlock_type::flushRegister(Register_type * reg_p)
{
	if (reg_p->expr_p == nullptr)
	{
		return;
	}

	auto varSymbol_p = getVarSymbol(reg_p->expr_p);

	if (varSymbol_p == nullptr)
	{
		auto stackMemory_p = new stackMemory_type();

		offset -= 8;
		stackMemory_p->offset1 = offset;
		stackMemory_p->base = &(Register_type::Reg_RBP);
		ASMTranslator_type::transMov(reg_p, stackMemory_p);
		(*locationMap_p)[reg_p->expr_p] = stackMemory_p;
		
	}
	else
	{
		varSymbol_p->register_p = nullptr;
		ASMTranslator_type::transMov(reg_p, varSymbol_p->memory_p);
		(*locationMap_p)[reg_p->expr_p] = varSymbol_p->register_p;
	}

	reg_p->expr_p = nullptr;
	




}

Register_type * basicBlock_type::selectRegister()
{
	for (auto reg_p : registerList)
	{
		if (reg_p->expr_p == nullptr)
		{
			return reg_p;
		}
	}
	
	for (auto reg_p : registerList)
	{
		if (reg_p->expr_p->usage == 0)
		{
			return reg_p;
		}
	}


		
	flushRegister(registerList.front());
	return registerList.front();
}

Register_type* basicBlock_type::replaceRegister(Expression_node *expr_p)
{
	
	auto reg_p = selectRegister();
	auto varSymbol_p = getVarSymbol(expr_p);
	auto loc_p = locationMap_p->find(expr_p)->second;
	ASMTranslator_type::transMov(loc_p, reg_p);
	(*locationMap_p)[expr_p] = reg_p;

	if (varSymbol_p != nullptr)
	{
		varSymbol_p->register_p = reg_p;
	}

	reg_p->expr_p = expr_p;

	return reg_p;

}


void basicBlock_type::startTrans()
{

	entryRoutine();


	for (auto quad_p: quadList)
	{
		transASM(quad_p);
	}

	exitRoutine();
}

