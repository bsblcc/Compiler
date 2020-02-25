#ifndef FUNCTION_H
#define FUNCTION_H

/**********
Currently what we need about a function is
its basic blocks(CFG) and the symbols(type, params, etc.)

sorry I won't diss GCC no more, I mean it for real.
maybe..
forget it,  GCC sucks

**********/
#include "symbol.h"
#include "CFG.h"
#include "AST.h"
#include "scope.h"
#include "symbolExtractor.h"
#include "quadTranslator.h"
class Function_type
{
public:

	Function_type();
	//functionBlock_type *functionBlock_p;
	funcSymbol_type *funcSymbol_p;

	CFG_type *CFG_p;

	basicBlock_type *cur_p;
	// this function is used at the entrance of a func definition
	// do the symbol declaration
	void enter(AST_node*);

	// walk on inside the function
	void walk(AST_node*);

	void leave();

	//void addTAC(TAC_type*);

	//list<Quad_type*>* exprTrans(Expression_node*);
	int totalParamSize;
	int totalArgSize;
	void entryRoutine();
	void transASM();
	void print();
};



#endif