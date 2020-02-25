#ifndef BASIC_BLOCK_H
#define BASIC_BLOCK_H

/*******************

Each basic block has only one entry/exit point,
and maybe mutiple destination/source at that point.

For exit point, there are at most 2 destinations, one conditional and one default.
At the exit point, check if the condition is matched, if so go to the cond exit,
otherwise go to the default one

if none of these two are explict, then go to the next on list, since the list is arranged in topo order.
********************/


using namespace std;




#include "AST.h"
#include <list>
#include "scope.h"
#include <map>
#include <vector>
#include "ASMTranslator.h"

class basicBlock_type;


class Exit_type
{
public:
	/*
	enum
	{
		UNC, COND,
	} exitType;
	*/
	basicBlock_type *defaultEgress_p;
	basicBlock_type *condEgress_p;
	Expression_node *condExpr_p;
};
/*
class uncExit_type: public Exit_type
{
public:
	uncEdge_type();
};

class condExit_type: public Exit_type
{
public:
	condEdge_type();
	basicBlock_type *condDst_p;
	Expression_node *condExpr_p;
};
*/

/*
class registerListEntry_type
{
public:
	Register_type *register_p;
	Expression_node *expression_p;
	registerListEntry_type(Register_type*);
};
*/

class basicBlock_type
{
public:

	list<Expression_node*> quadList;

	Exit_type exit;

	basicBlock_type();

	int id;

	static int count;

	bool reachable;

	void print();

	map<varSymbol_type*, Expression_node*>* varSSATable_p;

	map<Expression_node*, Location_type*>* locationMap_p;

	//map<Register_type*, Expression_node*>* registerMap_p;
	
	void getVarList();


	void startTrans();
	

	Location_type* getLocation(Expression_node*);

	void transASM(Expression_node*);
	void transPrimary(primaryExpr_node *);
	void transPostfix(postfixExpr_node*);
	void transUnary(unaryExpr_node*);
	void transMul(multiplicativeExpr_node*);
	void transAdd(additiveExpr_node*);
	void transAssign(assignExpr_node*);
	void transRelation(relationalExpr_node *);
	void transEquality(equalityExpr_node *);



	list <Register_type*> registerList;

	void flushRegister(Register_type*);

	Register_type* selectRegister();

	Register_type* replaceRegister(Expression_node*);

	varSymbol_type* getVarSymbol(Expression_node*);


	void entryRoutine();
	void exitRoutine();
	int offset;

};








#endif