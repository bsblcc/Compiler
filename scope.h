#ifndef SCOPE_H
#define SCOPE_H

#include <vector>
#include "symbolTable.h"
#include "AST.h"
using namespace std;



class Scope_type
{
public:
	static vector<symbolTable_type*> scope;
	static void enter();
	static void leave();
	static void print();
	static void declare(Symbol_type* symbol_p);
	static structSymbol_type* find_structSymbol(const string&);

	static funcSymbol_type* find_funcSymbol(const string&);

	static varSymbol_type* find_varSymbol(const string&);

};











#endif