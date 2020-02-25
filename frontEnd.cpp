#include "frontEnd.h"

using namespace std;

extern ofstream oout;

frontEnd::frontEnd(AST_node* root)
{
	this->root = root;
}

void frontEnd::AST_walk(AST_node* t)
{
	structSymbol_type* structSymbol_p;
	switch (t->get_nodeType())
	{
		case VAR_DECL:

			for (auto varSymbol_p: *(symbolExtractor_type::getVarSymbolList(t)))
			{
				Scope_type::declare(varSymbol_p);
				// here captures the global vars, so mark it in static memory area.
				auto staticMemory_p = new staticMemory_type();
				staticMemory_p->name = varSymbol_p->name;
				staticMemory_p->size = varSymbol_p->type_p->getSize();

				varSymbol_p->memory_p = staticMemory_p;
			}
			

			break;		

		case FUNC_DEF:
			
			functionManager_type::startFunction(t);

			//AST_walk(t->child[2]);

			
			functionManager_type::functionList.back()->print();
			functionManager_type::functionList.back()->transASM();
			
			
			functionManager_type::endFunction();
			break;

		case STRUCT_DECL:
			structSymbol_p = symbolExtractor_type::getStructSymbol(t);
			if (nullptr != structSymbol_p)
			{
				Scope_type::declare(structSymbol_p);
				symbolExtractor_type::addStructField(structSymbol_p, t);

				structSymbol_p->structType_p->getSize();
			}
			
			break;
		case SHOW_STAB:
			Scope_type::print();
			break;
			
		default:
			for (auto child : t->child)
			{
				AST_walk(child);
			}
			
	}
}





void frontEnd::start()
{


	print(root);
	Scope_type::enter();

	oout << ".section\t.rodata" << endl;


	oout << "string1:" << endl;
	oout << "\t.string \"%ld\"" << endl;
	oout << ".global\tmain" << endl;

	AST_walk(root);
	
	/*
	functionManager_type::print();
	functionManager_type::transASM();*/
	
	Scope_type::leave();

}













