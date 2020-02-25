#ifndef FRONT_END_H
#define FRONT_END_H


#include "AST.h"
#include "functionManager.h"
#include "symbolExtractor.h"


class frontEnd
{
public:
	AST_node* root;
	frontEnd(AST_node*);
	void AST_walk(AST_node*);
	void start();
};






















#endif