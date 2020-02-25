#ifndef CFG_H
#define CFG_H

/***************
The edges are inside the class of basicBlock



*****************/





#include "basicBlock.h"

class CFG_type
{
public:
	CFG_type();
	list<basicBlock_type*> CFG;
	basicBlock_type *CFGEntry_p, *CFGExit_p;
	basicBlock_type* startBasicBlock();
	void contract();
	void deleteUnreachable();
	void print();
	void dfs(basicBlock_type*);

	void optimize();

	int offset;
	void transASM();
	
};




#endif