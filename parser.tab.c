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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *outf;

/* helper para emitir linhas no out.asm */
void emitf(const char *fmt, ...);

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
  YYSYMBOL_CLIENTE = 3,                    /* CLIENTE  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_TIPO_KW = 6,                    /* TIPO_KW  */
  YYSYMBOL_PESO_KW = 7,                    /* PESO_KW  */
  YYSYMBOL_BEBIDAS_KW = 8,                 /* BEBIDAS_KW  */
  YYSYMBOL_SOBREMESAS_KW = 9,              /* SOBREMESAS_KW  */
  YYSYMBOL_ADICIONAR_ITEM = 10,            /* ADICIONAR_ITEM  */
  YYSYMBOL_CALCULAR_PESO = 11,             /* CALCULAR_PESO  */
  YYSYMBOL_FECHAR_CONTA = 12,              /* FECHAR_CONTA  */
  YYSYMBOL_MOSTRAR = 13,                   /* MOSTRAR  */
  YYSYMBOL_SE = 14,                        /* SE  */
  YYSYMBOL_ENTAO = 15,                     /* ENTAO  */
  YYSYMBOL_SENAO = 16,                     /* SENAO  */
  YYSYMBOL_REPETIR = 17,                   /* REPETIR  */
  YYSYMBOL_VEZES = 18,                     /* VEZES  */
  YYSYMBOL_CLIENTE_ATTR = 19,              /* CLIENTE_ATTR  */
  YYSYMBOL_SISTEMA_ATTR = 20,              /* SISTEMA_ATTR  */
  YYSYMBOL_SELF_SERVICE = 21,              /* SELF_SERVICE  */
  YYSYMBOL_RODIZIO = 22,                   /* RODIZIO  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_LT = 25,                        /* LT  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NUMBER = 27,                    /* NUMBER  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_PROGRAMA = 33,                  /* PROGRAMA  */
  YYSYMBOL_34_1 = 34,                      /* $@1  */
  YYSYMBOL_COMANDOS = 35,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 36,                   /* COMANDO  */
  YYSYMBOL_DEFINIR_CLIENTE = 37,           /* DEFINIR_CLIENTE  */
  YYSYMBOL_tipo_valor = 38,                /* tipo_valor  */
  YYSYMBOL_ADICIONAR = 39,                 /* ADICIONAR  */
  YYSYMBOL_CALCULAR = 40,                  /* CALCULAR  */
  YYSYMBOL_FECHAR = 41,                    /* FECHAR  */
  YYSYMBOL_MOSTRAR_CMD = 42,               /* MOSTRAR_CMD  */
  YYSYMBOL_BLOCO_SE = 43,                  /* BLOCO_SE  */
  YYSYMBOL_BLOCO_REPETIR = 44,             /* BLOCO_REPETIR  */
  YYSYMBOL_45_2 = 45,                      /* @2  */
  YYSYMBOL_ATRIBUICAO = 46,                /* ATRIBUICAO  */
  YYSYMBOL_CONDICAO = 47,                  /* CONDICAO  */
  YYSYMBOL_ATRIBUTO = 48,                  /* ATRIBUTO  */
  YYSYMBOL_attr_name = 49,                 /* attr_name  */
  YYSYMBOL_VALOR = 50                      /* VALOR  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    30,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    39,    52,    54,    58,    59,    60,    61,
      62,    63,    64,    65,    70,   100,   101,   106,   117,   132,
     182,   186,   194,   215,   214,   241,   249,   255,   261,   271,
     277,   287,   288,   289,   290,   291,   296,   302,   308
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
  "\"end of file\"", "error", "\"invalid token\"", "CLIENTE", "STRING",
  "IDENTIFIER", "TIPO_KW", "PESO_KW", "BEBIDAS_KW", "SOBREMESAS_KW",
  "ADICIONAR_ITEM", "CALCULAR_PESO", "FECHAR_CONTA", "MOSTRAR", "SE",
  "ENTAO", "SENAO", "REPETIR", "VEZES", "CLIENTE_ATTR", "SISTEMA_ATTR",
  "SELF_SERVICE", "RODIZIO", "ASSIGN", "GT", "LT", "EQ", "NUMBER", "'{'",
  "';'", "'}'", "'.'", "$accept", "PROGRAMA", "$@1", "COMANDOS", "COMANDO",
  "DEFINIR_CLIENTE", "tipo_valor", "ADICIONAR", "CALCULAR", "FECHAR",
  "MOSTRAR_CMD", "BLOCO_SE", "BLOCO_REPETIR", "@2", "ATRIBUICAO",
  "CONDICAO", "ATRIBUTO", "attr_name", "VALOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -55,    16,   -55,   -55,    27,     0,   -22,     8,    28,     2,
      -1,    34,    33,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,    15,     1,    36,     7,   -55,    32,    31,    37,
      38,    49,     9,    47,    60,   -55,   -55,   -55,    41,    42,
     -55,   -55,    40,    40,   -55,    44,     1,     1,     1,    45,
      46,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,    35,    -3,   -55,   -55,   -55,
      50,   -55,    12,    67,   -55,    52,    51,    53,    68,    54,
      56,    55,    71,    58,    59,    61,    57,   -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    36,    38,     0,     0,
      18,    20,     0,     0,    21,     0,     0,     0,     0,     0,
       0,    25,    17,    31,    35,    32,    33,    34,    29,    30,
       4,    26,    27,    28,    23,     0,     0,     4,    15,    16,
       0,    22,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,   -54,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,    48,    62,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     4,    13,    14,    70,    15,    16,    17,
      18,    19,    20,    67,    21,    31,    37,    58,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       5,    23,     6,    27,    22,    35,    66,     7,     8,     9,
      10,    11,    24,    72,    12,     5,     3,     6,    28,    29,
      28,    29,     7,     8,     9,    10,    11,    71,    36,    12,
       5,    26,     6,    46,    47,    48,    40,     7,     8,     9,
      10,    11,    74,    34,    12,    53,    54,    55,    56,    57,
      61,    62,    63,    28,    29,    25,    68,    69,    30,    32,
      33,    41,    42,    39,    45,    49,    50,    44,    43,    65,
      51,    52,    60,    64,    75,    76,    79,    80,    77,    73,
      83,    84,    78,    81,    82,     0,    85,    87,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59
};

static const yytype_int8 yycheck[] =
{
       3,    23,     5,     4,     4,     4,    60,    10,    11,    12,
      13,    14,     4,    67,    17,     3,     0,     5,    19,    20,
      19,    20,    10,    11,    12,    13,    14,    30,    27,    17,
       3,    29,     5,    24,    25,    26,    29,    10,    11,    12,
      13,    14,    30,    28,    17,     5,     6,     7,     8,     9,
      46,    47,    48,    19,    20,    27,    21,    22,    10,    11,
      27,    29,    31,    27,    15,    18,     6,    29,    31,    23,
      29,    29,    28,    28,     7,    23,     8,    23,    27,    29,
       9,    23,    29,    27,    29,    -1,    27,    30,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,    35,     3,     5,    10,    11,    12,
      13,    14,    17,    36,    37,    39,    40,    41,    42,    43,
      44,    46,     4,    23,     4,    27,    29,     4,    19,    20,
      48,    47,    48,    27,    28,     4,    27,    48,    50,    27,
      29,    29,    31,    31,    29,    15,    24,    25,    26,    18,
       6,    29,    29,     5,     6,     7,     8,     9,    49,    49,
      28,    50,    50,    50,    28,    23,    35,    45,    21,    22,
      38,    30,    35,    29,    30,     7,    23,    27,    29,     8,
      23,    27,    29,     9,    23,    27,    29,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    34,    33,    35,    35,    36,    36,    36,    36,
      36,    36,    36,    36,    37,    38,    38,    39,    40,    41,
      42,    42,    43,    45,    44,    46,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    50,    50,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,    20,     1,     1,     4,     3,     2,
       3,     3,     6,     0,     7,     4,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 39 "parser.y"
    { /* Abre arquivo de saída */ 
      outf = fopen("out.asm","w");
      if(!outf){ perror("opening out.asm"); exit(1); }
      /* constantes iniciais do sistema (poderia vir de config) */
      emitf("SET sistema.preco_kilo 20");
      emitf("SET sistema.preco_rodizio 50");
      emitf("SET sistema.preco_bebida 5");
      emitf("SET sistema.hora_atual 12");
    }
#line 1181 "parser.tab.c"
    break;

  case 3: /* PROGRAMA: $@1 COMANDOS  */
#line 49 "parser.y"
    { emitf("HALT"); fclose(outf); }
#line 1187 "parser.tab.c"
    break;

  case 14: /* DEFINIR_CLIENTE: CLIENTE STRING '{' TIPO_KW ASSIGN tipo_valor ';' PESO_KW ASSIGN NUMBER ';' BEBIDAS_KW ASSIGN NUMBER ';' SOBREMESAS_KW ASSIGN NUMBER ';' '}'  */
#line 76 "parser.y"
    {
        /* posições:
           $2 = nome (STRING)
           $6 = tipo_valor (STRING)
           $10 = peso (NUMBER)
           $14 = bebidas (NUMBER)
           $18 = sobremesas (NUMBER)
        */
        emitf("SET cliente.nome \"%s\"", (yyvsp[-18].string));
        emitf("SET cliente.tipo \"%s\"", (yyvsp[-14].string));  /* como string para comparação */
        char tmp[80];
        sprintf(tmp, "%g", (yyvsp[-10].number));
        emitf("SET cliente.peso %s", tmp);
        sprintf(tmp, "%g", (yyvsp[-6].number));
        emitf("SET cliente.bebidas %s", tmp);
        sprintf(tmp, "%g", (yyvsp[-2].number));
        emitf("SET cliente.sobremesas %s", tmp);
        /* inicializa total */
        emitf("SET cliente.total 0");
    }
#line 1212 "parser.tab.c"
    break;

  case 15: /* tipo_valor: SELF_SERVICE  */
#line 100 "parser.y"
                   { (yyval.string) = (yyvsp[0].string); }
#line 1218 "parser.tab.c"
    break;

  case 16: /* tipo_valor: RODIZIO  */
#line 101 "parser.y"
                   { (yyval.string) = (yyvsp[0].string); }
#line 1224 "parser.tab.c"
    break;

  case 17: /* ADICIONAR: ADICIONAR_ITEM STRING NUMBER ';'  */
#line 107 "parser.y"
    {
        emitf("ADD cliente.itens \"%s\"", (yyvsp[-2].string));
        char tmp[80];
        sprintf(tmp, "%g", (yyvsp[-1].number));
        emitf("ADD cliente.itens_qtd %s", tmp);
    }
#line 1235 "parser.tab.c"
    break;

  case 18: /* CALCULAR: CALCULAR_PESO NUMBER ';'  */
#line 118 "parser.y"
    {
        char tmp1[80];
        sprintf(tmp1, "%g", (yyvsp[-1].number));
        emitf("# CALCULAR_PESO %s", tmp1);
        emitf("GET cliente.peso temp.value");
        emitf("SET temp.mult %s", tmp1);
        emitf("MUL temp.value temp.mult");
        emitf("GET sistema.preco_kilo temp.k");
        emitf("MUL temp.value temp.k");
        emitf("ADD cliente.total temp.value");
    }
#line 1251 "parser.tab.c"
    break;

  case 19: /* FECHAR: FECHAR_CONTA ';'  */
#line 133 "parser.y"
    {
        static int fecharcnt = 0;
        char lbl_rodizio[64], lbl_bebidas[64];
        sprintf(lbl_rodizio, "CALC_RODIZIO_%d", fecharcnt);
        sprintf(lbl_bebidas, "CALC_BEBIDAS_%d", fecharcnt);
        fecharcnt++;
        
        /* Calcula o total automaticamente antes de fechar */
        emitf("# === FECHAR_CONTA: Calculando total ===");
        
        /* Verifica o tipo do cliente e calcula base */
        emitf("# Verificar tipo e calcular base");
        
        /* Para RODIZIO: base = preco_rodizio */
        /* Para SELF_SERVICE: base já foi calculada com CALCULAR_PESO */
        emitf("IF cliente.tipo == \"RODIZIO\" GOTO %s", lbl_rodizio);
        emitf("JMP %s", lbl_bebidas);
        
        emitf("LABEL %s", lbl_rodizio);
        emitf("GET sistema.preco_rodizio temp.base");
        emitf("ADD cliente.total temp.base");
        
        emitf("LABEL %s", lbl_bebidas);
        /* Soma bebidas: cliente.bebidas * sistema.preco_bebida */
        emitf("GET cliente.bebidas temp.bebidas");
        emitf("GET sistema.preco_bebida temp.preco_beb");
        emitf("MUL temp.bebidas temp.preco_beb");
        emitf("ADD cliente.total temp.bebidas");
        
        /* Soma sobremesas (usando mesmo preço de bebida por simplicidade) */
        emitf("GET cliente.sobremesas temp.sobremesas");
        emitf("GET sistema.preco_bebida temp.preco_sob");
        emitf("MUL temp.sobremesas temp.preco_sob");
        emitf("ADD cliente.total temp.sobremesas");
        
        emitf("# === Exibindo conta final ===");
        emitf("PRINT \"========================================\"");
        emitf("PRINT \"           CONTA DO CLIENTE            \"");
        emitf("PRINT \"========================================\"");
        emitf("PRINT cliente.nome");
        emitf("PRINT cliente.tipo");
        emitf("PRINT \"----------------------------------------\"");
        emitf("PRINT \"Total: \"");
        emitf("PRINT cliente.total");
        emitf("PRINT \"========================================\"");
    }
#line 1302 "parser.tab.c"
    break;

  case 20: /* MOSTRAR_CMD: MOSTRAR STRING ';'  */
#line 183 "parser.y"
    {
        emitf("PRINT \"%s\"", (yyvsp[-1].string));
    }
#line 1310 "parser.tab.c"
    break;

  case 21: /* MOSTRAR_CMD: MOSTRAR ATRIBUTO ';'  */
#line 187 "parser.y"
    {
        emitf("PRINT %s", (yyvsp[-1].string));
    }
#line 1318 "parser.tab.c"
    break;

  case 22: /* BLOCO_SE: SE CONDICAO ENTAO '{' COMANDOS '}'  */
#line 195 "parser.y"
    {
        static int ifcount = 0;
        char thenlbl[64], elselbl[64], endlbl[64];
        sprintf(thenlbl,"THEN_%d", ifcount);
        sprintf(elselbl,"ELSE_%d", ifcount);
        sprintf(endlbl,"ENDIF_%d", ifcount);
        ifcount++;
        emitf("IF %s GOTO %s", (yyvsp[-4].string), thenlbl);
        emitf("JMP %s", elselbl);
        emitf("LABEL %s", thenlbl);
        /* corpo já emitido */
        emitf("JMP %s", endlbl);
        emitf("LABEL %s", elselbl);
        emitf("LABEL %s", endlbl);
    }
#line 1338 "parser.tab.c"
    break;

  case 23: /* @2: %empty  */
#line 215 "parser.y"
    {
        /* mid-rule action: emite inicio do loop ANTES dos comandos */
        static int loopcnt = 0;
        char startlbl[64], cntname[64];
        sprintf(startlbl,"LOOP_START_%d", loopcnt);
        sprintf(cntname,"__loop_cnt_%d", loopcnt);
        emitf("SET %s %g", cntname, (yyvsp[-2].number));
        emitf("LABEL %s", startlbl);
        (yyval.number) = loopcnt;  /* passa o contador para a ação final */
        loopcnt++;
    }
#line 1354 "parser.tab.c"
    break;

  case 24: /* BLOCO_REPETIR: REPETIR NUMBER VEZES '{' @2 COMANDOS '}'  */
#line 227 "parser.y"
    {
        int idx = (int)(yyvsp[-2].number);  /* recupera o contador */
        char startlbl[64], endlbl[64], cntname[64];
        sprintf(startlbl,"LOOP_START_%d", idx);
        sprintf(endlbl,"LOOP_END_%d", idx);
        sprintf(cntname,"__loop_cnt_%d", idx);
        emitf("SUB %s 1", cntname);
        emitf("JNZ %s", startlbl);
        emitf("LABEL %s", endlbl);
    }
#line 1369 "parser.tab.c"
    break;

  case 25: /* ATRIBUICAO: IDENTIFIER ASSIGN VALOR ';'  */
#line 242 "parser.y"
    {
        emitf("SET %s %s", (yyvsp[-3].string), (yyvsp[-1].string));
    }
#line 1377 "parser.tab.c"
    break;

  case 26: /* CONDICAO: ATRIBUTO GT VALOR  */
#line 250 "parser.y"
    {
        char buf[256];
        sprintf(buf, "%s > %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = strdup(buf);
    }
#line 1387 "parser.tab.c"
    break;

  case 27: /* CONDICAO: ATRIBUTO LT VALOR  */
#line 256 "parser.y"
    {
        char buf[256];
        sprintf(buf, "%s < %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = strdup(buf);
    }
#line 1397 "parser.tab.c"
    break;

  case 28: /* CONDICAO: ATRIBUTO EQ VALOR  */
#line 262 "parser.y"
    {
        char buf[256];
        sprintf(buf, "%s == %s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = strdup(buf);
    }
#line 1407 "parser.tab.c"
    break;

  case 29: /* ATRIBUTO: CLIENTE_ATTR '.' attr_name  */
#line 272 "parser.y"
    {
        char buf[128];
        sprintf(buf, "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = strdup(buf);
    }
#line 1417 "parser.tab.c"
    break;

  case 30: /* ATRIBUTO: SISTEMA_ATTR '.' attr_name  */
#line 278 "parser.y"
    {
        char buf[128];
        sprintf(buf, "%s.%s", (yyvsp[-2].string), (yyvsp[0].string));
        (yyval.string) = strdup(buf);
    }
#line 1427 "parser.tab.c"
    break;

  case 31: /* attr_name: IDENTIFIER  */
#line 287 "parser.y"
                      { (yyval.string) = (yyvsp[0].string); }
#line 1433 "parser.tab.c"
    break;

  case 32: /* attr_name: PESO_KW  */
#line 288 "parser.y"
                      { (yyval.string) = strdup("peso"); }
#line 1439 "parser.tab.c"
    break;

  case 33: /* attr_name: BEBIDAS_KW  */
#line 289 "parser.y"
                      { (yyval.string) = strdup("bebidas"); }
#line 1445 "parser.tab.c"
    break;

  case 34: /* attr_name: SOBREMESAS_KW  */
#line 290 "parser.y"
                      { (yyval.string) = strdup("sobremesas"); }
#line 1451 "parser.tab.c"
    break;

  case 35: /* attr_name: TIPO_KW  */
#line 291 "parser.y"
                      { (yyval.string) = strdup("tipo"); }
#line 1457 "parser.tab.c"
    break;

  case 36: /* VALOR: NUMBER  */
#line 297 "parser.y"
    {
        char tmp[64];
        sprintf(tmp, "%g", (yyvsp[0].number));
        (yyval.string) = strdup(tmp);
    }
#line 1467 "parser.tab.c"
    break;

  case 37: /* VALOR: STRING  */
#line 303 "parser.y"
    {
        char *quoted = malloc(strlen((yyvsp[0].string))+3);
        sprintf(quoted, "\"%s\"", (yyvsp[0].string));
        (yyval.string) = quoted;
    }
#line 1477 "parser.tab.c"
    break;

  case 38: /* VALOR: ATRIBUTO  */
#line 309 "parser.y"
    {
        (yyval.string) = (yyvsp[0].string);
    }
#line 1485 "parser.tab.c"
    break;


#line 1489 "parser.tab.c"

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

#line 314 "parser.y"


/* implementações auxiliares */
#include <stdarg.h>
void emitf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(outf, fmt, ap);
    fprintf(outf, "\n");
    va_end(ap);
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror(argv[1]);
            return 1;
        }
        extern FILE *yyin;
        yyin = f;
    }
    return yyparse();
}
