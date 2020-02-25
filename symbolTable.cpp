#include "symbolTable.h"



using namespace std;

//map<string, list<Symbol_type*> > symbolTable_type::symbolTable;

void symbolTable_type::print()
{
	for (auto it = symbolTable.begin(); it != symbolTable.end(); it++)
	{
		it->second->print("  ");

	}
}



void symbolTable_type::declare(Symbol_type* symbol_p)
{
	auto res = symbolTable.find(symbol_p->name);
	if (res == symbolTable.end())
	{
		symbolTable[symbol_p->name] = symbol_p;
	}
	else
	{
		cerr << "redeclaration" << endl;
	}
}



structSymbol_type* symbolTable_type::find_structSymbol(const string& name)
{
	auto res = symbolTable.find(name);
	if (res == symbolTable.end())
	{
		return nullptr;
	}
	if (res->second->symbolType != Symbol_type::STRUCT)
	{
		return nullptr;
	}

	return static_cast<structSymbol_type*>(res->second );
}

funcSymbol_type* symbolTable_type::find_funcSymbol(const string& name)
{
	auto res = symbolTable.find(name);
	if (res == symbolTable.end())
	{
		return nullptr;
	}
	if (res->second->symbolType != Symbol_type::FUNC)
	{
		return nullptr;
	}

	return static_cast<funcSymbol_type*>(res->second );
}
varSymbol_type* symbolTable_type::find_varSymbol(const string& name)
{

	auto res = symbolTable.find(name);
	if (res == symbolTable.end())
	{

		return nullptr;
	}
	if (res->second->symbolType != Symbol_type::VAR)
	{

		return nullptr;
	}
	
	return static_cast<varSymbol_type*>(res->second);
}