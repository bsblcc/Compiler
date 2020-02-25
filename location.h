#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <sstream>
#include "AST.h"
using namespace std;

/***************************
3 types of locations where a variable may be located

@ stack memory
@ static memory(data segment)
@ register

***************************/




class Location_type
{
public:
	virtual void setLocationType() = 0;

	enum
	{
		MEMORY, REGISTER, IMMEDIATE,
	} locationType;

	virtual string getStr() = 0;
	
};

class Immediate_type: public Location_type
{
public:
	virtual void setLocationType();
	virtual string getStr();
	int value;
	Immediate_type();


};

class Memory_type: public Location_type
{
public:
	virtual void setMemoryType() = 0;
	virtual void setLocationType();
	enum
	{
		STACK, STATIC,
	} memoryType;
	int size;
};







class staticMemory_type: public Memory_type
{
public:
	staticMemory_type();
	virtual void setMemoryType();
	string name;

	virtual string getStr();

	
};
class Register_type: public Location_type
{
public:
	string name;
	virtual void setLocationType();
	int size;
	Register_type();
	Register_type(const string&);
	virtual string getStr();

	Expression_node* expr_p;

	static Register_type Reg_RAX;
	static Register_type Reg_RBX;
	static Register_type Reg_RCX;
	static Register_type Reg_RSI;
	static Register_type Reg_RDI;
	static Register_type Reg_R8;
	static Register_type Reg_R9;
	static Register_type Reg_R10;
	static Register_type Reg_R11;
	static Register_type Reg_R12;
	static Register_type Reg_R13;
	static Register_type Reg_R14;
	static Register_type Reg_R15;

	static Register_type Reg_RBP;
	static Register_type Reg_RSP;

};
class stackMemory_type: public Memory_type
{
public:
	stackMemory_type();
	virtual void setMemoryType();
	Register_type *base;
	int offset1;
	Register_type *offset2;
	int offset3;
	virtual string getStr();


	stackMemory_type(stackMemory_type*);
	
};










#endif