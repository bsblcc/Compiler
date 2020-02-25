#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

/*
scopes are arranged as a stack
enter/exit when compound statements occur
each scope points to a symbol table
*/
using namespace std;



enum specifier_type
{
	ARRAY, POINTER,
};

enum symbolType_type
{
	FUNC, DATA,
};
enum baseType_type
{
	STUB, INT, VOID, CHAR, FLOAT,
};



class Type
{
public:
	list <specifier_type> specifier;
	baseType_type baseType;


	void print(FILE* dout)
	{
		list <specifier_type>:: iterator it;
		for (it = specifier.begin(); it != specifier.end(); it++)
		{
			if (*it == POINTER)
			{
				fprintf(dout, "pointer to\n");
			}
			else if (*it == ARRAY)
			{
				fprintf(dout, "array of\n");
			}
		}

		switch (baseType)
		{
			case INT:
			{
				fprintf(dout, "int\n");
				break;
			}
			case VOID:
			{
				fprintf(dout, "void\n");
				break;
			}
			case CHAR:
			{
				fprintf(dout, "char\n");
				break;
			}
			case FLOAT:
			{
				fprintf(dout, "float\n");
				break;
			}

		}
	}

	bool operator == (const Type& y)
	{
		if (baseType != y.baseType)
		{
			return false;
		}

		if (specifier.size() != y.specifier.size())
		{
			return false;
		}

		auto it1 = specifier.begin();
		auto it2 = y.specifier.begin();
		for ( ; it1 != specifier.end() && it2 != y.specifier.end();
			 it1++, it2++)
		{
			if (*it1 != *it2)
			{
				return false;
			}
		}

		return true;
	}
};


class dataSymbol_type
{
public:
	string name;
	Type type;
	void print(FILE* dout)
	{
		fprintf(dout, "\nname: %s\n", name.c_str());
		fprintf(dout, "data type:\n");
		type.print(dout);

		fprintf(dout, "\n" );

	}
};

typedef list <dataSymbol_type> dataSymbolList_type;

class funcSymbol_type
{
public:
	string name;


	Type returnType;


	dataSymbolList_type paramList;
	void print(FILE* dout)
	{
		fprintf(dout, "\nname: %s\n", name.c_str());
		fprintf(dout, "return type:\n");
		returnType.print(dout);

		fprintf(dout, "parameters:\n");

		dataSymbolList_type:: iterator it;
		for (it = paramList.begin(); it != paramList.end(); it++)
		{
			it->print(dout);
		}
		fprintf(dout, "\n" );

	}

	bool sameSig(const funcSymbol_type& y)
	{
		if (paramList.size() != y.paramList.size())
		{
			return false;
		}
		auto it1 = paramList.begin();
		auto it2 = y.paramList.begin();
		for (; it1 != paramList.end() && it2 != y.paramList.end();
			 it1++, it2++)
		{
			if (!(it1->type == it2->type))
			{
				return false;
			}
		}

		return true;
	}

};

typedef list <funcSymbol_type*> funcSymbolList_type;




typedef funcSymbol_type funcSymbol_type;
typedef dataSymbol_type dataSymbol_type;
typedef map<string, dataSymbol_type*> dstab_type;
typedef map<string, funcSymbolList_type*> fstab_type;

struct stab_type
{
	dstab_type dstab;
	fstab_type fstab;
};
typedef stab_type stab_type;


typedef vector<stab_type*> scope_type;

typedef list<specifier_type> specifierList_type;
