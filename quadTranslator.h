


// simply record type of each AST expr node
// and do the type check.



#ifndef QUAD_TRANSLATOR_H
#define QUAD_TRANSLATOR_H



#include "AST.h"



#include "symbol.h"
#include "scope.h"

#include <list>

using namespace std;


class quadTranslator
{
public:

	static void transExpr(Expression_node*, std::list<Expression_node*>* );

	static Type_type* getReturnType(funcSymbol_type*, argumentExprList_node*);


	static void transChild(Expression_node* t, std::list<Expression_node*>*);
	
	static void getPrimaryType(primaryExpr_node* primaryExpr_p);
	static void getSubscriptType(postfixExpr_node* t);
	static void getMemberType(postfixExpr_node* t);
	static void getRefMemberType(postfixExpr_node* t);
	static void getRightIncDecType(postfixExpr_node *t);
	static void getLeftIncDecType(unaryExpr_node *t);
	static void getRefType(unaryExpr_node *t);
	static void getDerefType(unaryExpr_node *t);
	static void getPlusMinusType(unaryExpr_node *t);
	static void getNegType(unaryExpr_node *t);
	static void getCmplType(unaryExpr_node *t);
	static void getMulDivType(multiplicativeExpr_node *t);
	static void getAddSubType(additiveExpr_node *t);
	static void getShiftType(shiftExpr_node *t);
	static void getBitwiseType(Expression_node *t);
	static void getAssignType(assignExpr_node *t);
	static void getPrintType(unaryExpr_node*);

};









#endif
