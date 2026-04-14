/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_num;
void yyerror(const char* s);

ASTNode* root;

#line 85 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_FN = 12,                        /* FN  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_TYPE = 14,                      /* TYPE  */
  YYSYMBOL_MOD = 15,                       /* MOD  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_MULT = 19,                      /* MULT  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_INC = 29,                       /* INC  */
  YYSYMBOL_DEC = 30,                       /* DEC  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_ADD_ASSIGN = 32,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 33,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 34,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 35,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 36,                /* MOD_ASSIGN  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_THEN = 43,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_statement_list = 46,            /* statement_list  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_var_decl = 48,                  /* var_decl  */
  YYSYMBOL_declarator_list = 49,           /* declarator_list  */
  YYSYMBOL_declarator = 50,                /* declarator  */
  YYSYMBOL_assignment = 51,                /* assignment  */
  YYSYMBOL_if_stmt = 52,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 53,                /* while_stmt  */
  YYSYMBOL_for_stmt = 54,                  /* for_stmt  */
  YYSYMBOL_update = 55,                    /* update  */
  YYSYMBOL_print_stmt = 56,                /* print_stmt  */
  YYSYMBOL_func_decl = 57,                 /* func_decl  */
  YYSYMBOL_params = 58,                    /* params  */
  YYSYMBOL_return_stmt = 59,               /* return_stmt  */
  YYSYMBOL_block = 60,                     /* block  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_unary = 63,                     /* unary  */
  YYSYMBOL_factor = 64,                    /* factor  */
  YYSYMBOL_func_call = 65,                 /* func_call  */
  YYSYMBOL_args = 66                       /* args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    46,    51,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    73,    74,    78,    79,    83,
      84,    88,    91,    95,    99,   102,   105,   108,   111,   117,
     120,   126,   132,   137,   145,   148,   151,   157,   163,   166,
     172,   173,   174,   177,   178,   184,   190,   193,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   213,
     214,   215,   216,   220,   221,   222,   226,   227,   228,   229,
     230,   234,   240,   241,   242
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "NUMBER",
  "STRING_LITERAL", "LET", "IF", "ELSE", "WHILE", "PRINT", "RETURN", "FN",
  "FOR", "TYPE", "MOD", "ASSIGN", "PLUS", "MINUS", "MULT", "DIV", "LT",
  "GT", "EQ", "NE", "LE", "GE", "AND", "OR", "INC", "DEC", "NOT",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "THEN",
  "$accept", "program", "statement_list", "statement", "var_decl",
  "declarator_list", "declarator", "assignment", "if_stmt", "while_stmt",
  "for_stmt", "update", "print_stmt", "func_decl", "params", "return_stmt",
  "block", "expression", "term", "unary", "factor", "func_call", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,   315,     9,    -1,     3,     7,    12,    43,    10,    45,
      56,    28,  -129,    68,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,    16,    12,    17,    32,    12,    12,    12,
      12,    12,    12,    60,    42,    44,    12,    12,    12,    47,
    -129,  -129,    12,    12,    12,    98,    41,  -129,  -129,  -129,
      48,    31,   -10,    46,  -129,    49,  -129,  -129,  -129,   110,
    -129,  -129,   137,   149,   170,   182,   203,    76,    50,    12,
    -129,     9,   248,   266,   284,  -129,  -129,   302,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,  -129,    12,
      12,    12,    15,   325,     9,    12,    12,    15,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,    12,  -129,   345,  -129,
      68,    68,    51,  -129,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,  -129,  -129,  -129,    63,   103,    70,
     215,   236,    71,  -129,   104,  -129,  -129,    15,    72,    74,
     114,   114,    74,    68,  -129,    15,  -129,    -9,    91,    92,
    -129,  -129,  -129,    12,  -129,  -129,    68,    68,   345,  -129,
    -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     5,     6,     7,     8,    12,     9,
      10,    11,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    19,     0,    17,     0,     0,     0,    68,
      66,    67,     0,     0,     0,     0,    48,    59,    63,    69,
       0,     0,    19,     0,    47,     0,     1,     4,    13,     0,
      22,    23,     0,     0,     0,     0,     0,    73,     0,     0,
      15,     0,     0,     0,     0,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,    40,     0,     0,     0,     0,    40,    16,    46,
      21,    24,    25,    26,    27,    28,    72,    71,    20,    18,
       0,     0,     0,    70,    49,    50,    51,    52,    55,    56,
      53,    54,    57,    58,    62,    60,    61,    41,     0,     0,
       0,     0,     0,    74,    29,    31,    37,    40,    43,     0,
       0,     0,     0,     0,    42,    40,    38,     0,     0,     0,
      39,    30,    44,     0,    35,    36,     0,     0,    34,    32,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,    25,  -102,    89,     1,  -129,    90,  -129,  -129,
    -129,     4,  -129,  -129,   -95,  -129,  -128,    -5,   296,   -38,
    -129,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    53,    35,    15,    16,    17,
      18,   148,    19,    20,   129,    21,    22,    67,    46,    47,
      48,    49,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    45,   132,    34,    75,    76,    69,   153,   134,   135,
      23,   146,    33,    23,   150,    39,    40,    41,   127,    59,
     154,   155,    62,    63,    64,    65,    66,    97,    56,   128,
      42,    72,    73,    74,    93,    55,    36,     2,    57,    77,
      37,   151,   144,    43,    38,    94,    50,    51,    52,    44,
     152,   124,   125,   126,   159,   160,    89,    58,    60,     1,
      90,    91,     2,     3,   108,     4,     5,     6,     7,     8,
       9,     1,   109,    61,     2,     3,    69,     4,     5,     6,
       7,     8,     9,    70,    32,    92,    71,    98,   107,    99,
     130,   131,   136,    78,    79,    10,    54,    80,    81,    82,
      83,    84,    85,    86,    87,   137,   138,    10,   139,   142,
      23,    23,   143,    10,   145,    78,    79,   147,   106,    80,
      81,    82,    83,    84,    85,    86,    87,    78,    79,   156,
     157,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      95,    96,   133,    23,     0,   149,     0,     0,   158,     0,
       0,   100,     0,     0,    78,    79,    23,    23,    80,    81,
      82,    83,    84,    85,    86,    87,    78,    79,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,   101,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
     102,    80,    81,    82,    83,    84,    85,    86,    87,    78,
      79,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,   103,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,     0,   104,    80,    81,    82,    83,    84,    85,
      86,    87,    78,    79,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,   105,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,     0,   140,    80,    81,    82,
      83,    84,    85,    86,    87,    78,    79,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,   141,     0,     0,
       0,     0,     0,    78,    79,     0,   110,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,    78,    79,     0,   111,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    78,
      79,     0,   112,    80,    81,    82,    83,    84,    85,    86,
      87,    24,     0,     0,     0,     0,     0,     0,     0,     0,
     113,    24,     0,     0,    25,    26,     0,    27,    28,    29,
      30,    31,    32,     0,    25,    26,     0,    27,    28,    29,
      30,    31,    78,    79,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123
};

static const yytype_int16 yycheck[] =
{
       0,     6,    97,     2,    42,    43,    16,    16,   110,   111,
      10,   139,     3,    13,   142,     3,     4,     5,     3,    24,
      29,    30,    27,    28,    29,    30,    31,    37,     0,    14,
      18,    36,    37,    38,     3,    10,    37,     6,    13,    44,
      37,   143,   137,    31,    37,    14,     3,    37,     3,    37,
     145,    89,    90,    91,   156,   157,    15,    41,    41,     3,
      19,    20,     6,     7,    69,     9,    10,    11,    12,    13,
      14,     3,    71,    41,     6,     7,    16,     9,    10,    11,
      12,    13,    14,    41,    37,    37,    42,    41,    38,    40,
      95,    96,    41,    17,    18,    39,    40,    21,    22,    23,
      24,    25,    26,    27,    28,    42,     3,    39,    38,    38,
     110,   111,     8,    39,    42,    17,    18,     3,    42,    21,
      22,    23,    24,    25,    26,    27,    28,    17,    18,    38,
      38,    21,    22,    23,    24,    25,    26,    27,    28,    41,
      51,    51,   106,   143,    -1,   141,    -1,    -1,   153,    -1,
      -1,    41,    -1,    -1,    17,    18,   156,   157,    21,    22,
      23,    24,    25,    26,    27,    28,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      41,    21,    22,    23,    24,    25,    26,    27,    28,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    41,    21,    22,    23,    24,    25,    26,
      27,    28,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    41,    21,    22,    23,
      24,    25,    26,    27,    28,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    38,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    38,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    38,    21,    22,    23,    24,    25,    26,    27,
      28,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    16,    -1,    -1,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    -1,    29,    30,    -1,    32,    33,    34,
      35,    36,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     9,    10,    11,    12,    13,    14,
      39,    45,    46,    47,    48,    51,    52,    53,    54,    56,
      57,    59,    60,    65,    16,    29,    30,    32,    33,    34,
      35,    36,    37,     3,    49,    50,    37,    37,    37,     3,
       4,     5,    18,    31,    37,    61,    62,    63,    64,    65,
       3,    37,     3,    49,    40,    46,     0,    46,    41,    61,
      41,    41,    61,    61,    61,    61,    61,    61,    66,    16,
      41,    42,    61,    61,    61,    63,    63,    61,    17,    18,
      21,    22,    23,    24,    25,    26,    27,    28,    41,    15,
      19,    20,    37,     3,    14,    48,    51,    37,    41,    40,
      41,    41,    41,    41,    41,    41,    42,    38,    61,    49,
      38,    38,    38,    38,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,     3,    14,    58,
      61,    61,    58,    66,    47,    47,    41,    42,     3,    38,
      41,    41,    38,     8,    58,    42,    60,     3,    55,    55,
      60,    47,    58,    16,    29,    30,    38,    38,    61,    47,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    55,    56,    57,    57,
      58,    58,    58,    58,    58,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     1,     3,     1,
       3,     4,     3,     3,     4,     4,     4,     4,     4,     5,
       7,     5,     8,     8,     3,     2,     2,     5,     6,     6,
       0,     1,     3,     2,     4,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       3,     4,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: statement_list  */
#line 42 "parser.y"
                   { root = create_node(NODE_PROGRAM, NULL, (yyvsp[0].nval), NULL, NULL); }
#line 1285 "parser.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 46 "parser.y"
              { 
        ASTNode* last = (yyvsp[0].nval);
        while (last->next) last = last->next;
        (yyval.nval) = (yyvsp[0].nval); 
    }
#line 1295 "parser.tab.c"
    break;

  case 4: /* statement_list: statement statement_list  */
#line 51 "parser.y"
                               { 
        ASTNode* last = (yyvsp[-1].nval);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].nval); 
        (yyval.nval) = (yyvsp[-1].nval); 
    }
#line 1306 "parser.tab.c"
    break;

  case 5: /* statement: var_decl  */
#line 60 "parser.y"
             { (yyval.nval) = (yyvsp[0].nval); }
#line 1312 "parser.tab.c"
    break;

  case 6: /* statement: assignment  */
#line 61 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1318 "parser.tab.c"
    break;

  case 7: /* statement: if_stmt  */
#line 62 "parser.y"
              { (yyval.nval) = (yyvsp[0].nval); }
#line 1324 "parser.tab.c"
    break;

  case 8: /* statement: while_stmt  */
#line 63 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1330 "parser.tab.c"
    break;

  case 9: /* statement: print_stmt  */
#line 64 "parser.y"
                 { (yyval.nval) = (yyvsp[0].nval); }
#line 1336 "parser.tab.c"
    break;

  case 10: /* statement: func_decl  */
#line 65 "parser.y"
                { (yyval.nval) = (yyvsp[0].nval); }
#line 1342 "parser.tab.c"
    break;

  case 11: /* statement: return_stmt  */
#line 66 "parser.y"
                  { (yyval.nval) = (yyvsp[0].nval); }
#line 1348 "parser.tab.c"
    break;

  case 12: /* statement: for_stmt  */
#line 67 "parser.y"
               { (yyval.nval) = (yyvsp[0].nval); }
#line 1354 "parser.tab.c"
    break;

  case 13: /* statement: func_call SEMICOLON  */
#line 68 "parser.y"
                          { (yyval.nval) = (yyvsp[-1].nval); }
#line 1360 "parser.tab.c"
    break;

  case 14: /* statement: block  */
#line 69 "parser.y"
            { (yyval.nval) = (yyvsp[0].nval); }
#line 1366 "parser.tab.c"
    break;

  case 15: /* var_decl: LET declarator_list SEMICOLON  */
#line 73 "parser.y"
                                  { (yyval.nval) = (yyvsp[-1].nval); }
#line 1372 "parser.tab.c"
    break;

  case 16: /* var_decl: TYPE declarator_list SEMICOLON  */
#line 74 "parser.y"
                                     { (yyval.nval) = (yyvsp[-1].nval); }
#line 1378 "parser.tab.c"
    break;

  case 17: /* declarator_list: declarator  */
#line 78 "parser.y"
               { (yyval.nval) = (yyvsp[0].nval); }
#line 1384 "parser.tab.c"
    break;

  case 18: /* declarator_list: declarator COMMA declarator_list  */
#line 79 "parser.y"
                                       { (yyvsp[-2].nval)->next = (yyvsp[0].nval); (yyval.nval) = (yyvsp[-2].nval); }
#line 1390 "parser.tab.c"
    break;

  case 19: /* declarator: IDENTIFIER  */
#line 83 "parser.y"
               { (yyval.nval) = create_node(NODE_VAR_DECL, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1396 "parser.tab.c"
    break;

  case 20: /* declarator: IDENTIFIER ASSIGN expression  */
#line 84 "parser.y"
                                   { (yyval.nval) = create_node(NODE_VAR_DECL, (yyvsp[-2].sval), (yyvsp[0].nval), NULL, NULL); }
#line 1402 "parser.tab.c"
    break;

  case 21: /* assignment: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 88 "parser.y"
                                           {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), (yyvsp[-1].nval), NULL, NULL);
    }
#line 1410 "parser.tab.c"
    break;

  case 22: /* assignment: IDENTIFIER INC SEMICOLON  */
#line 91 "parser.y"
                               {
        /* Pseudo-assignment for x++ */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-2].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1419 "parser.tab.c"
    break;

  case 23: /* assignment: IDENTIFIER DEC SEMICOLON  */
#line 95 "parser.y"
                               {
        /* Pseudo-assignment for x-- */
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-2].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1428 "parser.tab.c"
    break;

  case 24: /* assignment: IDENTIFIER ADD_ASSIGN expression SEMICOLON  */
#line 99 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1436 "parser.tab.c"
    break;

  case 25: /* assignment: IDENTIFIER SUB_ASSIGN expression SEMICOLON  */
#line 102 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1444 "parser.tab.c"
    break;

  case 26: /* assignment: IDENTIFIER MUL_ASSIGN expression SEMICOLON  */
#line 105 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "*", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1452 "parser.tab.c"
    break;

  case 27: /* assignment: IDENTIFIER DIV_ASSIGN expression SEMICOLON  */
#line 108 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "/", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1460 "parser.tab.c"
    break;

  case 28: /* assignment: IDENTIFIER MOD_ASSIGN expression SEMICOLON  */
#line 111 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-3].sval), create_node(NODE_BINARY_OP, "%", create_node(NODE_IDENTIFIER, (yyvsp[-3].sval), NULL, NULL, NULL), NULL, (yyvsp[-1].nval)), NULL, NULL);
    }
#line 1468 "parser.tab.c"
    break;

  case 29: /* if_stmt: IF LPAREN expression RPAREN statement  */
#line 117 "parser.y"
                                                     {
        (yyval.nval) = create_node(NODE_IF, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1476 "parser.tab.c"
    break;

  case 30: /* if_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 120 "parser.y"
                                                           {
        (yyval.nval) = create_node(NODE_IF, NULL, (yyvsp[-4].nval), (yyvsp[-2].nval), (yyvsp[0].nval));
    }
#line 1484 "parser.tab.c"
    break;

  case 31: /* while_stmt: WHILE LPAREN expression RPAREN statement  */
#line 126 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_WHILE, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1492 "parser.tab.c"
    break;

  case 32: /* for_stmt: FOR LPAREN var_decl expression SEMICOLON update RPAREN statement  */
#line 132 "parser.y"
                                                                     {
        /* var_decl already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
        (yyval.nval) = create_node(NODE_FOR, NULL, (yyvsp[-5].nval), (yyvsp[-4].nval), tail);
    }
#line 1502 "parser.tab.c"
    break;

  case 33: /* for_stmt: FOR LPAREN assignment expression SEMICOLON update RPAREN statement  */
#line 137 "parser.y"
                                                                         {
        /* assignment already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
        (yyval.nval) = create_node(NODE_FOR, NULL, (yyvsp[-5].nval), (yyvsp[-4].nval), tail);
    }
#line 1512 "parser.tab.c"
    break;

  case 34: /* update: IDENTIFIER ASSIGN expression  */
#line 145 "parser.y"
                                 {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-2].sval), (yyvsp[0].nval), NULL, NULL);
    }
#line 1520 "parser.tab.c"
    break;

  case 35: /* update: IDENTIFIER INC  */
#line 148 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1528 "parser.tab.c"
    break;

  case 36: /* update: IDENTIFIER DEC  */
#line 151 "parser.y"
                     {
        (yyval.nval) = create_node(NODE_ASSIGN, (yyvsp[-1].sval), create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, (yyvsp[-1].sval), NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
#line 1536 "parser.tab.c"
    break;

  case 37: /* print_stmt: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 157 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_PRINT, NULL, (yyvsp[-2].nval), NULL, NULL);
    }
#line 1544 "parser.tab.c"
    break;

  case 38: /* func_decl: FN IDENTIFIER LPAREN params RPAREN block  */
#line 163 "parser.y"
                                             {
        (yyval.nval) = create_node(NODE_FUNC_DECL, (yyvsp[-4].sval), (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1552 "parser.tab.c"
    break;

  case 39: /* func_decl: TYPE IDENTIFIER LPAREN params RPAREN block  */
#line 166 "parser.y"
                                                 {
        (yyval.nval) = create_node(NODE_FUNC_DECL, (yyvsp[-4].sval), (yyvsp[-2].nval), (yyvsp[0].nval), NULL);
    }
#line 1560 "parser.tab.c"
    break;

  case 40: /* params: %empty  */
#line 172 "parser.y"
                { (yyval.nval) = NULL; }
#line 1566 "parser.tab.c"
    break;

  case 41: /* params: IDENTIFIER  */
#line 173 "parser.y"
                 { (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1572 "parser.tab.c"
    break;

  case 42: /* params: IDENTIFIER COMMA params  */
#line 174 "parser.y"
                              {
        (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[-2].sval), NULL, NULL, (yyvsp[0].nval));
    }
#line 1580 "parser.tab.c"
    break;

  case 43: /* params: TYPE IDENTIFIER  */
#line 177 "parser.y"
                      { (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1586 "parser.tab.c"
    break;

  case 44: /* params: TYPE IDENTIFIER COMMA params  */
#line 178 "parser.y"
                                   {
        (yyval.nval) = create_node(NODE_PARAM_LIST, (yyvsp[-2].sval), NULL, NULL, (yyvsp[0].nval));
    }
#line 1594 "parser.tab.c"
    break;

  case 45: /* return_stmt: RETURN expression SEMICOLON  */
#line 184 "parser.y"
                                {
        (yyval.nval) = create_node(NODE_RETURN, NULL, (yyvsp[-1].nval), NULL, NULL);
    }
#line 1602 "parser.tab.c"
    break;

  case 46: /* block: LBRACE statement_list RBRACE  */
#line 190 "parser.y"
                                 {
        (yyval.nval) = create_node(NODE_BLOCK, NULL, (yyvsp[-1].nval), NULL, NULL);
    }
#line 1610 "parser.tab.c"
    break;

  case 47: /* block: LBRACE RBRACE  */
#line 193 "parser.y"
                    {
        (yyval.nval) = create_node(NODE_BLOCK, NULL, NULL, NULL, NULL);
    }
#line 1618 "parser.tab.c"
    break;

  case 48: /* expression: term  */
#line 199 "parser.y"
         { (yyval.nval) = (yyvsp[0].nval); }
#line 1624 "parser.tab.c"
    break;

  case 49: /* expression: expression PLUS term  */
#line 200 "parser.y"
                           { (yyval.nval) = create_node(NODE_BINARY_OP, "+", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1630 "parser.tab.c"
    break;

  case 50: /* expression: expression MINUS term  */
#line 201 "parser.y"
                            { (yyval.nval) = create_node(NODE_BINARY_OP, "-", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1636 "parser.tab.c"
    break;

  case 51: /* expression: expression LT term  */
#line 202 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "<", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1642 "parser.tab.c"
    break;

  case 52: /* expression: expression GT term  */
#line 203 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, ">", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1648 "parser.tab.c"
    break;

  case 53: /* expression: expression LE term  */
#line 204 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "<=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1654 "parser.tab.c"
    break;

  case 54: /* expression: expression GE term  */
#line 205 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, ">=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1660 "parser.tab.c"
    break;

  case 55: /* expression: expression EQ term  */
#line 206 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "==", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1666 "parser.tab.c"
    break;

  case 56: /* expression: expression NE term  */
#line 207 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "!=", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1672 "parser.tab.c"
    break;

  case 57: /* expression: expression AND term  */
#line 208 "parser.y"
                          { (yyval.nval) = create_node(NODE_BINARY_OP, "&&", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1678 "parser.tab.c"
    break;

  case 58: /* expression: expression OR term  */
#line 209 "parser.y"
                         { (yyval.nval) = create_node(NODE_BINARY_OP, "||", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1684 "parser.tab.c"
    break;

  case 59: /* term: unary  */
#line 213 "parser.y"
          { (yyval.nval) = (yyvsp[0].nval); }
#line 1690 "parser.tab.c"
    break;

  case 60: /* term: term MULT unary  */
#line 214 "parser.y"
                      { (yyval.nval) = create_node(NODE_BINARY_OP, "*", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1696 "parser.tab.c"
    break;

  case 61: /* term: term DIV unary  */
#line 215 "parser.y"
                     { (yyval.nval) = create_node(NODE_BINARY_OP, "/", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1702 "parser.tab.c"
    break;

  case 62: /* term: term MOD unary  */
#line 216 "parser.y"
                     { (yyval.nval) = create_node(NODE_BINARY_OP, "%", (yyvsp[-2].nval), NULL, (yyvsp[0].nval)); }
#line 1708 "parser.tab.c"
    break;

  case 63: /* unary: factor  */
#line 220 "parser.y"
           { (yyval.nval) = (yyvsp[0].nval); }
#line 1714 "parser.tab.c"
    break;

  case 64: /* unary: MINUS unary  */
#line 221 "parser.y"
                  { (yyval.nval) = create_node(NODE_UNARY_OP, "-", (yyvsp[0].nval), NULL, NULL); }
#line 1720 "parser.tab.c"
    break;

  case 65: /* unary: NOT unary  */
#line 222 "parser.y"
                { (yyval.nval) = create_node(NODE_UNARY_OP, "!", (yyvsp[0].nval), NULL, NULL); }
#line 1726 "parser.tab.c"
    break;

  case 66: /* factor: NUMBER  */
#line 226 "parser.y"
           { (yyval.nval) = create_node(NODE_NUMBER, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1732 "parser.tab.c"
    break;

  case 67: /* factor: STRING_LITERAL  */
#line 227 "parser.y"
                     { (yyval.nval) = create_node(NODE_STRING, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1738 "parser.tab.c"
    break;

  case 68: /* factor: IDENTIFIER  */
#line 228 "parser.y"
                 { (yyval.nval) = create_node(NODE_IDENTIFIER, (yyvsp[0].sval), NULL, NULL, NULL); }
#line 1744 "parser.tab.c"
    break;

  case 69: /* factor: func_call  */
#line 229 "parser.y"
                { (yyval.nval) = (yyvsp[0].nval); }
#line 1750 "parser.tab.c"
    break;

  case 70: /* factor: LPAREN expression RPAREN  */
#line 230 "parser.y"
                               { (yyval.nval) = (yyvsp[-1].nval); }
#line 1756 "parser.tab.c"
    break;

  case 71: /* func_call: IDENTIFIER LPAREN args RPAREN  */
#line 234 "parser.y"
                                  {
        (yyval.nval) = create_node(NODE_CALL, (yyvsp[-3].sval), (yyvsp[-1].nval), NULL, NULL);
    }
#line 1764 "parser.tab.c"
    break;

  case 72: /* args: %empty  */
#line 240 "parser.y"
                { (yyval.nval) = NULL; }
#line 1770 "parser.tab.c"
    break;

  case 73: /* args: expression  */
#line 241 "parser.y"
                 { (yyval.nval) = create_node(NODE_ARG_LIST, NULL, (yyvsp[0].nval), NULL, NULL); }
#line 1776 "parser.tab.c"
    break;

  case 74: /* args: expression COMMA args  */
#line 242 "parser.y"
                            {
        (yyval.nval) = create_node(NODE_ARG_LIST, NULL, (yyvsp[-2].nval), NULL, (yyvsp[0].nval));
    }
#line 1784 "parser.tab.c"
    break;


#line 1788 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 247 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}
