/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */
  
#include <stdio.h>  
#include <ctype.h>  
#include <cstring>
#include <math.h>
#include "frontEnd.h"
int yylex(void);
extern char* yytext;
int yyerror(char* s);

extern FILE *yyin, *yyout;
FILE* dout;


using namespace std;


AST_node* root;




#line 89 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_NUMBER = 258,
    FLOAT_NUMBER = 259,
    CHAR_LITERAL = 260,
    INT_TYPE = 261,
    FLOAT_TYPE = 262,
    CHAR_TYPE = 263,
    VOID_TYPE = 264,
    IDENTIFIER = 265,
    STRUCT = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    FOR = 270,
    CASE = 271,
    CONTINUE = 272,
    BREAK = 273,
    RETURN = 274,
    LOGICAL_AND_OP = 275,
    LOGICAL_OR_OP = 276,
    EQ_OP = 277,
    NE_OP = 278,
    LE_OP = 279,
    GE_OP = 280,
    INC_OP = 281,
    DEC_OP = 282,
    LSHIFT_OP = 283,
    RSHIFT_OP = 284,
    AR_OP = 285,
    STRING_LITERAL = 286,
    STAB = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "parser.ypp" /* yacc.c:355  */


	string* name;


	AST_node* AST_type;

#line 170 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 187 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,     2,    40,     2,
      36,    37,    41,    42,    38,    43,    49,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      52,    39,    53,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,    50,    34,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    80,    88,    92,   100,   111,   116,   127,
     134,   143,   152,   161,   170,   180,   188,   195,   199,   209,
     213,   220,   227,   233,   239,   245,   251,   257,   263,   274,
     283,   290,   297,   305,   314,   322,   328,   338,   343,   351,
     355,   363,   367,   374,   378,   385,   389,   397,   401,   410,
     414,   420,   429,   433,   439,   445,   451,   460,   464,   470,
     479,   483,   489,   498,   502,   508,   518,   522,   526,   530,
     539,   546,   553,   561,   569,   582,   593,   599,   608,   615,
     626,   631,   639,   647,   656,   663,   673,   679,   688,   694,
     701,   708,   712,   718,   732,   737,   738,   742,   743,   749,
     750,   757,   758,   763,   764,   769,   770,   774,   775,   776,
     781,   786,   787,   791,   792,   796,   797,   833,   838,   842,
     846,   850,   860,   864,   871,   876,   884,   888,   895,   899,
     907,   912,   920,   925,   930,   938,   943,   948,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_NUMBER", "FLOAT_NUMBER",
  "CHAR_LITERAL", "INT_TYPE", "FLOAT_TYPE", "CHAR_TYPE", "VOID_TYPE",
  "IDENTIFIER", "STRUCT", "IF", "ELSE", "WHILE", "FOR", "CASE", "CONTINUE",
  "BREAK", "RETURN", "LOGICAL_AND_OP", "LOGICAL_OR_OP", "EQ_OP", "NE_OP",
  "LE_OP", "GE_OP", "INC_OP", "DEC_OP", "LSHIFT_OP", "RSHIFT_OP", "AR_OP",
  "STRING_LITERAL", "STAB", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'='", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'@'", "'['", "']'",
  "'.'", "'|'", "'^'", "'<'", "'>'", "'/'", "$accept", "translation_unit",
  "external_declaration", "struct_declaration",
  "struct_var_declaration_list", "primary_expression", "expression",
  "assignment_expression", "unary_expression", "postfix_expression",
  "argument_expression_list", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "declaration", "type_specifier",
  "function_definition", "function_definition_declarator",
  "direct_function_definition_declarator", "parameter_declaration_list",
  "parameter_declaration", "var_declaration", "var_declarator_list",
  "init_var_declarator", "var_declarator", "direct_var_declarator",
  "function_declaration", "function_declarator_list",
  "function_declarator", "direct_function_declarator",
  "abstract_parameter_list", "abstract_parameter_declaration",
  "abstract_var_declaration", "abstract_var_declarator",
  "abstract_function_declaration", "abstract_function_declarator_list",
  "abstract_function_declarator", "direct_abstract_function_declarator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   123,   125,    59,    40,    41,    44,    61,
      38,    42,    43,    45,   126,    33,    64,    91,    93,    46,
     124,    94,    60,    62,    47
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     436,  -123,  -123,  -123,  -123,    30,  -123,    19,  -123,  -123,
    -123,    14,  -123,  -123,  -123,    36,  -123,  -123,    18,    31,
      99,    38,  -123,    51,  -123,    34,    59,    75,  -123,  -123,
     209,   117,  -123,    31,    77,   107,  -123,  -123,  -123,   195,
    -123,  -123,    31,   410,    13,  -123,    11,   128,    26,    31,
    -123,   122,    12,    57,  -123,   114,  -123,  -123,  -123,  -123,
     111,  -123,  -123,  -123,  -123,   121,   137,   183,   190,   199,
      39,   410,   410,  -123,  -123,  -123,   410,   410,   410,   410,
     410,   410,   410,   410,  -123,   136,  -123,   224,   431,   248,
     256,   246,   238,   268,   143,   171,   204,   225,     4,  -123,
     108,  -123,  -123,   239,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   265,  -123,   279,   307,  -123,  -123,   285,  -123,   123,
      21,   299,  -123,   318,   173,  -123,  -123,  -123,   209,  -123,
     209,   253,   410,   410,   327,  -123,  -123,  -123,   217,  -123,
    -123,   240,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
     410,   410,  -123,  -123,   371,   356,   410,   378,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   279,   131,  -123,  -123,  -123,
     337,  -123,  -123,   109,   254,    80,  -123,  -123,  -123,   410,
    -123,    52,    31,  -123,  -123,  -123,   266,   269,   381,   381,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,   274,    -2,  -123,
    -123,   256,   246,   238,   268,   143,   171,   171,   204,   204,
     204,   204,   225,   225,     4,     4,  -123,  -123,  -123,   369,
     258,  -123,  -123,   343,  -123,   283,   283,   410,   410,  -123,
     410,  -123,   -24,   376,  -123,   284,   312,  -123,   283,   283,
     283,  -123,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    72,    73,    71,    70,     0,    68,     0,     2,    69,
       5,     0,     4,    66,    67,    74,     1,     3,    90,     0,
       0,     0,    77,     0,    84,    87,    89,     0,    95,    98,
       0,     0,    90,     0,     0,     0,    76,    88,    97,     0,
      75,    83,     0,     0,     0,    94,     0,     0,     0,     0,
       8,   100,   109,     0,    80,     0,   101,   103,   104,    91,
      90,    10,    11,    13,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    12,   122,   128,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    15,    63,    19,    17,
      39,    41,    43,    45,    47,    49,    52,    57,    60,   126,
       0,   127,   117,     0,   124,   118,   119,   120,   121,    85,
      86,     0,    92,     0,     0,    96,    74,     0,     7,     0,
     109,     0,    82,   106,     0,   111,   114,    78,     0,    99,
       0,     0,     0,     0,     0,   135,   136,   137,     0,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,   129,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,   123,   125,    93,
       0,     6,   116,   109,     0,   109,   107,   113,   108,     0,
     110,     0,     0,    81,   102,    79,     0,     0,     0,     0,
     138,    14,    16,    18,    34,    31,    37,     0,     0,    33,
      63,    40,    42,    44,    46,    48,    50,    51,    55,    56,
      53,    54,    58,    59,    61,    62,    64,    65,   100,     0,
     109,   115,   105,     0,   112,     0,     0,     0,     0,    32,
       0,    30,   109,   131,   132,     0,     0,    38,     0,     0,
       0,   130,   134,   133
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   383,  -123,  -123,  -123,   -69,   -43,    20,  -123,
    -123,  -123,   236,   244,   235,   243,   247,   188,   174,   186,
     193,   -25,     8,  -123,   394,  -123,  -123,   282,   -19,  -123,
     -39,   -15,  -123,  -123,  -123,   365,   -18,  -109,   288,  -123,
     -46,  -123,  -123,   228,  -111,   -73,   407,  -123,   326,  -122,
    -123,  -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    48,    84,    85,    86,    87,    88,
     207,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    10,   183,    12,    36,    22,    53,    54,    13,    23,
      24,    25,    26,    14,    27,    28,    29,    55,    56,    57,
     186,    58,   124,   125,   126,   101,   102,   103,   104,   105,
     106,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     110,   138,    38,   109,    34,    37,   123,   141,    11,   187,
     184,    50,   199,   122,    99,    11,   111,   242,    37,    16,
      37,   113,    32,   121,    18,     1,     2,     3,     4,   118,
       5,    32,     1,     2,     3,     4,   150,    47,    49,    52,
      15,    32,    61,    62,    63,   173,   241,   100,   119,    64,
      19,     6,   114,   120,    31,    20,    49,   119,   174,   121,
     117,   112,   185,   196,   197,    71,    72,    19,   121,    30,
      73,    39,    33,    43,   137,    76,   237,   238,    99,    77,
      78,    79,    80,    81,    82,    83,    41,   208,   229,    42,
      32,   139,   140,   233,   127,   128,    38,   142,   143,   144,
     145,   146,   147,   148,    34,    37,    44,   202,   203,    18,
      45,   100,   206,    46,    59,   198,    19,    60,   175,   187,
     184,   185,   187,     1,     2,     3,     4,   121,    47,     1,
       2,     3,     4,    32,    47,    19,   192,   123,   116,   192,
      35,   175,    49,    19,    19,   229,   232,   131,    35,   176,
     230,   129,   130,   122,    51,   -79,   121,   132,    38,    19,
     182,    37,   243,   244,    33,   163,   164,    19,   245,   246,
      37,   149,    33,   133,   150,   251,   252,   253,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   226,   227,   165,   166,   247,    61,    62,
      63,     1,     2,     3,     4,    64,     5,    65,   190,    66,
      67,   191,    68,    69,    70,     1,     2,     3,     4,   134,
      47,    71,    72,   167,   168,   135,    73,     6,    39,    74,
      75,    76,   169,   170,   136,    77,    78,    79,    80,    81,
      82,    83,    61,    62,    63,     1,     2,     3,     4,    64,
       5,    65,   200,    66,    67,   150,    68,    69,    70,     1,
       2,     3,     4,   151,    47,    71,    72,   171,   172,   158,
      73,     6,    39,   177,    75,    76,   159,   201,   150,    77,
      78,    79,    80,    81,    82,    83,    61,    62,    63,   161,
     195,   231,   130,    64,   229,    65,   160,    66,    67,   242,
      68,    69,    70,   235,   150,   121,   236,   150,   162,    71,
      72,   239,   240,   179,    73,   180,    39,   113,    75,    76,
     181,   249,   150,    77,    78,    79,    80,    81,    82,    83,
      61,    62,    63,     1,     2,     3,     4,    64,    47,   218,
     219,   220,   221,     1,     2,     3,     4,   188,    47,   250,
     150,   216,   217,    71,    72,   222,   223,   189,    73,    61,
      62,    63,    75,    76,   224,   225,    64,    77,    78,    79,
      80,    81,    82,    83,   228,     1,     2,     3,     4,   229,
      47,   204,    71,    72,    61,    62,    63,    73,   209,   248,
      17,    64,    76,   205,   211,   213,    77,    78,    79,    80,
      81,    82,    83,   212,   214,    21,   182,    71,    72,   215,
     193,   115,    73,    61,    62,    63,    75,    76,   194,   234,
      64,    77,    78,    79,    80,    81,    82,    83,    40,   178,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,    73,     1,     2,     3,     4,    76,     5,     0,     0,
      77,    78,    79,    80,    81,    82,    83,   152,   153,     0,
       0,   154,     0,     0,     0,     0,     0,   155,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
     157
};

static const yytype_int16 yycheck[] =
{
      43,    70,    20,    42,    19,    20,    52,    76,     0,   120,
     119,    30,   134,    52,    39,     7,     3,    41,    33,     0,
      35,    10,    10,    47,    10,     6,     7,     8,     9,    48,
      11,    10,     6,     7,     8,     9,    38,    11,    30,    31,
      10,    10,     3,     4,     5,    41,    48,    39,    36,    10,
      36,    32,    41,    41,    36,    41,    48,    36,    54,    47,
      34,    48,    41,   132,   133,    26,    27,    36,    47,    33,
      31,    33,    41,    39,    35,    36,   198,   199,   103,    40,
      41,    42,    43,    44,    45,    46,    35,   156,    36,    38,
      10,    71,    72,    41,    37,    38,   114,    77,    78,    79,
      80,    81,    82,    83,   119,   120,    47,   150,   151,    10,
      35,   103,   155,    38,    37,   134,    36,    10,    10,   230,
     229,    41,   233,     6,     7,     8,     9,    47,    11,     6,
       7,     8,     9,    10,    11,    36,   128,   183,    10,   131,
      41,    10,   134,    36,    36,    36,   189,    36,    41,    41,
      41,    37,    38,   192,    37,    33,    47,    36,   176,    36,
      37,   176,   235,   236,    41,    22,    23,    36,   237,   238,
     185,    35,    41,    36,    38,   248,   249,   250,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    24,    25,   240,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    35,    14,
      15,    38,    17,    18,    19,     6,     7,     8,     9,    36,
      11,    26,    27,    52,    53,    35,    31,    32,    33,    34,
      35,    36,    28,    29,    35,    40,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    35,    14,    15,    38,    17,    18,    19,     6,
       7,     8,     9,    39,    11,    26,    27,    42,    43,    21,
      31,    32,    33,    34,    35,    36,    20,    37,    38,    40,
      41,    42,    43,    44,    45,    46,     3,     4,     5,    51,
      37,    37,    38,    10,    36,    12,    50,    14,    15,    41,
      17,    18,    19,    37,    38,    47,    37,    38,    40,    26,
      27,    37,    38,    48,    31,    36,    33,    10,    35,    36,
      35,    37,    38,    40,    41,    42,    43,    44,    45,    46,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   165,
     166,   167,   168,     6,     7,     8,     9,    48,    11,    37,
      38,   163,   164,    26,    27,   169,   170,    39,    31,     3,
       4,     5,    35,    36,   171,   172,    10,    40,    41,    42,
      43,    44,    45,    46,    37,     6,     7,     8,     9,    36,
      11,    10,    26,    27,     3,     4,     5,    31,    10,    13,
       7,    10,    36,    37,   158,   160,    40,    41,    42,    43,
      44,    45,    46,   159,   161,    11,    37,    26,    27,   162,
     128,    46,    31,     3,     4,     5,    35,    36,   130,   191,
      10,    40,    41,    42,    43,    44,    45,    46,    21,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    31,     6,     7,     8,     9,    36,    11,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    11,    32,    56,    57,    58,
      76,    77,    78,    83,    88,    10,     0,    57,    10,    36,
      41,    79,    80,    84,    85,    86,    87,    89,    90,    91,
      33,    36,    10,    41,    86,    41,    79,    86,    91,    33,
     101,    35,    38,    39,    47,    35,    38,    11,    59,    77,
      83,    37,    77,    81,    82,    92,    93,    94,    96,    37,
      10,     3,     4,     5,    10,    12,    14,    15,    17,    18,
      19,    26,    27,    31,    34,    35,    36,    40,    41,    42,
      43,    44,    45,    46,    60,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   100,   101,   102,   103,   104,   105,   106,   107,    85,
      62,     3,    48,    10,    41,    90,    10,    34,    83,    36,
      41,    47,    85,    95,    97,    98,    99,    37,    38,    37,
      38,    36,    36,    36,    36,    35,    35,    35,    61,    63,
      63,    61,    63,    63,    63,    63,    63,    63,    63,    35,
      38,    39,    26,    27,    30,    36,    47,    49,    21,    20,
      50,    51,    40,    22,    23,    24,    25,    52,    53,    28,
      29,    42,    43,    41,    54,    10,    41,    34,   103,    48,
      36,    35,    37,    77,    92,    41,    95,    99,    48,    39,
      35,    38,    77,    82,    93,    37,    61,    61,    83,   104,
      35,    37,    62,    62,    10,    37,    62,    65,    61,    10,
      63,    67,    68,    69,    70,    71,    72,    72,    73,    73,
      73,    73,    74,    74,    75,    75,    63,    63,    37,    36,
      41,    37,    62,    41,    98,    37,    37,   104,   104,    37,
      38,    48,    41,   100,   100,    61,    61,    62,    13,    37,
      37,   100,   100,   100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   107,   107,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     6,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     1,     4,     3,
       1,     3,     2,     3,     1,     3,     3,     1,     2,     1,
       1,     3,     3,     4,     3,     1,     3,     2,     1,     4,
       3,     1,     3,     1,     1,     4,     2,     2,     2,     0,
       3,     1,     3,     2,     1,     3,     2,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       7,     5,     5,     7,     7,     2,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new transUnit_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));

			root = (yyval.AST_type);

			root->height = 0;
		}
#line 1514 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-1].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1523 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1531 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "parser.ypp" /* yacc.c:1646  */
    {
			cerr << "do decl" << endl;
			auto tmp = new structDecl_node();
			tmp->name = *(yyvsp[-4].name);
			tmp->insertChild((yyvsp[-2].AST_type));
			(yyval.AST_type) = tmp;
		}
#line 1551 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "parser.ypp" /* yacc.c:1646  */
    {
			cerr << "collecting list" << endl;
			static_cast<structVarDeclList_node*>((yyvsp[-1].AST_type))->insertChild((yyvsp[0].AST_type));
		}
#line 1560 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "parser.ypp" /* yacc.c:1646  */
    {
			cerr << "vd" << endl;
			auto tmp = new structVarDeclList_node();
			tmp->insertChild((yyvsp[0].AST_type));
			(yyval.AST_type) = tmp;
		}
#line 1571 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new primaryExpr_node();
			tmp->primaryValue = *(yyvsp[0].name);
			tmp->valueType = primaryExpr_node::ID;
			(yyval.AST_type) = tmp;
		}
#line 1582 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new primaryExpr_node();
			tmp->primaryValue = *(yyvsp[0].name);
			tmp->valueType = primaryExpr_node::INT;
			//tmp->builtInType = builtInType_type::INT;
			//tmp->assignable = Expression_type::NO;
			(yyval.AST_type) = tmp;
		}
#line 1595 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 144 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new primaryExpr_node();
			tmp->primaryValue = *(yyvsp[0].name);
			tmp->valueType = primaryExpr_node::FLOAT;
			//tmp->builtInType = builtInType_type::FLOAT;
			//tmp->assignable = Expression::NO;
			(yyval.AST_type) = tmp;
		}
#line 1608 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new primaryExpr_node();
			tmp->primaryValue = *(yyvsp[0].name);
			tmp->valueType = primaryExpr_node::ID;
			//tmp->builtInType = builtInType_type::STRING;
			//tmp->assignable = Expression::NO;
			(yyval.AST_type) = tmp;
		}
#line 1621 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 162 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new primaryExpr_node();
			tmp->primaryValue = *(yyvsp[0].name);
			tmp->valueType = primaryExpr_node::CHAR;
			//tmp->builtInType = builtInType_type::CHAR;
			//tmp->assignable = Expression::NO;
			(yyval.AST_type) = tmp;
		}
#line 1634 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "parser.ypp" /* yacc.c:1646  */
    {
			/*$$ = new primaryExpr_node();
			$$->insertChild($2);*/
			(yyval.AST_type) = (yyvsp[-1].AST_type);
		}
#line 1644 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {
		/*
			$$ = new Expression_node();
			$$->insertChild($1);
			*/
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1656 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-2].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1665 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 196 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1673 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 200 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new assignExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1682 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1690 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {

			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::INC_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1701 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 221 "parser.ypp" /* yacc.c:1646  */
    {

			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::DEC_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1712 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::REF_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1722 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::IDR_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1732 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::PLUS_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1742 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::MINUS_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1752 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 252 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::CMPL_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1762 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 258 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::NEG_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1772 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 264 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new unaryExpr_node();
			static_cast<unaryExpr_node*>((yyval.AST_type))->expr_operator = unaryExpr_node::PRINT_OP;
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1782 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "parser.ypp" /* yacc.c:1646  */
    {
		/*
			$$ = new postfixExpr_node();
			static_cast<postfixExpr_node*>($$)->expr_operator = postfixExpr_node::NONE;
			$$->insertChild($1);
			*/
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1795 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 285 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-3].AST_type), (yyvsp[-1].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::SUBSCRIPT_OP;
		}
#line 1805 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 292 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::FUNC_CALL_OP;
		}
#line 1815 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 299 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-3].AST_type), (yyvsp[-1].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::FUNC_CALL_OP;

		}
#line 1826 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 307 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::DOT_OP;
			static_cast<postfixExpr_node*>((yyval.AST_type))->memberName = *(yyvsp[0].name);
		}
#line 1837 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 316 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::AR_OP;
			static_cast<postfixExpr_node*>((yyval.AST_type))->memberName = *(yyvsp[0].name);
		}
#line 1848 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::INC_OP;
		}
#line 1858 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 329 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new postfixExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type));
			static_cast<postfixExpr_node*>((yyval.AST_type))->expr_operator = postfixExpr_node::DEC_OP;
		}
#line 1868 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 339 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new argumentExprList_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1877 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 344 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-2].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 1886 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 352 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1894 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 356 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new logicalOrExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1903 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 364 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1911 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 368 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new logicalAndExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1920 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 375 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1928 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new inclusiveOrExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1937 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 386 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1945 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 390 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new exclusiveOrExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1954 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 398 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1962 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 402 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new andExpr_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1971 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 411 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 1979 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 415 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new equalityExpr_node();
			static_cast<equalityExpr_node*>((yyval.AST_type))->expr_operator = equalityExpr_node::EQ_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1989 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 421 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new equalityExpr_node();
			static_cast<equalityExpr_node*>((yyval.AST_type))->expr_operator = equalityExpr_node::NE_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 1999 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 430 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2007 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 434 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new relationalExpr_node();
			static_cast<relationalExpr_node*>((yyval.AST_type))->expr_operator = relationalExpr_node::L_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2017 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 440 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new relationalExpr_node();
			static_cast<relationalExpr_node*>((yyval.AST_type))->expr_operator = relationalExpr_node::G_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2027 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 446 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new relationalExpr_node();
			static_cast<relationalExpr_node*>((yyval.AST_type))->expr_operator = relationalExpr_node::LE_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2037 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 452 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new relationalExpr_node();
			static_cast<relationalExpr_node*>((yyval.AST_type))->expr_operator = relationalExpr_node::GE_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2047 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 461 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2055 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 465 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new shiftExpr_node();
			static_cast<shiftExpr_node*>((yyval.AST_type))->expr_operator = shiftExpr_node::LSHIFT_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2065 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 471 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new shiftExpr_node();
			static_cast<shiftExpr_node*>((yyval.AST_type))->expr_operator = shiftExpr_node::RSHIFT_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2075 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 480 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2083 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 484 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new additiveExpr_node();
			static_cast<additiveExpr_node*>((yyval.AST_type))->expr_operator = additiveExpr_node::ADD_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2093 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 490 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new additiveExpr_node();
			static_cast<additiveExpr_node*>((yyval.AST_type))->expr_operator = additiveExpr_node::SUB_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2103 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 499 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2111 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 503 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new multiplicativeExpr_node();
			static_cast<multiplicativeExpr_node*>((yyval.AST_type))->expr_operator = multiplicativeExpr_node::MUL_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2121 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 509 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new multiplicativeExpr_node();
			static_cast<multiplicativeExpr_node*>((yyval.AST_type))->expr_operator = multiplicativeExpr_node::DIV_OP;
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2131 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 519 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2139 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 523 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new funcDecl_node();
		}
#line 2147 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 527 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new showStab_node();
		}
#line 2155 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 531 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2163 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 540 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new typeSpec_node();
			tmp->type = typeSpec_node::BUILTIN;
			tmp->builtInType = typeSpec_node::VOID_TYPE;
			(yyval.AST_type) = tmp;
		}
#line 2174 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 547 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new typeSpec_node();
			tmp->type = typeSpec_node::BUILTIN;
			tmp->builtInType = typeSpec_node::CHAR_TYPE;
			(yyval.AST_type) = tmp;
		}
#line 2185 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 554 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new typeSpec_node();
			tmp->type = typeSpec_node::BUILTIN;
			tmp->builtInType = typeSpec_node::INT_TYPE;

			(yyval.AST_type) = tmp;
		}
#line 2197 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 562 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new typeSpec_node();
			tmp->type = typeSpec_node::BUILTIN;
			tmp->builtInType = typeSpec_node::FLOAT_TYPE;

			(yyval.AST_type) = tmp;
		}
#line 2209 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 570 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new typeSpec_node();

			tmp->type = typeSpec_node::STRUCT;
			tmp->name = (yyvsp[0].name);
			(yyval.AST_type) = tmp;
		}
#line 2221 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 585 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new funcDef_node();

			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[-1].AST_type), (yyvsp[0].AST_type));
		}
#line 2231 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 594 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
			static_cast<funcDefDeclarator_node*>((yyval.AST_type))->typeSpecifierList.push_back(*(new pointerSpecifier_type()));
		}
#line 2240 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 600 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2248 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 609 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new funcDefDeclarator_node();
 			static_cast<funcDefDeclarator_node*>((yyval.AST_type))->funcName = *(yyvsp[-3].name);
 			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type));
		}
#line 2258 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 616 "parser.ypp" /* yacc.c:1646  */
    {
 			(yyval.AST_type) = new funcDefDeclarator_node();
 			static_cast<funcDefDeclarator_node*>((yyval.AST_type))->funcName = *(yyvsp[-2].name);
 		}
#line 2267 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 627 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new paramDeclList_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2276 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 632 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-2].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2285 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 640 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new paramDecl_node();
			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type), (yyvsp[0].AST_type));
		}
#line 2294 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 648 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new varDecl_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[-1].AST_type));
		}
#line 2303 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 657 "parser.ypp" /* yacc.c:1646  */
    {

			(yyval.AST_type) = new varDeclaratorList_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));

		}
#line 2314 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 664 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-2].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2323 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 674 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new initVarDeclarator_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));

		}
#line 2333 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 681 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new initVarDeclarator_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2342 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 689 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
			static_cast<varDeclarator_node*>((yyval.AST_type))->typeSpecifierList.push_back(*(new pointerSpecifier_type()));
		}
#line 2351 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 695 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2359 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 702 "parser.ypp" /* yacc.c:1646  */
    {
			auto tmp = new varDeclarator_node();
			tmp->varName = *(yyvsp[0].name);
			(yyval.AST_type) = tmp;
			//delete $1;
		}
#line 2370 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 709 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-1].AST_type);
		}
#line 2378 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 713 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-2].AST_type);
			static_cast<varDeclarator_node*>((yyval.AST_type))->typeSpecifierList.push_back(*(new arraySpecifier_type()));
			
		}
#line 2388 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 719 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-3].AST_type);
			int length = atoi((yyvsp[-1].name)->c_str());
			auto ts = (new arraySpecifier_type());
			ts->length = length;
			static_cast<varDeclarator_node*>((yyval.AST_type))->typeSpecifierList.push_back(*ts);
			
		}
#line 2401 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 834 "parser.ypp" /* yacc.c:1646  */
    {
			
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2410 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 839 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2418 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 843 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2426 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 847 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2434 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 851 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);

		}
#line 2443 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 861 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new compoundStmt_node();
		}
#line 2451 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 865 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-1].AST_type);
		}
#line 2459 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 872 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new compoundStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2468 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 877 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[-1].AST_type);
			(yyval.AST_type)->insertChild((yyvsp[0].AST_type));
		}
#line 2477 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 885 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 889 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = (yyvsp[0].AST_type);
		}
#line 2493 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 896 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new expressionStmt_node();
		}
#line 2501 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 900 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new expressionStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type));
		}
#line 2510 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 908 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new selectionStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-4].AST_type), (yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2519 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 913 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new selectionStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2528 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 921 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new iterationStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2537 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 926 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new iterationStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-4].AST_type), (yyvsp[-3].AST_type), (yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2546 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 931 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new iterationStmt_node();
			(yyval.AST_type)->insertChild((yyvsp[-4].AST_type), (yyvsp[-3].AST_type), (yyvsp[-2].AST_type), (yyvsp[0].AST_type));
		}
#line 2555 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 939 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new jumpStmt_node();
			static_cast<jumpStmt_node*>((yyval.AST_type))->jump_type = jumpStmt_node::CONTINUE;
		}
#line 2564 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 944 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new jumpStmt_node();
			static_cast<jumpStmt_node*>((yyval.AST_type))->jump_type = jumpStmt_node::BREAK;
		}
#line 2573 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 949 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new jumpStmt_node();
			static_cast<jumpStmt_node*>((yyval.AST_type))->jump_type = jumpStmt_node::RETURN;
		}
#line 2582 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 954 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.AST_type) = new jumpStmt_node();
			static_cast<jumpStmt_node*>((yyval.AST_type))->jump_type = jumpStmt_node::RETURN;
			(yyval.AST_type)->insertChild((yyvsp[-1].AST_type));
		}
#line 2592 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2596 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 962 "parser.ypp" /* yacc.c:1906  */
  

int yyerror(char* s) 
{  
    fprintf(stderr, "%s\n", s);  
    return 1;  
}  
  

int main(int argc, char* argv[]) 
{  

	if (argc > 1)
	{
		yyin = fopen(argv[1], "r");
	}
	dout = fopen("debug_out", "w");
    yyparse();

    cout << "parse done" << endl;
    
    frontEnd fe(root);

    fe.start();

    cout << "all done" << endl;

}  
  
