#include "quadTranslator.h"

using namespace std;

void quadTranslator::transChild(Expression_node* t, list<Expression_node*>* quadList_p)
{
	for (auto child: t->child)
	{
		transExpr(static_cast<Expression_node*>(child), quadList_p);
	}
}


// get return type of a function using the given args
// simply check whether the left hand side is a function, then whether the args are valid 
Type_type* quadTranslator::getReturnType(funcSymbol_type* funcSymbol_p, argumentExprList_node* argExprList_p)
{

	if (funcSymbol_p->argList.size() != argExprList_p->child.size())
	{
		return nullptr;
	}

	auto it1 = funcSymbol_p->argList.begin();
	auto it2 = argExprList_p->child.begin();

	for (; it1 != funcSymbol_p->argList.end() && it2 != argExprList_p->child.end(); it1++, it2++)
	{
		varSymbol_type* var1_p = *it1;
		Expression_node* var2_p = static_cast<Expression_node*>(*it2);
		if (!(*(var1_p->type_p) == *(var2_p->type_p)))
		{
			return nullptr;
		}
	}

	return funcSymbol_p->type_p;
}

// get the type of the primary expression,
// literal value, or an ID
// if it's an ID, search in symbol table to find the type, and it's a left value
// otherwise it's a non-left value
void quadTranslator::getPrimaryType(primaryExpr_node* primaryExpr_p)
{
	
	if (primaryExpr_node::ID == primaryExpr_p->valueType)
	{
		auto varSymbol_p = Scope_type::find_varSymbol(primaryExpr_p->primaryValue);
		if (nullptr == varSymbol_p)
		{
			cerr << "undeclared variable" << endl;
			return;
		}
		primaryExpr_p->lValue = true;
		primaryExpr_p->type_p = varSymbol_p->type_p;
	}
	else if (primaryExpr_node::INT == primaryExpr_p->valueType)
	{
		auto type_p = new Type_type();
		type_p->baseType_p = intType_type::intType_const_p;
		primaryExpr_p->lValue = false;
		primaryExpr_p->type_p = type_p;
	}
	else if (primaryExpr_node::FLOAT == primaryExpr_p->valueType)
	{
		auto type_p = new Type_type();

		type_p->baseType_p = floatType_type::floatType_const_p;
		primaryExpr_p->lValue = false;
		primaryExpr_p->type_p = type_p;
	}
	else if (primaryExpr_node::STRING == primaryExpr_p->valueType)
	{
		auto type_p = new Type_type();
		type_p->specifierList.push_back(*(new pointerSpecifier_type));
		type_p->baseType_p = intType_type::intType_const_p;
		primaryExpr_p->lValue = false;
		primaryExpr_p->type_p = type_p;
	}
	else if (primaryExpr_node::CHAR == primaryExpr_p->valueType)
	{
		auto type_p = new Type_type();

		type_p->baseType_p = charType_type::charType_const_p;
		primaryExpr_p->lValue = false;
		primaryExpr_p->type_p = type_p;
	}
}

// subscripts e.g. a[5]
// the left hand side must have a topmost specifier of pointer or array
// and the right hand side must in type of int 
// return a left value
void quadTranslator::getSubscriptType(postfixExpr_node* t)
{


	auto child1 = static_cast<Expression_node*>(t->child[1]);
	auto child0 = static_cast<Expression_node*>(t->child[0]);

	if (child1->type_p->specifierList.size() != 0)
	{
		cerr << "subscript must be an integer" << endl;
		return;
	}
	if (child1->type_p->baseType_p != intType_type::intType_const_p)
	{
		cerr << "subscript must be an integer" << endl;
		return;
	}

	if (child0->type_p->specifierList.size() == 0)
	{
		cerr << "subscript left hand side is not a pointer or array";
		return;
	}
	if (!(child0->type_p->specifierList.front().isPointer() ||
		child0->type_p->specifierList.front().isArray()))
	{
		cerr << "subscript left hand side is not a pointer or array";
		return;
	}
	// not sure if its implemented, copy-construction
	auto type_p = new Type_type(*(child0->type_p));

	// not sure either.
	type_p->specifierList.pop_front();


	t->lValue = true;
	t->type_p =  type_p;
}

// member access e.g. pair.first
// the left hand side must be of a struct type
// the right hand side must be a primary expression of an ID
// check whether the struct type has such a field
// return the field's type as a left value
void quadTranslator::getMemberType(postfixExpr_node* t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "dot left hand side is not of a struct type" << endl;
		return;
	}

	if (child0->type_p->baseType_p->baseTypeType != baseType_type::STRUCT)
	{

		cerr << "dot left hand side is not of a struct type" << endl;
		return;
	}
	auto structType_p = static_cast<structType_type*>(child0->type_p->baseType_p);
	for (auto field_p: structType_p->fieldList)
	{
		if (field_p->name == t->memberName)
		{
			t->type_p = field_p->type_p;
			t->lValue = true;
			return;
		}
	}
	return;
}

// member access with a potiner e.g. pair_p->first
// pretty similar as the method above, but the left hand side should be a pointer to a struct
void quadTranslator::getRefMemberType(postfixExpr_node* t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 1)
	{
		cerr << "arrow left hand side is not a pointer" << endl;
		return;
	}
	if (!(child0->type_p->specifierList.front().isPointer()))
	{
		cerr << "ssssssss" << endl;
		cerr << "arrow left hand side is not a pointer" << endl;
		return;
	}
	if (child0->type_p->baseType_p->baseTypeType != baseType_type::STRUCT)
	{

		cerr << "dot left hand side is not of a struct type" << endl;
		return;
	}
	auto structType_p = static_cast<structType_type*>(child0->type_p->baseType_p);
	for (auto field_p: structType_p->fieldList)
	{
		if (field_p->name == t->memberName)
		{
			t->type_p = field_p->type_p;
			t->lValue = true;
			return;
		}
	}
	return;
}

// self-inc/dec as a postfix operator, e.g. i++
// check whether the child's type is int or float,
// returns a non-left value
void quadTranslator::getRightIncDecType(postfixExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "invalid inc or dec operand, only float/int supported" << endl;
		return;
	}
	if (child0->type_p->baseType_p != intType_type::intType_const_p &&
		child0->type_p->baseType_p != floatType_type::floatType_const_p)
	{
		cerr << "invalid inc or dec operand, only float/int supported" << endl;
		return;
	}
	t->lValue = false;
	t->type_p = child0->type_p;
}

// self inc/dec as a unary operator, e.g. ++i
// pretty similar as the one above, but returns a left value.
void quadTranslator::getLeftIncDecType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "invalid inc or dec operand, only float/int supported" << endl;
		return;
	}
	if (child0->type_p->baseType_p != intType_type::intType_const_p &&
		child0->type_p->baseType_p != floatType_type::floatType_const_p)
	{
		cerr << "invalid inc or dec operand, only float/int supported" << endl;
		return;
	}
	t->lValue = true;
	t->type_p = child0->type_p;
}




// reference operator getting the address, e.g. &pair
// the child's type must be of a left value.
// returns a non-left value
void quadTranslator::getRefType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->lValue == false)
	{
		cerr << "cannot get the address of a non-left value" << endl;
		return;
	}

	t->type_p = new Type_type(child0->type_p);

	t->type_p->specifierList.push_front(*(new pointerSpecifier_type()));

	t->lValue = false;
}

// de-reference of a address, e.g. *pair_p
// the child's type must be of a pointer, or an array
// returns a left-value
void quadTranslator::getDerefType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() == 0)
	{
		cerr << "cannot de-reference a non-address value" << endl;
		return;
	}

	if (!(child0->type_p->specifierList.front().isPointer() ||
		child0->type_p->specifierList.front().isArray()))
	{
		cerr << "cannot de-reference a non-address value" << endl;
		return;
	}

	t->type_p = new Type_type(child0->type_p);
	t->type_p->specifierList.pop_front();
	t->lValue = true;
}

// positive number op, e.g. +a, -23
// the child's type must be of int or float
// return a non-left value
void quadTranslator::getPlusMinusType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "plus/minus-unary operator must have int or float operand" << endl;
		return;
	}

	if (child0->type_p->baseType_p != intType_type::intType_const_p &&
		child0->type_p->baseType_p != floatType_type::floatType_const_p)
	{
		cerr << "plus/minus-unary operator must have int or float operand" << endl;
		return;
	}

	t->type_p = new Type_type(child0->type_p);
	t->lValue = false;
}

// negative operator, e.g. !a
// the child's type must be of int
// return a non-left value

void quadTranslator::getNegType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "negative operator must have a int operand" << endl;
		return;
	}

	if (child0->type_p->baseType_p != intType_type::intType_const_p)
	{
		cerr << "negative operator must have a int operand" << endl;
		return;
	}
	t->type_p = new Type_type(child0->type_p);
	t->lValue = false;
}

// complement operator, e.g. ~a
// the child's type must be of a int
// return a non-left value
void quadTranslator::getCmplType(unaryExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	if (child0->type_p->specifierList.size() != 0)
	{
		cerr << "complement operator must have a int operand" << endl;
		return;
	}

	if (child0->type_p->baseType_p != intType_type::intType_const_p)
	{
		cerr << "complement operator must have a int operand" << endl;
		return;
	}
	t->type_p = new Type_type(child0->type_p);
	t->lValue = false;
}

void quadTranslator::getPrintType(unaryExpr_node *unaryExpr_p)
{
	
	auto child0 = static_cast<Expression_node*>(unaryExpr_p->child[0]);
	unaryExpr_p->type_p = new Type_type(child0->type_p);
	unaryExpr_p->lValue = false;
}


// mul/div operator ,e.g.  5 * a, a / b
// both hand side must be of int/float
// when any of a side is of float, then the return type is float
// otherwise return an int
// as a non-left value
void quadTranslator::getMulDivType(multiplicativeExpr_node *t)
{
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->specifierList.size() != 0)
		{
			cerr << "mul/div operands must be of int or float" << endl;
			return;
		}
		if (c->type_p->baseType_p != intType_type::intType_const_p &&
			c->type_p->baseType_p != floatType_type::floatType_const_p)
		{
			cerr << "mul/div operands must be of int or float" << endl;
			return;
		}
	}
	t->type_p = new Type_type();
	t->lValue = false;
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->baseType_p == floatType_type::floatType_const_p)
		{
			t->type_p->baseType_p = floatType_type::floatType_const_p;
			return;
		}
	}
	t->type_p->baseType_p = intType_type::intType_const_p;
}

// additive operator e.g. a + 2, b - 1
// the rule is similar as the one above
void quadTranslator::getAddSubType(additiveExpr_node *t)
{
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->specifierList.size() != 0)
		{
			cerr << "add/sub operands must be of int or float" << endl;
			return;
		}
		if (c->type_p->baseType_p != intType_type::intType_const_p &&
			c->type_p->baseType_p != floatType_type::floatType_const_p)
		{
			cerr << "add/sub operands must be of int or float" << endl;
			return;
		}
	}
	t->type_p = new Type_type();
	t->lValue = false;
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->baseType_p == floatType_type::floatType_const_p)
		{
			t->type_p->baseType_p = floatType_type::floatType_const_p;
			return;
		}
	}
	t->type_p->baseType_p = intType_type::intType_const_p;
}

// shift operator , e.g. 1 >> 2, 23 << k
// operands must be of int,
// return an int as a non-left value
void quadTranslator::getShiftType(shiftExpr_node *t)
{
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->specifierList.size() != 0)
		{
			cerr << "add/sub operands must be of int" << endl;
			return;
		}
		if (c->type_p->baseType_p != intType_type::intType_const_p)
		{
			cerr << "add/sub operands must be of int" << endl;
			return;
		}
	}
	t->type_p = new Type_type();
	t->lValue = false;
	t->type_p->baseType_p = intType_type::intType_const_p;
}


// all the other bit-wise operators,
// e.g. 1 < 2, 'g' >= 'k', 'd' > 24, 'd' && 2.5
// the operands must be of int, float, or char since char type is simulated using int
// returns an int type as a non-left value
void quadTranslator::getBitwiseType(Expression_node *t)
{
	for (auto child: t->child)
	{
		auto c = static_cast<Expression_node*>(child);
		if (c->type_p->specifierList.size() != 0)
		{
			cerr << "bit-wise operands must be of int, float or char" << endl;
			return;
		}
		if (c->type_p->baseType_p != intType_type::intType_const_p &&
			c->type_p->baseType_p != floatType_type::floatType_const_p &&
			c->type_p->baseType_p != charType_type::charType_const_p)
		{
			cerr << "bit-wise operands must be of int, float or char" << endl;
			return;
		}
	}
	t->type_p = new Type_type();
	t->lValue = false;
	t->type_p->baseType_p = intType_type::intType_const_p;
}


// assignment operator, e.g. a = 42
// using the strict strategy here, which means the both hand side must be of the same type
// and the left hand side must be a left value
// return the type of the left hand side as a left value
void quadTranslator::getAssignType(assignExpr_node *t)
{
	auto child0 = static_cast<Expression_node*>(t->child[0]);
	auto child1 = static_cast<Expression_node*>(t->child[1]);
	if (child0->lValue == false)
	{
		cerr << "assignment operator need left hand side as a left value" << endl;
		return;
	}
	if (!(*(child0->type_p) == *(child1->type_p)))
	{
		cerr << "assignment operator need operands to be of the same type" << endl;
		return;
	}
	t->type_p = new Type_type(child0->type_p);
	t->lValue = true;

}




void quadTranslator::transExpr(Expression_node* t, std::list<Expression_node*>* quadList_p)
{

	if (EXPRESSION == t->get_nodeType())
	{
		transChild(t, quadList_p);
		t->type_p = new Type_type(static_cast<Expression_node*>(t->child[0])->type_p);
		t->lValue = false;
	}

	else if (PRIMARY_EXPR == t->get_nodeType())
	{
		// recursion ends here
		auto primaryExpr_p = static_cast<primaryExpr_node*>(t);
		getPrimaryType(primaryExpr_p);
	}
	else if (POSTFIX_EXPR == t->get_nodeType())
	{

		auto postfixExpr_p = static_cast<postfixExpr_node*>(t);
		cerr << postfixExpr_node::postfix_op_dic[postfixExpr_p->expr_operator] << endl;
		if (postfixExpr_node::FUNC_CALL_OP == postfixExpr_p->expr_operator)
		{
			if (PRIMARY_EXPR != postfixExpr_p->child[0]->get_nodeType())
			{
				cerr << "unsupported" << endl;
				return;
			}
			auto primaryExpr_p = static_cast<primaryExpr_node*>(postfixExpr_p->child[0]);
			if (primaryExpr_node::ID != primaryExpr_p->valueType)
			{
				cerr << "unsupported" << endl;
				return;
			}
			auto funcSymbol_p = Scope_type::find_funcSymbol(primaryExpr_p->primaryValue);
			if (nullptr == funcSymbol_p)
			{
				cerr << "undefined function" << endl;
				return;
			}
			//transChild(t->child[1], quadList_p);
			quadList_p->push_back(primaryExpr_p);
			for (auto c: t->child[1]->child)
			{
				auto e = static_cast<Expression_node*>(c);
				transExpr(e, quadList_p);
			}
			auto returnType_p = getReturnType(funcSymbol_p, static_cast<argumentExprList_node*>(postfixExpr_p->child[1]));
			if (nullptr == returnType_p)
			{
				cerr << "wrong match of params" << endl;
				return;
			}
			t->type_p = returnType_p;

		}
		else if (postfixExpr_node::SUBSCRIPT_OP == postfixExpr_p->expr_operator)
		{
			transChild(postfixExpr_p, quadList_p);
			getSubscriptType(postfixExpr_p);
		}

		else if (postfixExpr_node::DOT_OP == postfixExpr_p->expr_operator)
		{
			transExpr(static_cast<Expression_node*>(t->child[0]), quadList_p);
			getMemberType(postfixExpr_p);
		}
		else if (postfixExpr_node::AR_OP == postfixExpr_p->expr_operator)
		{
			transExpr(static_cast<Expression_node*>(t->child[0]), quadList_p);
			getRefMemberType(postfixExpr_p);
		}
		else if (postfixExpr_node::INC_OP == postfixExpr_p->expr_operator || postfixExpr_node::DEC_OP == postfixExpr_p->expr_operator)
		{
			transChild(postfixExpr_p, quadList_p);
			getRightIncDecType(postfixExpr_p);
		}
	}
	else if (UNARY_EXPR == t->get_nodeType())
	{
		auto unaryExpr_p = static_cast<unaryExpr_node*>(t);
		if (unaryExpr_node::INC_OP == unaryExpr_p->expr_operator || unaryExpr_node::DEC_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getLeftIncDecType(unaryExpr_p);
		}
		else if (unaryExpr_node::REF_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getRefType(unaryExpr_p);
		}
		else if (unaryExpr_node::IDR_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getDerefType(unaryExpr_p);
		}
		else if (unaryExpr_node::PLUS_OP == unaryExpr_p->expr_operator ||
				unaryExpr_node::MINUS_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getPlusMinusType(unaryExpr_p);
		}
		else if (unaryExpr_node::NEG_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getNegType(unaryExpr_p);
		}
		else if (unaryExpr_node::CMPL_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getCmplType(unaryExpr_p);
		}
		else if (unaryExpr_node::PRINT_OP == unaryExpr_p->expr_operator)
		{
			transChild(unaryExpr_p, quadList_p);
			getPrintType(unaryExpr_p);
		}
	}
	else if (MULTIPLICATIVE_EXPR == t->get_nodeType())
	{
		auto mulExpr_p = static_cast<multiplicativeExpr_node*>(t);
		transChild(mulExpr_p, quadList_p);
		getMulDivType(mulExpr_p);
	}
	else if (ADDITIVE_EXPR == t->get_nodeType())
	{
		auto addExpr_p = static_cast<additiveExpr_node*>(t);
		transChild(addExpr_p, quadList_p);
		getAddSubType(addExpr_p);
	}
	else if (SHIFT_EXPR == t->get_nodeType())
	{
		auto shiftExpr_p = static_cast<shiftExpr_node*>(t);
		transChild(shiftExpr_p, quadList_p);
		getShiftType(shiftExpr_p);
	}
	else if (t->get_nodeType() == RELATIONAL_EXPR ||
			t->get_nodeType() == EQUALITY_EXPR ||
			t->get_nodeType() == AND_EXPR ||
			t->get_nodeType() == EXCLUSIVEOR_EXPR ||
			t->get_nodeType() == INCLUSIVEOR_EXPR ||
			t->get_nodeType() == LOGICALAND_EXPR ||
			t->get_nodeType() == LOGICALOR_EXPR)
	{
		transChild(static_cast<Expression_node*>(t), quadList_p);
		getBitwiseType(t);
	}

	else if (t->get_nodeType() == ASSIGN_EXPR)
	{
		auto assignExpr_p = static_cast<assignExpr_node*>(t);

		transExpr(static_cast<Expression_node*>(assignExpr_p->child[1]), quadList_p);

		transExpr(static_cast<Expression_node*>(assignExpr_p->child[0]), quadList_p);
		getAssignType(assignExpr_p);
	}

	quadList_p->push_back(t);
} 
