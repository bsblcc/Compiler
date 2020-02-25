
#include <vector>
#include <list>
#include <iostream>
#include "type.h"
#include <fstream>


#ifndef AST_H
#define AST_H

using namespace std;


const string ASTNode_dic[] = 
{
	"root",
	"translation unit",
	"external declaration",
	"function definition",
	"function declaration",
	"variable declaration",
	"type specifier",
	"variable declarator list",
	"initial variable declarator",
	"variable declarator",
	"function definition declarator",
	"parameter declaration list",
	"parameter declaration",
	"show symbol table",
	"statement",
	"compound statement",
	"expression statement",
	"selection statement",
	"iteration statement",
	"expression",
	"assignment expression",
	"unary expression",
	"postfix expression",
	"argument expression list",
	"logical-or expression",
	"logical-and expression",
	"inclusive-or expression",
	"exclusive-or expression",
	"and expression",
	"equality expression",
	"relational expression",
	"shift expression",
	"additive expression",
	"multiplicative expression",
	"primary expression",
	"jump statement",
	"struct declaration",
	"left bracet",
	"right bracet",
	"struct variable declaration list",
};

enum ASTNode_type
{
	ROOT, TRANS_UNIT, EXTERN_DECL, FUNC_DEF, FUNC_DECL, VAR_DECL, TYPE_SPEC, VAR_DECLARATOR_LIST, INIT_VAR_DECLARATOR,
	VAR_DECLARATOR, FUNC_DEF_DECLARATOR, PARAM_DECL_LIST, PARAM_DECL, SHOW_STAB, 
	STATEMENT, COMPOUND_STMT, EXPRESSION_STMT, SELECTION_STMT, ITERATION_STMT,
	EXPRESSION, ASSIGN_EXPR, UNARY_EXPR, POSTFIX_EXPR, ARGUMENT_EXPR_LIST,
	LOGICALOR_EXPR, LOGICALAND_EXPR, INCLUSIVEOR_EXPR, EXCLUSIVEOR_EXPR,
	AND_EXPR, EQUALITY_EXPR, RELATIONAL_EXPR, SHIFT_EXPR, ADDITIVE_EXPR,
	MULTIPLICATIVE_EXPR, PRIMARY_EXPR, JUMP_STMT, STRUCT_DECL,
	LEFT_BRACET, RIGHT_BRACET, STRUCT_VAR_DECL_LIST,

};




class AST_node
{
	
public:
	std::vector<AST_node*> child;

	int height;
	string blank_buffer;
	virtual int get_nodeType();
	void print_nodeName();
	virtual void print_info();

	void print();

	void bracet_begin();

	void bracet_end();
	


	void insertChild(AST_node* t) 
	{
		child.push_back(t);
	}
	template <typename T, typename... Args>
	void insertChild(T t, Args... args)
	{
	    //std::cout << t <<std::endl ;
		child.push_back(t);
		insertChild(args...) ;
	}

};






class transUnit_node : public AST_node
{
public:

	 virtual int get_nodeType();
};

class externDecl_node : public transUnit_node
{
public:

	virtual int get_nodeType();
};


class funcDef_node : public externDecl_node
{
public:

	virtual int get_nodeType();
};


class funcDecl_node : public externDecl_node
{
public:

	virtual int get_nodeType();
};

class varDecl_node : public externDecl_node
{
public:

	virtual int get_nodeType();
};



class typeSpec_node : public AST_node
{
public:

	virtual int get_nodeType();
	enum
	{
		STRUCT, BUILTIN,
	} type;
	enum builtInType_type
	{
		INT_TYPE, VOID_TYPE, CHAR_TYPE, FLOAT_TYPE,
	};
	union
	{
		string* name;
		builtInType_type builtInType;
	};

	virtual void print_info();
};






class varDeclaratorList_node : public AST_node
{
public:

	virtual int get_nodeType();

	
};
class initVarDeclarator_node : public AST_node
{
public:

	virtual int get_nodeType();
	



};

class varDeclarator_node : public AST_node
{
public:

	virtual int get_nodeType();
	string varName;

	list<typeSpecifier_type> typeSpecifierList;
	virtual void print_info();

};

class funcDefDeclarator_node : public AST_node
{
public:
	virtual int get_nodeType();
	
	string funcName;


	list<typeSpecifier_type> typeSpecifierList;
	virtual void print_info();
};

class paramDeclList_node : public AST_node
{
public:
	virtual int get_nodeType();
	
};

class paramDecl_node : public AST_node
{
public:
	virtual int get_nodeType();
};

class showStab_node : public AST_node
{
public:

	virtual int get_nodeType();

	
};



class Statement_node : public AST_node
{
public:
	virtual int get_nodeType();
};
class compoundStmt_node : public Statement_node
{
public:
	virtual int get_nodeType();
};
class expressionStmt_node : public Statement_node
{
public:
	virtual int get_nodeType();
};
class selectionStmt_node : public Statement_node
{
public:
	virtual int get_nodeType();
};
class iterationStmt_node : public Statement_node
{
public:
	virtual int get_nodeType();
};




class Expression_node : public AST_node
{
public:
	virtual int get_nodeType();

	Type_type *type_p;

	bool lValue;

	int id;
	static int count;
	int usage;
	Expression_node();


	virtual string getOpStr();

	void printQuad();

};




class assignExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};

class unaryExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		INC_OP, DEC_OP, REF_OP, IDR_OP, PLUS_OP, MINUS_OP,
		NEG_OP, CMPL_OP, PRINT_OP
	} expr_operator;
	virtual void print_info();
	static const string unary_op_dic[];
	virtual string getOpStr();
};

class postfixExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		SUBSCRIPT_OP, FUNC_CALL_OP, DOT_OP, AR_OP, INC_OP, DEC_OP, 
	} expr_operator;
	string memberName;
	virtual void print_info();
	static const string postfix_op_dic[];
	virtual string getOpStr();
};
class argumentExprList_node : public Expression_node
{
public:
	virtual int get_nodeType();
	//virtual string getOpStr();
};

class logicalOrExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};
class logicalAndExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};

class inclusiveOrExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};

class exclusiveOrExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};
class andExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual string getOpStr();
};
class equalityExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		EQ_OP, NE_OP,
	} expr_operator;
	virtual void print_info();
	static const string equality_op_dic[];
	virtual string getOpStr();
};

class relationalExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum 
	{
		L_OP, G_OP, LE_OP, GE_OP,
	} expr_operator;
	virtual void print_info();
	static const string relational_op_dic[];
	virtual string getOpStr();
};
class shiftExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		LSHIFT_OP, RSHIFT_OP,
	} expr_operator;
	virtual void print_info();
	static const string shift_op_dic[];
	virtual string getOpStr();
};
class additiveExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		ADD_OP, SUB_OP,
	} expr_operator;
	virtual void print_info();
	static const string additive_op_dic[];
	virtual string getOpStr();
};
class multiplicativeExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	virtual void print_info();
	enum
	{
		MUL_OP, DIV_OP,
	} expr_operator;
	static const string multiplicative_op_dic[];
	virtual string getOpStr();
};

class primaryExpr_node : public Expression_node
{
public:
	virtual int get_nodeType();
	enum
	{
		ID, INT, FLOAT, STRING, CHAR
	} valueType;
	string primaryValue;
	const static string valueType_dic[];
	virtual void print_info();
	virtual string getOpStr();

};

class jumpStmt_node : public AST_node
{
public:
	virtual int get_nodeType();
	virtual void print_info();
	enum
	{
		BREAK, RETURN, CONTINUE,
	} jump_type;
	static const string jump_type_dic[];
};

class leftBracet_node: public AST_node
{
public:
	virtual int get_nodeType();
	virtual void print_info();
};



class rightBracet_node: public AST_node
{
public:
	virtual int get_nodeType();
	virtual void print_info();
};

class structDecl_node : public externDecl_node
{
public:
	virtual int get_nodeType();
	string name;

};

class structVarDeclList_node: public AST_node
{
public:
	virtual int get_nodeType();

};

void print(AST_node* t);

#endif