%{
#include "parser.tab.h"
#include <string.h>

void yyerror(const char *s);
int yylval_set_string(const char *s);
%}

%%

[ \t\r\n]+                    { /* ignora espaços em branco */ }

"/*"([^*]|\*+[^*/])*\*+"/"     { /* comentário C-style ignorado */ }

"CLIENTE"                    { return CLIENTE; }
"tipo"                       { return TIPO; }
"="                          { return '='; }
"SELF_SERVICE"               { return SELF_SERVICE; }
"RODIZIO"                    { return RODIZIO; }
"peso"                       { return PESO; }
"bebidas"                    { return BEBIDAS; }
"sobremesas"                 { return SOBREMESAS; }
"ADICIONAR_ITEM"             { return ADICIONAR_ITEM; }
"CALCULAR_PESO"              { return CALCULAR_PESO; }
"FECHAR_CONTA"               { return FECHAR_CONTA; }
"MOSTRAR"                    { return MOSTRAR; }
"SE"                         { return SE; }
"ENTAO"                      { return ENTAO; }
"SENAO"                      { return SENAO; }
"REPETIR"                    { return REPETIR; }
"VEZES"                      { return VEZES; }

"preco_kilo"                 { return SISTEMA_PRECO_KILO; }
"preco_rodizio"              { return SISTEMA_PRECO_RODIZIO; }
"preco_bebida"               { return SISTEMA_PRECO_BEBIDA; }
"hora_atual"                 { return SISTEMA_HORA_ATUAL; }

"{"                          { return '{'; }
"}"                          { return '}'; }
";"                          { return ';'; }
","                          { return ','; }
"."                          { return '.'; }

">"                          { return '>'; }
"<"                          { return '<'; }
"=="                         { return EQ; }

\"([^\\\"]|\\.)*\"            {
                                /* string literal: remove quotes */
                                char *s = strdup(yytext);
                                int len = strlen(s);
                                s[len-1] = '\0';
                                char *inner = strdup(s+1);
                                free(s);
                                yylval_set_string(inner);
                                free(inner);
                                return STRING;
                             }

[0-9]+("."[0-9]+)?            {
                                yylval->num = atof(yytext);
                                return NUMBER;
                             }

[A-Za-z_][A-Za-z0-9_]*        {
                                /* identificador (IDENTIFIER) or attribute names like cliente, sistema */
                                if (strcmp(yytext, "cliente") == 0) return CLIENTE_ATTR;
                                if (strcmp(yytext, "sistema") == 0) return SISTEMA_ATTR;
                                /* identifiers */
                                yylval_set_string(yytext);
                                return IDENTIFIER;
                             }

.                            { /* caractere inesperado */
                                yyerror("Caracter desconhecido");
                             }

%%

/* helper to set yylval string (we store pointer in yylval->str) */
int yylval_set_string(const char *s) {
    extern YYSTYPE yylval;
    if (s == NULL) return 0;
    yylval.str = strdup(s);
    return 1;
}
