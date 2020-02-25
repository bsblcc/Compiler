#include <list>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#ifndef SEM_H
#define SEM_H
using namespace std;

enum typeSpecifier_type
{
	ARRAY, POINTER,
};

enum builtInType_type
{
	STUB, INT, VOID, CHAR, FLOAT,

};
const string typeSpecifier_dic[] =
{
	"array",
	"pointer",
};

const string builtInType_dic[] = 
{
	"stub",
	"int",
	"void",
	"char",
	"float",
};


class Symbol_type;

typedef list<typeSpecifier_type> typeSpecifierList_type;
typedef list<Symbol_type*> paramSymbolList_type;




//typedef __gnu_cxx::hash_map<string, funcSymbol_type*> funcStab_type;
//typedef __gnu_cxx::hash_map<string, varSymbol_type*> varStab_type;


typedef list<Symbol_type*> stab_entry;

typedef map<string, stab_entry*> stab_type;


typedef vector<stab_type*> scope_type;

void enter_scope();
void leave_scope();








class Symbol_type
{
public:
	builtInType_type builtInType;
	typeSpecifierList_type typeSpecifierList;
	string name;
	enum
	{
		FUNC, VAR,
	} type;
	paramSymbolList_type paramSymbolList;
	bool initialized;
	void declare(const scope_type& scope);
};

void Symbol_type::declare(const scope_type& scope)
{
	if 
}




class varSymbol_type : public Symbol_type
{
public:

	string getKey();
	bool initialized = false;
	void declare(const scope_type& scope);
	void print(string);
};


class funcSymbol_type : public Symbol_type
{
public:
	bool defined = false;
	paramSymbolList_type paramSymbolList;
	string getKey();
	
	void declare(const scope_type&);
	
	void print(string);
};

void enter_scope();
void leave_scope();
void show_stab();

class Expression_type
{
public:
	builtInType_type builtInType;
	typeSpecifierList_type typeSpecifierList;
	enum
	{
		YES, NO, NUL,
	} assignable = NUL;
};
/*
Expression* get_postfixExpr(postfixExpr_node* t);
Expression* get_primaryExpr(primaryExpr_node* t);*/
#endif