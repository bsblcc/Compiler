#ifndef FUNCTION_MAMANGER_H
#define FUNCTION_MAMANGER_H

/***************

a manager of functions helping the front end to orginas(z)e.

****************/


#include "function.h"


// like writing on a book, write TACs on the last function on default
// but watch out whether youre inside a function.
class functionManager_type
{
public:
	static std::list<Function_type*> functionList;
	static int inside;

	// when entering a function
	// firstly declare the symbols,
	// then allocate a new function block, 
	// walk on, and the upcoming TACs will be put into the new block.
	static void startFunction(AST_node*);
	static void endFunction();
	static void transASM();

	static void print();
};






#endif