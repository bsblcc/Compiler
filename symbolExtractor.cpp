

#include "symbolExtractor.h"


list<varSymbol_type*>* symbolExtractor_type::getVarSymbolList(AST_node* t)
{
	if (TYPE_SPEC != t->child[0]->get_nodeType())
	{
		cerr << "AST constructure crash:" << endl << "the first child of varDecl must be a typeSpec" << endl ;
		return nullptr;
	}

	auto resList = new list<varSymbol_type*>();


	auto typeSpec = static_cast<typeSpec_node*>(t->child[0]);
	auto baseType_p = getType(typeSpec);
	if (nullptr == baseType_p)
	{
		cerr << "Invalid type specifier!" << endl;
		return nullptr;
	}

	for (auto c : t->child[1]->child)
	{
		auto ivd = static_cast<initVarDeclarator_node*>(c);
		if (ivd->child.size() != 1 && ivd->child.size() != 2)
		{
			cerr << "initial variable declarator has no children!" << endl;
			return nullptr;
		}

		auto varSymbol_p = new varSymbol_type();
		auto varDeclarator = static_cast<varDeclarator_node*>(ivd->child[0]);
		varSymbol_p->name = varDeclarator->varName;
		
		varSymbol_p->type_p = new Type_type();
		varSymbol_p->type_p->specifierList = varDeclarator->typeSpecifierList;

		

		varSymbol_p->type_p->baseType_p = baseType_p;
		

		if (ivd->child.size() == 2)
		{
			//todo : about initialized
			varSymbol_p->initialized = true;
		}
		//varSymbol_p->declare(scope);
		//Scope_type::declare(varSymbol_p);
		//return varSymbol_p;
		resList->push_back(varSymbol_p);
	}

	return resList;
}
// it just declare the symbols about the function, like parmas or whatelse.

varSymbol_type* symbolExtractor_type::getArgSymbol(AST_node* t)
{
	auto typeSpec = static_cast<typeSpec_node*>(t->child[0]);
	auto baseType_p = getType(typeSpec);
	if (nullptr == baseType_p)
	{
		return nullptr;
	}
	auto argSymbol_p = new varSymbol_type();
	auto initVarDeclarator = static_cast<initVarDeclarator_node*>(t->child[1]);
	auto varDeclarator = static_cast<varDeclarator_node*>(initVarDeclarator->child[0]);
	argSymbol_p->name = varDeclarator->varName;
	argSymbol_p->type_p = new Type_type();
	argSymbol_p->type_p->specifierList = varDeclarator->typeSpecifierList;

	argSymbol_p->type_p->baseType_p = baseType_p;


	if (2 == initVarDeclarator->child.size())
	{
		// todo: initialized parameter
		argSymbol_p->initialized = true;
	}
	return argSymbol_p;
}


structSymbol_type* symbolExtractor_type::getStructSymbol(AST_node* t)
{

	auto sd = static_cast<structDecl_node*>(t);
	auto structSymbol_p = new structSymbol_type();
	structSymbol_p->name = sd->name;
	structSymbol_p->structType_p = new structType_type(); 
	structSymbol_p->structType_p->name = sd->name;
	return structSymbol_p;

}


void symbolExtractor_type::addStructField(structSymbol_type* structSymbol_p, AST_node* t)
{
	for (auto vd: t->child[0]->child)
	{
		if (VAR_DECL != vd->get_nodeType())
		{
			cerr << "AST constructure crash:" << endl << "the child of structVarDeclList must be a varDecl" << endl ;
			
			return;
		}
		if (TYPE_SPEC != vd->child[0]->get_nodeType())
		{
			cerr << "AST constructure crash:" << endl << "the first child of varDecl must be a typeSpec" << endl ;
			return;
		}

		auto typeSpec = static_cast<typeSpec_node*>(vd->child[0]);

		auto baseType_p = getType(typeSpec);
		if (nullptr == baseType_p)
		{
			cerr << "Invalid type specifier!" << endl;
			return;
		}

		for (auto c : vd->child[1]->child)
		{
			auto ivd = static_cast<initVarDeclarator_node*>(c);
			if (ivd->child.size() != 1 && ivd->child.size() != 2)
			{
				cerr << "initial variable declarator has no children!" << endl;
				return;
			}
			auto structField_p = new structField_type();
			auto varDeclarator = static_cast<varDeclarator_node*>(ivd->child[0]);
			
			/*
			auto memberAccessEdge_p = new memberAccessEdge_type();
			memberAccessEdge_p->memberName = varDeclarator->varName;

			*/
			structField_p->type_p = new Type_type();
			structField_p->name = varDeclarator->varName;
			structField_p->type_p->baseType_p = baseType_p;
			structField_p->type_p->specifierList = varDeclarator->typeSpecifierList;
			/*

			auto cur = baseType_p;
			auto rit = varDeclarator->typeSpecifierList.rbegin();
			for (; rit != varDeclarator->typeSpecifierList.rend(); rit++)
			{
				switch (*rit)
				{
					case (ARRAY):
						cur = cur->onEdge(Type_type::arrayEdge_const_p);
						break;
					case (POINTER):
						cur = cur->onEdge(Type_type::pointerEdge_const_p);
						break;
				}
			}
			*/
			//structSymbol_p->type_p = cur->onEdge(memberAccessEdge_p);
			//structSymbol_p->type_p->addEdge(memberAccessEdge_p, cur);
			if (ivd->child.size() == 2)
			{
				//todo : about initialized
				structField_p->initialized = true;
			}
			structSymbol_p->structType_p->fieldList.push_back(structField_p);

		}

	}
}



funcSymbol_type* symbolExtractor_type::getFuncSymbol(AST_node* t)
{
	if (TYPE_SPEC != t->child[0]->get_nodeType())
	{
		cerr << "AST constructure crash:" << endl << "the first child of funcDef must be a typeSpec" << endl ;
		return nullptr;
	}
	auto funcSymbol_p = new funcSymbol_type();
	auto typeSpec = static_cast<typeSpec_node*>(t->child[0]);
	auto baseType_p = getType(typeSpec);
	if (nullptr == baseType_p)
	{
		cerr << "Invalid type specifier!" << endl;
		return nullptr;
	}
	auto funcDefDeclarator = static_cast<funcDefDeclarator_node*>(t->child[1]);
	
	funcSymbol_p->name = funcDefDeclarator->funcName;

	funcSymbol_p->type_p = new Type_type();

	funcSymbol_p->type_p->baseType_p = baseType_p;
	funcSymbol_p->type_p->specifierList = funcDefDeclarator->typeSpecifierList;
	/*
	auto cur = baseType_p;
	auto rit = funcDefDeclarator->typeSpecifierList.rbegin()
	for (; rit != funcDefDeclarator->typeSpecifierList.rend(); rit++)
	{
		switch (*rit)
		{
			case (ARRAY):
				cur = cur->onEdge(Type_type::arrayEdge_const_p);
				break;
			case (POINTER):
				cur = cur->onEdge(Type_type::pointerEdge_const_p);
				break;
		}
	}
	*/
	funcSymbol_p->initialized = true;
	//funcSymbol_p->paramList = new list<Symbol_type*> ();

	//list<Type_type*> paramTypeList;


	if (0 != funcDefDeclarator->child.size())
	{
		// has params
		auto paramDeclList = static_cast<paramDeclList_node*>(funcDefDeclarator->child[0]);
		for (auto child : paramDeclList->child)
		{
			auto paramSymbol_p = getArgSymbol(child);
			if (nullptr == paramSymbol_p)
			{
				cerr << "invalid parameters" << endl;
			}
			//paramTypeList.push_back(paramSymbol_p->type_p);
			funcSymbol_p->argList.push_back(paramSymbol_p);
		}
	}

	/*
	auto funcCallEdge_p = new funcCallEdge_type();
	funcCallEdge_p->paramTypeList = paramTypeList;

	
	funcSymbol_p->type_p = new Type_type();
	funcSymbol_p->type_p->addEdge(funcCallEdge_p, cur);
	*/


	return funcSymbol_p;
}



baseType_type* symbolExtractor_type::getType(typeSpec_node* t)
{
	switch (t->type)
	{
		case typeSpec_node::BUILTIN:
			
			switch (t->builtInType)
			{
				case typeSpec_node::INT_TYPE:
					return intType_type::intType_const_p;
				case typeSpec_node::VOID_TYPE:
					return voidType_type::voidType_const_p;
				case typeSpec_node::CHAR_TYPE:
					return charType_type::charType_const_p;
				case typeSpec_node::FLOAT_TYPE:
					return floatType_type::floatType_const_p;
			}
			break;


		case typeSpec_node::STRUCT:
			auto structSymbol_p = Scope_type::find_structSymbol(*(t->name));
			if (nullptr != structSymbol_p)
			{
				return structSymbol_p->structType_p;
			}
			
	}
	return nullptr;
}


