






#include "scope.h"

using namespace std;

vector<symbolTable_type*> Scope_type::scope;

void Scope_type::enter()
{
	scope.push_back(new symbolTable_type);
}
void Scope_type::leave()
{

	delete scope.back();
	scope.pop_back();
}
void Scope_type::print()
{
	fout << "symbols:" << endl;
	for (int i = scope.size() - 1; i >= 0; i--)
	{
		fout << "scope #" << i << ":" << endl;

		scope[i]->print();
		fout << endl;
	}
}

void Scope_type::declare(Symbol_type* symbol_p)
{
	if (0 == scope.size())
	{
		return;
	}
	scope.back()->declare(symbol_p);
}


structSymbol_type* Scope_type::find_structSymbol(const string& name)
{
	for (int i = scope.size() - 1; i >= 0; i--)
	{
		auto res = scope[i]->find_structSymbol(name);
		if (res != nullptr)
		{
			return res;
		}
	}
	return nullptr;
}
funcSymbol_type* Scope_type::find_funcSymbol(const string& name)
{
	for (int i = scope.size() - 1; i >= 0; i--)
	{
		auto res = scope[i]->find_funcSymbol(name);
		if (res != nullptr)
		{
			return res;
		}
	}
	return nullptr;
}
varSymbol_type* Scope_type::find_varSymbol(const string& name)
{
	cerr << "n: " << scope.size();
	for (int i = scope.size() - 1; i >= 0; i--)
	{
		auto res = scope[i]->find_varSymbol(name);
		cerr << "here: " << (res == nullptr) << endl;
		if (res != nullptr)
		{

			return res;
		}
	}
	return nullptr;
}

/*
symbolTable_type* Scope_type::top()
{
	return scope.back();
}*/