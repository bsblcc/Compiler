#include "functionManager.h"




//using namespace std;

extern ofstream gout;
extern ofstream oout;
std::list<Function_type*> functionManager_type::functionList;
int functionManager_type::inside = 0;


void functionManager_type::startFunction(AST_node* t)
{
	auto tmp = new Function_type() ;
	
	tmp->enter(t);
	functionList.push_back(tmp);
	inside = 1;
}

void functionManager_type::endFunction()
{
	Scope_type::leave();
	inside = -1;
}

void functionManager_type::print()
{
	for (auto func_p: functionList)
	{
		func_p->print();
	}
}


void functionManager_type::transASM()
{




	
	
	for (auto func_p: functionList)
	{
		func_p->transASM();
	}

}