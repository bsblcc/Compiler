#include "ASMTranslator.h"

#include <fstream>

ofstream oout("obj.s");



void ASMTranslator_type::transMov(Location_type *x, Location_type *y)
{
	// Basic assumption: without awareness and considering of the upper level, $dummy$
	// e.g. there are some instructions that are impossible in ASM-level,

	// @ memory->memory 
	// @ any->immediate 

	oout << "\tmovq\t" << x->getStr() << ", " << y->getStr() << endl;
}





void ASMTranslator_type::transAdd(Location_type *x, Location_type *y)
{

	oout << "\taddq\t" << x->getStr() << ", " << y->getStr() << endl;
}


void ASMTranslator_type::transSub(Location_type *x, Location_type *y)
{

	oout << "\tsubq\t" << x->getStr() << ", " << y->getStr() << endl;
}

void ASMTranslator_type::transLea(Location_type *x, Location_type *y)
{
	oout << "\tleaq\t" << x->getStr() << ", " << y->getStr() << endl;
}

void ASMTranslator_type::transNeg(Location_type *x)
{
	oout << "\tnegq\t" << x->getStr() << endl;
}

void ASMTranslator_type::transCmp(Location_type *x, Location_type *y)
{
	oout << "\tcmpq\t" << x->getStr() << ", " << y->getStr() << endl;
}

void ASMTranslator_type::transSete(Location_type *x)
{
	oout << "\tsete\t" <<"%r15b" << endl;
}
void ASMTranslator_type::transSetne(Location_type *x)
{
	oout << "\tsetne\t" << "%r15b" << endl;
}
void ASMTranslator_type::transSetl(Location_type *x)
{
	oout << "\tsetl\t" << "%r15b" << endl;
}
void ASMTranslator_type::transSetg(Location_type *x)
{
	oout << "\tsetg\t" << "%r15b" << endl;
}
void ASMTranslator_type::transSetle(Location_type *x)
{
	oout << "\tsetle\t" << "%r15b" << endl;
}

void ASMTranslator_type::transSetge(Location_type *x)
{
	oout << "\tsetge\t" << "%r15b" << endl;
}

void ASMTranslator_type::transMul(Location_type *x, Location_type *y)
{
	oout << "\timul\t" << x->getStr() << ", " << y->getStr() << endl;
}

void ASMTranslator_type::transDiv(Location_type *x, Location_type *y)
{
}

void ASMTranslator_type::transJe(int id)
{
	oout << "\tje\t" << "BB" << id << endl;
}

void ASMTranslator_type::transJmp(int id)
{
	oout << "\tjmp\t" << "BB" << id << endl;
}


void ASMTranslator_type::transXor(Location_type *x, Location_type *y)
{
	oout << "\txor\t" << x->getStr() << ", " << y->getStr() << endl;
}
