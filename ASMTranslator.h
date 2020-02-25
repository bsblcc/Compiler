#ifndef ASM_TRANSLATOR_H
#define ASM_TRANSLATOR_H

#include <list>
#include "symbol.h"
#include "memory.h"
#include "location.h"
#include <map>

/**************************




**************************/









class ASMTranslator_type
{
public:

	ASMTranslator_type();




	static void transAdd(Location_type*, Location_type*);
	static void transMov(Location_type*, Location_type*);
	static void transSub(Location_type*, Location_type*);
	static void transLea(Location_type*, Location_type*);

	static void transNeg(Location_type*);

	static void transCmp(Location_type*, Location_type*);

	static void transSete(Location_type*);
	static void transSetl(Location_type*);
	static void transSetg(Location_type*);
	static void transSetle(Location_type*);
	static void transSetge(Location_type*);
	static void transSetne(Location_type*);

	static void transMul(Location_type*, Location_type*);
	static void transDiv(Location_type*, Location_type*);

	
	static void transJe(int id);
	static void transJmp(int id);
	static void transXor(Location_type *, Location_type *);
	Location_type* transAnd(Location_type*, Location_type*);
	Location_type* transOr(Location_type*, Location_type*);
	Location_type* transNot(Location_type*, Location_type*);
	Location_type* transSal(Location_type*, Location_type*);
	Location_type* transSar(Location_type*, Location_type*);


};




#endif