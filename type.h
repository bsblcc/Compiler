
#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;




/*************

A type is represented as a node in a graph.



*************/


/*
class Type_type;

class typeEdge_type
{
public:
	enum
	{
		FUNC_CALL,
		MEMBER_ACS,
		POINTER,
		ARRAY,
	} edgeType;

	friend ostream& operator << (ostream& out, typeEdge_type&);
};

ostream& operator << (ostream& out, typeEdge_type&);

class funcCallEdge_type: public typeEdge_type
{
public:
	funcCallEdge_type();
	list<Type_type*> paramTypeList;


};

class memberAccessEdge_type: public typeEdge_type
{
public:
	memberAccessEdge_type();
	string memberName;
};


class pointerEdge_type: public typeEdge_type
{
public:
	pointerEdge_type();
	static pointerEdge_type* pointerEdge_const_p;

};

class arrayEdge_type: public typeEdge_type
{
public:
	arrayEdge_type();
	static arrayEdge_type* arrayEdge_const_p;

};


class Type_type
{
public:
	list< pair<typeEdge_type*, Type_type*> > edgeList;

	static Type_type* intType_const_p;
	static Type_type* voidType_const_p;
	static Type_type* floatType_const_p;
	static Type_type* charType_const_p;

	Type_type* onEdge(typeEdge_type*);
	int size;
	int addEdge(typeEdge_type*, Type_type*);


	friend ostream& operator << (ostream& out, const Type_type&);
};


ostream& operator << (ostream& out, const Type_type&);

*/


class typeSpecifier_type
{
public:

	enum 
	{
		ARRAY, POINTER,
	} specifierType;
	int length;
	bool isPointer() const;
	bool isArray() const;
	string getStr() const;

	bool operator == (const typeSpecifier_type&) const;
};

class arraySpecifier_type: public typeSpecifier_type
{
public:
	
	arraySpecifier_type();

};
class pointerSpecifier_type: public typeSpecifier_type
{
public:
	pointerSpecifier_type();
};
class baseType_type;

class Type_type
{
public:
	Type_type(const Type_type&);
	Type_type(Type_type*);
	Type_type();
	
	static const string typeSpecifier_dic[];
	
	baseType_type* baseType_p;
	list<typeSpecifier_type> specifierList;

	bool operator == (const Type_type&) const;

	friend ostream& operator << (ostream& out, const Type_type&);
	int size = -1;
	int getSize();
	
};



ostream& operator << (ostream& out, const Type_type&);



class baseType_type
{
public:
	enum
	{
		BUILTIN, STRUCT,
	} baseTypeType;
	bool operator == (const baseType_type& other) const;
	string name;
	//baseType_type();

	virtual int getSize() = 0;
};

class structField_type
{
public:
	string name;
	Type_type *type_p;
	int offset;
	bool initialized = false;
};

class structType_type : public baseType_type
{	
public:
	structType_type();
	list<structField_type*> fieldList;
	static structType_type* structType_const_p;
	friend ostream& operator << (ostream& out, const structType_type&);
	virtual int getSize();
};

ostream& operator << (ostream& out, const structType_type&);
class builtInType_type : public baseType_type
{
public:
	enum
	{
		INT_TYPE, VOID_TYPE, CHAR_TYPE, FLOAT_TYPE,
	} builtInTypeType;
	builtInType_type();
	static const string builtInType_dic[];
	virtual int getSize();
};



class intType_type : public builtInType_type
{
public:
	static intType_type* intType_const_p;

	intType_type();

};

class voidType_type : public builtInType_type
{

public:
	static  voidType_type* voidType_const_p;
	voidType_type();
};

class charType_type : public builtInType_type
{
public:
	static  charType_type* charType_const_p;
	charType_type();
};

class floatType_type : public builtInType_type
{
public:
	static  floatType_type* floatType_const_p;
	floatType_type();
};










#endif