#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include "symbol.h"


using namespace std;

class symbolTable_type
{
public:
	map<string, Symbol_type* > symbolTable;
	void print();
	void declare(Symbol_type* symbol_p);
	structSymbol_type* find_structSymbol(const string&);
	funcSymbol_type* find_funcSymbol(const string&);
	varSymbol_type* find_varSymbol(const string&);
};





#endif