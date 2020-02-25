#ifndef SYMBOL_EXTRACTOR_H
#define SYMBOL_EXTRACTOR_H


/************

This class extracts the symbol out of the AST and declare them into the scope

**********/
#include "AST.h"
#include "symbol.h"
#include "scope.h"


class symbolExtractor_type
{
public:
	static baseType_type* getType(typeSpec_node* t);
	static list<varSymbol_type*>* getVarSymbolList(AST_node* t);
	static varSymbol_type* getArgSymbol(AST_node* t);
	static structSymbol_type* getStructSymbol(AST_node* t);

	static void addStructField(structSymbol_type*, AST_node*);

	static funcSymbol_type* getFuncSymbol(AST_node* t);
};













#endif