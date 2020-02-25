
#include "AST.h"

#include <cstring>



ofstream aout("ast.out");
ofstream gout("CFG.out");




void AST_node::print_nodeName()
{
	blank_buffer = "";
	for (int i = 1; i <= height; i++)
	{
		aout << "|   ";
		blank_buffer += "|   ";
	}
	aout << *(ASTNode_dic + get_nodeType()) << endl;
}

int AST_node::get_nodeType()
{
	return ROOT;
}

void AST_node::print()
{
	print_nodeName();
	print_info();
}




void AST_node::print_info()
{
}

void AST_node::bracet_begin()
{
	aout << blank_buffer << "{" << endl;
}

void AST_node::bracet_end()
{
	aout << blank_buffer << "}" << endl;
}

void typeSpec_node::print_info()
{
	bracet_begin();
	//aout << blank_buffer << "  " << "built-in type: " << builtInType_dic[builtInType] << endl;
	


	bracet_end();
}

void varDeclarator_node::print_info()
{
	bracet_begin();

	aout << blank_buffer << "  " << "varName: " << varName << endl;
	aout << blank_buffer << "  " <<  "type specifier: ";

	for (auto sp : typeSpecifierList)
	{
		aout << sp.getStr() << " ";
	}
	aout << endl;
	bracet_end();
}

void funcDefDeclarator_node::print_info()
{
	bracet_begin();

	aout << blank_buffer << "  " << "funcName: " << funcName << endl;
	aout << blank_buffer << "  " <<  "type specifier: ";

	for (auto sp : typeSpecifierList)
	{
		aout << sp.getStr() << " ";
	}
	aout << endl;
	bracet_end();
}

int Expression_node::count = 0;
Expression_node::Expression_node()
{
	id = ++count;
}

int Statement_node::get_nodeType()
{
	return STATEMENT;
}

int compoundStmt_node::get_nodeType()
{
	return COMPOUND_STMT;
}

int expressionStmt_node::get_nodeType()
{
	return EXPRESSION_STMT;
}

int selectionStmt_node::get_nodeType()
{
	return SELECTION_STMT;
}
int iterationStmt_node::get_nodeType()
{
	return ITERATION_STMT;
}
int Expression_node::get_nodeType()
{
	return EXPRESSION;
}
int assignExpr_node::get_nodeType()
{
	return ASSIGN_EXPR;
}
int unaryExpr_node::get_nodeType()
{
	return UNARY_EXPR;
}
int postfixExpr_node::get_nodeType()
{
	return POSTFIX_EXPR;
}
int argumentExprList_node::get_nodeType()
{
	return ARGUMENT_EXPR_LIST;
}
int logicalOrExpr_node::get_nodeType()
{
	return LOGICALOR_EXPR;
}
int logicalAndExpr_node::get_nodeType()
{
	return LOGICALAND_EXPR;
}
int inclusiveOrExpr_node::get_nodeType()
{
	return INCLUSIVEOR_EXPR;
}
int exclusiveOrExpr_node::get_nodeType()
{
	return EXCLUSIVEOR_EXPR;
}
int andExpr_node::get_nodeType()
{
	return AND_EXPR;
}
int equalityExpr_node::get_nodeType()
{
	return EQUALITY_EXPR;
}
int relationalExpr_node::get_nodeType()
{
	return RELATIONAL_EXPR;
}
int shiftExpr_node::get_nodeType()
{
	return SHIFT_EXPR;
}
int additiveExpr_node::get_nodeType()
{
	return ADDITIVE_EXPR;
}
int multiplicativeExpr_node::get_nodeType()
{
	return MULTIPLICATIVE_EXPR;
}
int primaryExpr_node::get_nodeType()
{
	return PRIMARY_EXPR;
}
int structDecl_node::get_nodeType()
{
	return STRUCT_DECL;
}
int typeSpec_node::get_nodeType()
{
	return TYPE_SPEC;
}
int varDecl_node::get_nodeType()
{
	return VAR_DECL;
}
int funcDecl_node::get_nodeType()
{
	return FUNC_DECL;
}
int funcDef_node::get_nodeType()
{
	return FUNC_DEF;
}
int externDecl_node::get_nodeType()
{
	return EXTERN_DECL;
}
int transUnit_node::get_nodeType()
{
	return TRANS_UNIT;
}

int varDeclaratorList_node::get_nodeType()
{
	return VAR_DECLARATOR_LIST;
}
int initVarDeclarator_node::get_nodeType()
{
	return INIT_VAR_DECLARATOR;
}

int varDeclarator_node::get_nodeType()
{
	return VAR_DECLARATOR;
}
int funcDefDeclarator_node::get_nodeType()
{
	return FUNC_DEF_DECLARATOR;
}
int paramDeclList_node::get_nodeType()
{
	return PARAM_DECL_LIST;
}
int paramDecl_node::get_nodeType()
{
	return PARAM_DECL;
}
int showStab_node::get_nodeType()
 {
 	return SHOW_STAB;
 }
const string unaryExpr_node::unary_op_dic[] = 
{
	"++", "--", "&", "*", "+", "-", "!", "~", "@",
};

const string postfixExpr_node::postfix_op_dic[] = 
{
	"[]", "()", ".", "->", "++", "--",
};
const string equalityExpr_node::equality_op_dic[] = 
{
	"==", "!=", 
};
const string relationalExpr_node::relational_op_dic[] = 
{
	"<", ">", "<=", ">=",
};

const string shiftExpr_node::shift_op_dic[] = 
{
	"<<", ">>",
};

const string additiveExpr_node::additive_op_dic[] = 
{
	"+", "-",
};

const string multiplicativeExpr_node::multiplicative_op_dic[] =
{
	"*", "/",
};

void multiplicativeExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << multiplicative_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}
void additiveExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << additive_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}

void shiftExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << shift_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}
void relationalExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << relational_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}

void equalityExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << equality_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}
void postfixExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << postfix_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}
void unaryExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "operator: " << unary_op_dic[expr_operator];
	aout << endl;
	bracet_end();
}

int jumpStmt_node::get_nodeType()
{
	return JUMP_STMT;
}
const string jumpStmt_node::jump_type_dic[] = 
{
	"break", "return", "continue",
};
void jumpStmt_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "jump type: " << jump_type_dic[jump_type];
	aout << endl;
	bracet_end();
}

const string primaryExpr_node::valueType_dic[] = 
{
	"identifier", "integer", "float", "string"
};

void primaryExpr_node::print_info()
{
	bracet_begin();
	aout << blank_buffer << "  " << "primary value type: " << valueType_dic[valueType];
	aout << endl;
	aout << blank_buffer << "  " << "value: " << primaryValue << endl;
	bracet_end();
}

int leftBracet_node::get_nodeType()
{
	return LEFT_BRACET;
}
void leftBracet_node::print_info()
{
	bracet_begin();
	aout << "LB" << endl;
	bracet_end();
}


int rightBracet_node::get_nodeType()
{
	return RIGHT_BRACET;
}
void rightBracet_node::print_info()
{
	bracet_begin();
	aout << "RB" << endl;
	bracet_end();
}

int structVarDeclList_node::get_nodeType()
{
	return STRUCT_VAR_DECL_LIST;
}






void print(AST_node* t)
{

	// action:

	// print blanks

	
	t->print();

	for (auto child : t->child) 
	{
		child->height = t->height + 1;
		print(child);
	}

	return;
}

void Expression_node::printQuad()
{
	gout << "Quad#" << id << ":= ";
	for (auto c: child)
	{

		gout << "Quad#" << static_cast<Expression_node*>(c)->id << " ";
	}
	gout << getOpStr() << endl;
}


string Expression_node::getOpStr()
{
	return "list";
}

string assignExpr_node::getOpStr()
{
	return "assign";
}
string unaryExpr_node::getOpStr()
{
	
	return unary_op_dic[expr_operator];
}

string postfixExpr_node::getOpStr()
{
	if (postfixExpr_node::AR_OP == expr_operator || postfixExpr_node::DOT_OP == expr_operator)
	{
		return postfix_op_dic[expr_operator] + " " + memberName;
	}

	return postfix_op_dic[expr_operator];
}
string logicalOrExpr_node::getOpStr()
{
	return "logical or";
}
string logicalAndExpr_node::getOpStr()
{
	return "logical and";
}
string inclusiveOrExpr_node::getOpStr()
{
	return "inclusive or";
}
string exclusiveOrExpr_node::getOpStr()
{
	return "exclusive or";
}
string andExpr_node::getOpStr()
{
	return "and";
}

string equalityExpr_node::getOpStr()
{
	return equality_op_dic[expr_operator];
}
string relationalExpr_node::getOpStr()
{
	return relational_op_dic[expr_operator];
}
string shiftExpr_node::getOpStr()
{
	return shift_op_dic[expr_operator];
}


string additiveExpr_node::getOpStr()
{
	return additive_op_dic[expr_operator];
}


string multiplicativeExpr_node::getOpStr()
{
	return multiplicative_op_dic[expr_operator];
}


string primaryExpr_node::getOpStr()
{
	return primaryValue;
}