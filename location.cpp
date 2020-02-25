#include "location.h"





using namespace std;


stackMemory_type::stackMemory_type()
{

	setLocationType();
	setMemoryType();
	base = &(Register_type::Reg_RBP);
	offset1 = 0;
	offset3 = 0;
}

stackMemory_type::stackMemory_type(stackMemory_type* other)
{
	setLocationType();
	setMemoryType();
	base = other->base;
	offset1 = other->offset1;
	offset2 = other->offset2;
	offset3 = other->offset3;
	size = other->size;
	
}
void stackMemory_type::setMemoryType()
{
	memoryType = STACK;
}

string stackMemory_type::getStr()
{
	stringstream ss;
	string res;

	string o = "";

	if (offset2 == nullptr)
	{

		ss << offset1 << "(" << base->getStr() << ")";
	}
	else if (offset3 == 0)
	{
		
		ss << offset1 << "(" << base->getStr() << "," << (offset2->getStr()) << ")";
	}
	else
	{



		//cerr << "fff:" << (offset2->getStr()) << " " << offset3 << endl;
		ss << offset1 << "(" << base->getStr() << "," << (offset2->getStr()) << "," << offset3 << ")";
		//cerr << "b:"  << offset1 << "(%rbp, " << (offset2->getStr()) << ", " << offset3 << ")" << endl;
	}

	ss >> res;
	return res;

}

staticMemory_type::staticMemory_type()
{
	setMemoryType();
}



void staticMemory_type::setMemoryType()
{
	memoryType = STATIC;
}
string staticMemory_type::getStr()
{

	stringstream ss;
	string res;

	ss << name << "(%rip)";
	ss >> res;
	return res;
}
void Register_type::setLocationType()
{
	locationType = Location_type::REGISTER;
}
Register_type::Register_type()
{
	setLocationType();
}

Register_type::Register_type(const string& name)
{
	this->name = name;
	setLocationType();
}

string Register_type::getStr()
{

	stringstream ss;
	string  res;
	ss << "%" << name;
	ss >> res;
	return res;
}


Register_type Register_type::Reg_RAX("rax");
Register_type Register_type::Reg_RBX("rbx");
Register_type Register_type::Reg_RCX("rcx");
Register_type Register_type::Reg_RSI("rsi");
Register_type Register_type::Reg_RDI("rdi");

Register_type Register_type::Reg_R8("r8");
Register_type Register_type::Reg_R9("r9");
Register_type Register_type::Reg_R10("r10");
Register_type Register_type::Reg_R11("r11");
Register_type Register_type::Reg_R12("r12");
Register_type Register_type::Reg_R13("r13");
Register_type Register_type::Reg_R14("r14");
Register_type Register_type::Reg_R15("r15");

Register_type Register_type::Reg_RBP("rbp");
Register_type Register_type::Reg_RSP("rsp");


void Memory_type::setLocationType()
{
	locationType = Location_type::MEMORY;
}

void Immediate_type::setLocationType()
{
	locationType = Location_type::IMMEDIATE;
}

string Immediate_type::getStr()
{
	stringstream ss;
	ss << "$" << value << endl;
	string res;
	ss >> res;
	return res;
}
Immediate_type::Immediate_type()
{
	setLocationType();
}