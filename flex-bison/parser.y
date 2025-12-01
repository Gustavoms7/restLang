%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void yyerror(const char *s);
int yylex(void);
extern int yylineno;

FILE *fout;
int label_counter = 0;
int new_label() { return ++label_counter; }

void emit(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(fout, fmt, ap);
    fprintf(fout, "\n");
    va_end(ap);
}
%}

/* valor semântico: cadeias (strings) */
%union {
    char *str;
}

/* --- tokens e tipos semânticos --- */
%token CLIENTE
%token <str> STRING
%token <str> NUMBER
%token <str> IDENTIFIER
%token <str> CLIENTE_ATTR
%token <str> SISTEMA_ATTR

/* palavras-chave/atributos (mantidos como <str> para facilitar ações) */
%token <str> TIPO
%token <str> SELF_SERVICE
%token <str> RODIZIO
%token <str> PESO
%token <str> BEBIDAS
%token <str> SOBREMESAS

%token ADICIONAR_ITEM CALCULAR_PESO FECHAR_CONTA MOSTRAR
%token SE ENTAO SENAO REPETIR VEZES

%token <str> SISTEMA_PRECO_KILO
%token <str> SISTEMA_PRECO_RODIZIO
%token <str> SISTEMA_PRECO_BEBIDA
%token <str> SISTEMA_HORA_ATUAL

%token EQ


/* tipos de não-terminais */
%type <str> PROGRAMA DEFINIR_CLIENTE ADICIONAR CALCULAR FECHAR
%type <str> BLOCO_SE BLOCO_REPETIR ATRIBUICAO CONDICAO ATRIBUTO VALOR
%type <str> MOSTRAR_CMD
%type COMANDOS COMANDO

%start PROGRAMA

%%

/* -------- PROGRAMA -------- */
PROGRAMA:
    {
      fout = fopen("saida.asm", "w");
      if (!fout) { fprintf(stderr, "Erro: não foi possível criar saida.asm\n"); exit(1); }
      emit("; === generated assembly (restLang) ===");
      emit("SECTION DATA");
      emit("SECTION CODE");
    }
    COMANDOS
    {
      emit("; === fim do código gerado ===");
      fclose(fout);
    }
    ;

/* -------- COMANDOS -------- */
COMANDOS:
      /* vazio */
    | COMANDOS COMANDO
    ;

/* -------- COMANDO (alternativas) -------- */
COMANDO:
      DEFINIR_CLIENTE
    | ADICIONAR
    | CALCULAR
    | FECHAR
    | MOSTRAR_CMD
    | BLOCO_SE
    | BLOCO_REPETIR
    | ATRIBUICAO
    ;

/* -------- DEFINIR_CLIENTE (duas alternativas: SELF_SERVICE ou RODIZIO) -------- */
DEFINIR_CLIENTE:
    CLIENTE STRING '{' TIPO '=' SELF_SERVICE ';' PESO '=' NUMBER ';' BEBIDAS '=' NUMBER ';' SOBREMESAS '=' NUMBER ';' '}'
    {
      emit("; DEFINIR_CLIENTE %s", $2);
      emit("DATA CLIENTE_NAME \"%s\"", $2);
      emit("DATA CLIENTE_TIPO \"%s\"", "SELF_SERVICE");
      emit("DATA CLIENTE_PESO %s", $10);
      emit("DATA CLIENTE_BEBIDAS %s", $14);
      emit("DATA CLIENTE_SOBREMESAS %s", $18);
      free($2); free($10); free($14); free($18);
    }
  | CLIENTE STRING '{' TIPO '=' RODIZIO ';' PESO '=' NUMBER ';' BEBIDAS '=' NUMBER ';' SOBREMESAS '=' NUMBER ';' '}'
    {
      emit("; DEFINIR_CLIENTE %s", $2);
      emit("DATA CLIENTE_NAME \"%s\"", $2);
      emit("DATA CLIENTE_TIPO \"%s\"", "RODIZIO");
      emit("DATA CLIENTE_PESO %s", $10);
      emit("DATA CLIENTE_BEBIDAS %s", $14);
      emit("DATA CLIENTE_SOBREMESAS %s", $18);
      free($2); free($10); free($14); free($18);
    }
    ;


/* -------- ADICIONAR_ITEM -------- */
ADICIONAR:
    ADICIONAR_ITEM STRING NUMBER ';'
    {
      emit("ADICIONAR_ITEM \"%s\" %s", $2, $3);
      free($2); free($3);
    }
    ;

/* -------- CALCULAR_PESO -------- */
CALCULAR:
    CALCULAR_PESO NUMBER ';'
    {
      emit("CALCULAR_PESO %s", $2);
      free($2);
    }
    ;

/* -------- FECHAR_CONTA -------- */
FECHAR:
    FECHAR_CONTA ';'
    {
      emit("FECHAR_CONTA");
    }
    ;

/* -------- MOSTRAR (string ou atributo) -------- */
MOSTRAR_CMD:
    MOSTRAR STRING ';'
    {
      emit("PRINT \"%s\"", $2);
      free($2);
    }
  | MOSTRAR ATRIBUTO ';'
    {
      emit("PRINT_ATTR %s", $2);
      free($2);
    }
    ;

/* -------- BLOCO SE / SENAO --------
   Observação: aqui estamos gerando EVAL_COND <texto> e labels; a VM faz avaliação textual simples.
*/
BLOCO_SE:
    SE CONDICAO ENTAO '{' COMANDOS '}'
    {
      int L1 = new_label();
      int Lend = new_label();
      emit("; IF %s THEN", $2);
      emit("EVAL_COND %s", $2);
      emit("JZ L_else_%d", L1);
      /* then body já foi emitido pelos COMANDOS */
      emit("JMP L_end_%d", Lend);
      emit("L_else_%d:", L1);
      emit("; (no else)");
      emit("L_end_%d:", Lend);
      free($2);
    }
  | SE CONDICAO ENTAO '{' COMANDOS '}' SENAO '{' COMANDOS '}'
    {
      int Lelse = new_label();
      int Lend = new_label();
      emit("; IF %s THEN ... ELSE ...", $2);
      emit("EVAL_COND %s", $2);
      emit("JZ L_else_%d", Lelse);
      /* then body */
      emit("JMP L_end_%d", Lend);
      emit("L_else_%d:", Lelse);
      /* else body */
      emit("L_end_%d:", Lend);
      free($2);
    }
    ;

/* -------- BLOCO REPETIR -------- */
BLOCO_REPETIR:
    REPETIR NUMBER VEZES '{' COMANDOS '}'
    {
      int Lstart = new_label();
      int Lend = new_label();
      emit("PUSH %s", $2); /* contador inicial */
      emit("L_repeat_%d:", Lstart);
      emit("DUP");
      emit("JZ L_repeat_end_%d", Lend);
      /* body */
      emit("DEC");
      emit("JMP L_repeat_%d", Lstart);
      emit("L_repeat_end_%d:", Lend);
      free($2);
    }
    ;

/* -------- ATRIBUIÇÃO -------- */
ATRIBUICAO:
    IDENTIFIER '=' VALOR ';'
    {
      emit("STORE %s %s", $1, $3);
      free($1); free($3);
    }
    ;

/* -------- CONDICAO (monta string para EVAL_COND) -------- */
CONDICAO:
    ATRIBUTO '>' VALOR
    {
      size_t n = strlen($1) + strlen($3) + 4;
      $$ = malloc(n);
      snprintf($$, n, "%s>%s", $1, $3);
      free($1); free($3);
    }
  | ATRIBUTO '<' VALOR
    {
      size_t n = strlen($1) + strlen($3) + 4;
      $$ = malloc(n);
      snprintf($$, n, "%s<%s", $1, $3);
      free($1); free($3);
    }
  | ATRIBUTO EQ VALOR
    {
      size_t n = strlen($1) + strlen($3) + 5;
      $$ = malloc(n);
      snprintf($$, n, "%s==%s", $1, $3);
      free($1); free($3);
    }
    ;

/* -------- ATRIBUTO (várias formas suportadas) -------- */
ATRIBUTO:
    CLIENTE_ATTR '.' TIPO
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | CLIENTE_ATTR '.' PESO
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | CLIENTE_ATTR '.' BEBIDAS
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | CLIENTE_ATTR '.' SOBREMESAS
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | SISTEMA_ATTR '.' SISTEMA_PRECO_KILO
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | SISTEMA_ATTR '.' SISTEMA_PRECO_RODIZIO
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | SISTEMA_ATTR '.' SISTEMA_PRECO_BEBIDA
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
  | SISTEMA_ATTR '.' SISTEMA_HORA_ATUAL
    {
      size_t n = strlen($1) + 1 + strlen($3) + 1;
      $$ = malloc(n);
      snprintf($$, n, "%s.%s", $1, $3);
      free($1); free($3);
    }
    ;

/* -------- VALOR (NUMBER | STRING | ATRIBUTO) -------- */
VALOR:
    NUMBER    { $$ = $1; }
  | STRING    { $$ = $1; }
  | ATRIBUTO  { $$ = $1; }
    ;

%%

/* -------- código auxiliar (yyerror / main) -------- */
void yyerror(const char *s) {
    fprintf(stderr, "Parse error (line %d): %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <arquivo.rest>\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (!in) { perror("fopen"); return 1; }
    extern FILE *yyin;
    yyin = in;
    if (yyparse() == 0) {
        printf("Parse OK. Arquivo saida.asm gerado.\n");
    } else {
        printf("Erros de parse.\n");
    }
    fclose(in);
    return 0;
}
