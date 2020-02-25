#include "symbol.h"


using namespace std;




ofstream fout("sout.out");

varSymbol_type::varSymbol_type()
{
	symbolType = Symbol_type::VAR;
	register_p = nullptr;
}




void varSymbol_type::print(string blank)
{
	fout << blank << "variable:" << endl;
	fout << blank << "name: " << name << endl;
	fout << blank << "type: " << *type_p << endl;
	fout << blank << (initialized? "initialized" : "uninitialized") << endl;
	fout << endl;
}


funcSymbol_type::funcSymbol_type()
{
	symbolType = FUNC;
}
/*
bool funcSymbol_type::sameFigWith(const funcSymbol_type& other) const
{
	if (name != other.name)
	{
		return false;
	}
	if (!(returnType == other.returnType))
	{
		return false;
	}
	return true;
}
*/

void funcSymbol_type::print(string  blank)
{
	fout << blank << "function" << endl;
	fout << blank << "name: " << name << endl;
	fout << blank << "type: " << *type_p << endl;
	fout << blank << (initialized? "initialized" : "uninitialized") << endl;
	
	fout << blank << "parameters:" << endl;
	for (auto param_p: argList)
	{
		param_p->print(blank + "    ");
	}
	fout << endl;
}



structSymbol_type::structSymbol_type()
{
	symbolType = Symbol_type::STRUCT;
}


void structSymbol_type::print(string blank)
{
	fout << blank << "struct" << endl;
	fout << blank << "name: " << name << endl;
	
	fout << blank << "struct type: " << *structType_p << endl;
	
	
}


/*
Expression* handle_expr(AST_node* t)
{
	switch (t->get_nodeType())
	{
		case PRIMARY_EXPR:
			return get_primaryExpr(static_cast<primaryExpr_node*>(t));

		case POSTFIX_EXPR:
			return get_postfixExpr(static_cast<postfixExpr_node*>(t));
	}
}
Expression* get_primaryExpr(primaryExpr_node* t)
{
	auto primaryExpr = new Expression();
	switch (t->valueType)
	{
		case ID:
			primaryExpr->assignable = YES;
			auto varSymbol = findVarSymbol(t->primaryValue);
			primaryExpr->builtInType = varSymbol->builtInType;
			primaryExpr->typeSpecifierList = varSymbol->typeSpecifierList;
			break;
		case INT:
			primaryExpr->assignable = NO;
			primaryExpr->builtInType = INT;
			break;
		case FLOAT:
			primaryExpr->assignable = NO;
			primaryExpr->builtInType = FLOAT;
			break;

		case STRING:
			primaryExpr->assignable = NO;
			primaryExpr->builtInType = CHAR;
			primaryExpr->typeSpecifierList.push_back(POINTER);
			break;

		case CHAR:
			primaryExpr->assignable = NO;
			primaryExpr->builtInType = CHAR;
			break;
	}
	return primaryExpr;
}

Expression* get_postfixExpr(postfixExpr_node* t)
{
	switch (t->expr_operator)
	{
		case NONE:

			return handle_expr(t->child[0]);
			break;

		case FUNC_CALL_OP:
			string key;
			key = 
			break;


	}
}*/