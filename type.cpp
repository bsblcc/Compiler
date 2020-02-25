#include "type.h"



using namespace std;






const string Type_type::typeSpecifier_dic[] = 
{
	"array",
	"pointer",
};


const string builtInType_type::builtInType_dic[] = 
{
	"int",
	"void",
	"char",
	"float",
};







structType_type::structType_type()
{
	baseType_type::baseTypeType = baseType_type::STRUCT;
}

builtInType_type::builtInType_type()
{
	baseTypeType = baseType_type::BUILTIN;
}

intType_type::intType_type()
{
	name = "int";
	builtInTypeType = builtInType_type::INT_TYPE;
}

voidType_type::voidType_type()
{
	name = "void";
	builtInTypeType = builtInType_type::VOID_TYPE;
}
charType_type::charType_type()
{
	name = "char";
	builtInTypeType = builtInType_type::CHAR_TYPE;
}
floatType_type::floatType_type()
{
	name = "float";
	builtInTypeType = builtInType_type::FLOAT_TYPE;
}




bool baseType_type::operator == (const baseType_type& other) const
{

	return this == &(other);
}
Type_type::Type_type(const Type_type& other)
{
	baseType_p = other.baseType_p;
	specifierList = other.specifierList;
}

Type_type::Type_type(Type_type *other)
{
	baseType_p = other->baseType_p;
	specifierList = other->specifierList;
}
Type_type::Type_type()
{
}

arraySpecifier_type::arraySpecifier_type()
{
	specifierType = typeSpecifier_type::ARRAY;
}
pointerSpecifier_type::pointerSpecifier_type()
{
	specifierType = typeSpecifier_type::POINTER;
}
bool typeSpecifier_type::isPointer() const
{
	return specifierType == typeSpecifier_type::POINTER;
}
bool typeSpecifier_type::isArray() const
{
	return specifierType == typeSpecifier_type::ARRAY;
}
string typeSpecifier_type::getStr() const
{
	if (specifierType == typeSpecifier_type::ARRAY)
	{
		return "array";
	}
	else
	{
		return "pointer";
	}
}

bool typeSpecifier_type::operator == (const typeSpecifier_type& other) const
{
	return specifierType == other.specifierType;
}


bool Type_type::operator == (const Type_type& other) const
{
	if ((baseType_p != other.baseType_p))
	{
		return false;
	}
	if (specifierList.size() != other.specifierList.size())
	{
		return false;
	}
	auto it1 = specifierList.begin();
	auto it2 = other.specifierList.begin();

	for (; 
		it1 != specifierList.end() && it2 != other.specifierList.end();
		it1++, it2++)
	{
		if (!(*it1 == *it2))
		{
			return false;
		}
	}

	return true;
}

int Type_type::getSize()
{
	/*if (size != -1)
	{
		return size;
	}*/
	int res = 1;
	for (auto typeSpecifier : specifierList)
	{
		if (typeSpecifier.specifierType == typeSpecifier_type::POINTER)
		{
			return res * 8;
		}
		else
		{
			auto arraySpecifier_p = static_cast<arraySpecifier_type*>(&typeSpecifier);
			//cerr << "length: " << arraySpecifier_p->length << endl;
			res = res * arraySpecifier_p->length;
		}
	}
	return size = res * baseType_p->getSize();
}

int builtInType_type::getSize()
{
	return 8;
}

int structType_type::getSize()
{
	int res = 0;
	for (auto field_p: fieldList)
	{
		field_p->offset = res;
		res += field_p->type_p->getSize();
	}
	return res;
}



ostream& operator << (ostream& out, const Type_type& t)
{
	for (auto i: t.specifierList)
	{
		out << i.getStr() << " ";
	}
	out << t.baseType_p->name;
	return out;
}

ostream& operator << (ostream& out, const structType_type& t)
{
	out << "name: " << t.name << endl;
	out << "fields:" << endl;



	for (auto field_p: t.fieldList)
	{
		out << "name: " << field_p->name << endl;
		out << "type: " <<  *(field_p->type_p) << endl;
	}
	return out;
}
intType_type* intType_type::intType_const_p = new intType_type();
voidType_type* voidType_type::voidType_const_p = new voidType_type();
floatType_type* floatType_type::floatType_const_p = new floatType_type();
charType_type* charType_type::charType_const_p = new charType_type();


/*
auto Type_type::intType_const_p = new Type_type();
auto Type_type::voidType_const_p = new Type_type();
auto Type_type::charType_const_p = new Type_type();
auto Type_type::floatType_const_p = new Type_type();

auto pointerEdge_type::pointerEdge_const_p = new pointerEdge_type();
auto arrayEdge_type::arrayEdge_const_p = new arrayEdge_type();


funcCallEdge_type::funcCallEdge_type()
{
	edgeType = typeEdge_type::FUNC_CALL;
}
memberAccessEdge_type::memberAccessEdge_type()
{
	edgeType = typeEdge_type::MEMBER_ACS;
}
pointerEdge_type::pointerEdge_type()
{
	edgeType = typeEdge_type::POINTER;
}
arrayEdge_type::arrayEdge_type()
{
	edgeType = typeEdge_type::ARRAY;
}

Type_type* Type_type::onEdge(typeEdge_type* edge_p)
{
	for (auto e: edgeList)
	{
		if (e.first == edge_p)
		{
			return e.second;
		}
	}
	pair<typeEdge_type*, Type_type*> tmp1, tmp2;
	tmp1.first = edge_p;
	tmp1.second = new Type_type();

	tmp2.first = edge_p;
	tmp2.second = this;
	tmp1.second->edgeList.push_back(tmp2);
	edgeList.push_back(tmp1);

	return tmp1.second;
}

int Type_type::addEdge(typeEdge_type* edge_p, Type_type* to_p)
{
	for (auto e: edgeList)
	{
		if (e.first == edge_p)
		{
			return -1;
		}
	}
	pair<typeEdge_type*, Type_type*> tmp;
	tmp.first = edge_p;
	tmp.second = to_p;
	edgeList.push_back(tmp);
	return 0;
}


ostream& operator << (ostream& out, typeEdge_type& edge)
{
	funcCallEdge_type* fce_p;
	memberAccessEdge_type* mae_p;
	switch (edge.edgeType)
	{
		case typeEdge_type::FUNC_CALL:
			fce_p = static_cast<funcCallEdge_type*>(&edge);
			out << "func call edge, params:" << endl;

			for (auto t: fce_p->paramTypeList)
			{
				cout << *t << endl;
			}
			break;

		case typeEdge_type::MEMBER_ACS:

			mae_p = static_cast<memberAccessEdge_type*>(&edge);
			out << "mem acs edge, field name: " << mae_p->memberName;
			break;

		case typeEdge_type::POINTER:

			out << "pointer edge";

			break;

		case typeEdge_type::ARRAY:
			out << "array edge";
			break;
	}

	return out;
}



ostream& operator << (ostream& out, const Type_type& type)
{
	if (Type_type::intType_const_p == &type)
	{
		out << "int ";
	}
	else if (Type_type::voidType_const_p == &type)
	{
		out << "void ";
	}
	else if (Type_type::charType_const_p == &type)
	{
		out << "char ";
	}
	else if (Type_type::floatType_const_p == &type)
	{
		out << "float ";
	}
	else
	{
		for (auto pair: type.edgeList)
		{
			auto edge_p = pair.first;
			auto to_p = pair.second;

			out << "on edge:" << endl << *edge_p << endl << "to" <<endl;
			out << *to_p;
		}
	}
}

*/