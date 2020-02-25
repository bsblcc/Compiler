%{
  #include <stdio.h>
  #include <stdlib.h>

  
  #include "AST.h"


  #include "parser.tab.hpp"
  void start_comment();
  extern int yyerror(char* s);
  
%}




INTEGER_NUMBER       [1-9][0-9]*|[0]

FLOAT_NUMBER         [1-9][0-9]*|[0][.][0-9][0-9]*



WS            [ \t\v\n\f]

IDENTIFIER    [a-zA-Z_][a-zA-Z_0-9]*
STRING_LITERAL		  \"(\\.|[^"\\])*\"

CHAR_LITERAL            \'([^']|(\'))*\'

COMMENT_BLOCK      "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
COMMENT_LINE		"//"[^\n]*
%%

{COMMENT_BLOCK}			{;}
{COMMENT_LINE}			{;}
{INTEGER_NUMBER}       {
                        string* tmp = new string;
                        *tmp = yytext;

                        yylval.name = tmp;
                        return INTEGER_NUMBER;
                      }
{STRING_LITERAL}                {
                        string* tmp = new string;
                        *tmp = yytext;

                        yylval.name = tmp;
                        return STRING_LITERAL;
                      }

{CHAR_LITERAL}              {
                      string *tmp = new string;
                      *tmp = yytext;
                      yylval.name = tmp;
                      return CHAR_LITERAL;
                    }

{FLOAT_NUMBER}         {
                        string* tmp = new string;
                        *tmp = yytext;

                        yylval.name = tmp;
                        return FLOAT_NUMBER;
                      }
"int"      		{return INT_TYPE;}
"float"    		{return FLOAT_TYPE;}
"void"			{return VOID_TYPE;}
"char"			{return CHAR_TYPE;}
"="     		{return '=';}
"+"        		{ return '+';}
"-"        		{return '-';}
"*"          	{return '*';}
"/"        		{return '/';}
"&&"        	{return LOGICAL_AND_OP;}
"||"        	{return LOGICAL_OR_OP;}
"++"			{return INC_OP;}
"--"			{return DEC_OP;}
"->"			{return AR_OP;}
">>"			{return RSHIFT_OP;}
"<<"			{return LSHIFT_OP;}
"!"        		{return '!';}
"|"				{return '|';}
"&"				{return '&';}
"^"				{return '^';}
";"         	{ return ';';}
","         	{return ',';}
":"				{return ':';}
"."           	{return '.';}
"("            	{return '(';}
")"            	{return ')';}
"{"            	{return '{';}
"}"            	{return '}';}
"["            	{return '[';}
"]"            	{return ']';}
"@"     {return '@';}
"~"				{return '~';}
">"				{return '>';}
"<"				{return '<';}
">="			{return GE_OP;}
"<="			{return LE_OP;}
"=="			{ return EQ_OP;}
"!="			{return NE_OP;}
"struct"        {return STRUCT;}
"return"        {return RETURN;}
"if"            {return IF;}
"else"          {return ELSE;}
"while"         {return WHILE;}
"for"          	{return FOR;}

"continue"		{return CONTINUE;}
"break"  		{return BREAK;}

"#stab"			{return STAB;}

{IDENTIFIER}    {
					string* tmp = new string;
					*tmp = yytext;

					yylval.name = tmp;


					return IDENTIFIER;

				}
{WS}+			{;}
%%



int yywrap() {

  return 1;
}

