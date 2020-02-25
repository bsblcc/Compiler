

#ifndef SYMBOL_H
#define SYMBOL_H

#include <list>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>



#include "location.h"

#include "type.h"

using namespace std;




extern ofstream fout;






class Symbol_type
{
public:
	string name;
	enum
	{
		FUNC, VAR, STRUCT,
	} symbolType;
	
	virtual void print(string) = 0;
	bool initialized = false;

};




class varSymbol_type : public Symbol_type
{
public:
	varSymbol_type();
	Type_type *type_p;

	// where this variable is located in memory.
	Memory_type *memory_p;

	// which register holds the copy of this variable, null if none.
	Register_type *register_p;

	void print(string);
};

class funcSymbol_type: public Symbol_type
{
public:
	funcSymbol_type();
	list<varSymbol_type*> argList;
	void print(string);
	Type_type *type_p;
	//bool sameFigWith(const funcSymbol_type&) const;
};




class structSymbol_type: public Symbol_type
{
public:
	structSymbol_type();
	//list<structField_type*> fieldList;

	structType_type *structType_p;
	void print(string);
};


















/*
class Expression_type
{
public:
	builtInType_type builtInType;
	typeSpecifierList_type typeSpecifierList;
	enum
	{
		YES, NO, NUL,
	} assignable = NUL;
};*/
/*
Expression* get_postfixExpr(postfixExpr_node* t);
Expression* get_primaryExpr(primaryExpr_node* t);*/
#endif