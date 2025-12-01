%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *outf;

/* helper para emitir linhas no out.asm */
void emitf(const char *fmt, ...);
%}

%union {
    double number;
    char *string;
}

/* Declaração de tokens (inclui os que faltavam: ASSIGN, GT, LT, EQ) */
%token <string> CLIENTE STRING IDENTIFIER
%token TIPO_KW PESO_KW BEBIDAS_KW SOBREMESAS_KW
%token ADICIONAR_ITEM CALCULAR_PESO FECHAR_CONTA MOSTRAR
%token SE ENTAO SENAO REPETIR VEZES
%token <string> CLIENTE_ATTR SISTEMA_ATTR
%token <string> SELF_SERVICE RODIZIO

%token ASSIGN
%token GT LT EQ

%token <number> NUMBER

/* declarar tipos para não-terminais que retornam valores */
%type <string> ATRIBUTO VALOR tipo_valor CONDICAO attr_name

%%

PROGRAMA:
    { /* Abre arquivo de saída */ 
      outf = fopen("out.asm","w");
      if(!outf){ perror("opening out.asm"); exit(1); }
      /* constantes iniciais do sistema (poderia vir de config) */
      emitf("SET sistema.preco_kilo 20");
      emitf("SET sistema.preco_rodizio 50");
      emitf("SET sistema.preco_bebida 5");
      emitf("SET sistema.hora_atual 12");
    }
    COMANDOS
    { emitf("HALT"); fclose(outf); }
    ;

COMANDOS:
      /* vazio */
    | COMANDOS COMANDO
    ;

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

/* DEFINIR_CLIENTE */
DEFINIR_CLIENTE:
    CLIENTE STRING '{'
        TIPO_KW ASSIGN tipo_valor ';'
        PESO_KW ASSIGN NUMBER ';'
        BEBIDAS_KW ASSIGN NUMBER ';'
        SOBREMESAS_KW ASSIGN NUMBER ';'
    '}' 
    {
        /* posições:
           $2 = nome (STRING)
           $6 = tipo_valor (STRING)
           $10 = peso (NUMBER)
           $14 = bebidas (NUMBER)
           $18 = sobremesas (NUMBER)
        */
        emitf("SET cliente.nome \"%s\"", $2);
        emitf("SET cliente.tipo \"%s\"", $6);  /* como string para comparação */
        char tmp[80];
        sprintf(tmp, "%g", $10);
        emitf("SET cliente.peso %s", tmp);
        sprintf(tmp, "%g", $14);
        emitf("SET cliente.bebidas %s", tmp);
        sprintf(tmp, "%g", $18);
        emitf("SET cliente.sobremesas %s", tmp);
        /* inicializa total */
        emitf("SET cliente.total 0");
    }
    ;

/* producao auxiliar para o tipo (evita parênteses na RHS) */
tipo_valor:
      SELF_SERVICE { $$ = $1; }
    | RODIZIO      { $$ = $1; }
    ;

/* ADICIONAR_ITEM "nome" numero ; */
ADICIONAR:
    ADICIONAR_ITEM STRING NUMBER ';'
    {
        emitf("ADD cliente.itens \"%s\"", $2);
        char tmp[80];
        sprintf(tmp, "%g", $3);
        emitf("ADD cliente.itens_qtd %s", tmp);
    }
    ;

/* CALCULAR_PESO number ; */
CALCULAR:
    CALCULAR_PESO NUMBER ';'
    {
        char tmp1[80];
        sprintf(tmp1, "%g", $2);
        emitf("# CALCULAR_PESO %s", tmp1);
        emitf("GET cliente.peso temp.value");
        emitf("SET temp.mult %s", tmp1);
        emitf("MUL temp.value temp.mult");
        emitf("GET sistema.preco_kilo temp.k");
        emitf("MUL temp.value temp.k");
        emitf("ADD cliente.total temp.value");
    }
    ;

FECHAR:
    FECHAR_CONTA ';'
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
    ;

MOSTRAR_CMD:
      MOSTRAR STRING ';'
    {
        emitf("PRINT \"%s\"", $2);
    }
    | MOSTRAR ATRIBUTO ';'
    {
        emitf("PRINT %s", $2);
    }
    ;

/* BLOCO_SE */
BLOCO_SE:
    SE CONDICAO ENTAO '{' COMANDOS '}' 
    {
        static int ifcount = 0;
        char thenlbl[64], elselbl[64], endlbl[64];
        sprintf(thenlbl,"THEN_%d", ifcount);
        sprintf(elselbl,"ELSE_%d", ifcount);
        sprintf(endlbl,"ENDIF_%d", ifcount);
        ifcount++;
        emitf("IF %s GOTO %s", $2, thenlbl);
        emitf("JMP %s", elselbl);
        emitf("LABEL %s", thenlbl);
        /* corpo já emitido */
        emitf("JMP %s", endlbl);
        emitf("LABEL %s", elselbl);
        emitf("LABEL %s", endlbl);
    }
    ;

/* BLOCO_REPETIR */
BLOCO_REPETIR:
    REPETIR NUMBER VEZES '{'
    {
        /* mid-rule action: emite inicio do loop ANTES dos comandos */
        static int loopcnt = 0;
        char startlbl[64], cntname[64];
        sprintf(startlbl,"LOOP_START_%d", loopcnt);
        sprintf(cntname,"__loop_cnt_%d", loopcnt);
        emitf("SET %s %g", cntname, $2);
        emitf("LABEL %s", startlbl);
        $<number>$ = loopcnt;  /* passa o contador para a ação final */
        loopcnt++;
    }
    COMANDOS '}'
    {
        int idx = (int)$<number>5;  /* recupera o contador */
        char startlbl[64], endlbl[64], cntname[64];
        sprintf(startlbl,"LOOP_START_%d", idx);
        sprintf(endlbl,"LOOP_END_%d", idx);
        sprintf(cntname,"__loop_cnt_%d", idx);
        emitf("SUB %s 1", cntname);
        emitf("JNZ %s", startlbl);
        emitf("LABEL %s", endlbl);
    }
    ;

/* ATRIBUICAO: IDENTIFIER = VALOR ; */
ATRIBUICAO:
    IDENTIFIER ASSIGN VALOR ';'
    {
        emitf("SET %s %s", $1, $3);
    }
    ;

/* CONDICAO */
CONDICAO:
      ATRIBUTO GT VALOR
    {
        char buf[256];
        sprintf(buf, "%s > %s", $1, $3);
        $$ = strdup(buf);
    }
    | ATRIBUTO LT VALOR
    {
        char buf[256];
        sprintf(buf, "%s < %s", $1, $3);
        $$ = strdup(buf);
    }
    | ATRIBUTO EQ VALOR
    {
        char buf[256];
        sprintf(buf, "%s == %s", $1, $3);
        $$ = strdup(buf);
    }
    ;

/* ATRIBUTO */
ATRIBUTO:
      CLIENTE_ATTR '.' attr_name
    {
        char buf[128];
        sprintf(buf, "%s.%s", $1, $3);
        $$ = strdup(buf);
    }
    | SISTEMA_ATTR '.' attr_name
    {
        char buf[128];
        sprintf(buf, "%s.%s", $1, $3);
        $$ = strdup(buf);
    }
    ;

/* nomes de atributos (inclui palavras reservadas que podem ser atributos) */
attr_name:
      IDENTIFIER      { $$ = $1; }
    | PESO_KW         { $$ = strdup("peso"); }
    | BEBIDAS_KW      { $$ = strdup("bebidas"); }
    | SOBREMESAS_KW   { $$ = strdup("sobremesas"); }
    | TIPO_KW         { $$ = strdup("tipo"); }
    ;

/* VALOR */
VALOR:
      NUMBER
    {
        char tmp[64];
        sprintf(tmp, "%g", $1);
        $$ = strdup(tmp);
    }
    | STRING
    {
        char *quoted = malloc(strlen($1)+3);
        sprintf(quoted, "\"%s\"", $1);
        $$ = quoted;
    }
    | ATRIBUTO
    {
        $$ = $1;
    }
    ;

%%

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
