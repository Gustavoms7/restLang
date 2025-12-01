%option noyywrap
%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
%}

%%

[ \t\r\n]+                ;   /* ignora espaços e quebras de linha */

"CLIENTE"                 { yylval.string = strdup("CLIENTE"); return CLIENTE; }
"tipo"                    { return TIPO_KW; }
"SELF_SERVICE"            { yylval.string = strdup("SELF_SERVICE"); return SELF_SERVICE; }
"RODIZIO"                 { yylval.string = strdup("RODIZIO"); return RODIZIO; }

"peso"                    { return PESO_KW; }
"bebidas"                 { return BEBIDAS_KW; }
"sobremesas"              { return SOBREMESAS_KW; }

"ADICIONAR_ITEM"          { return ADICIONAR_ITEM; }
"CALCULAR_PESO"           { return CALCULAR_PESO; }
"FECHAR_CONTA"            { return FECHAR_CONTA; }
"MOSTRAR"                 { return MOSTRAR; }

"SE"                      { return SE; }
"ENTAO"                   { return ENTAO; }
"SENAO"                   { return SENAO; }
"REPETIR"                 { return REPETIR; }
"VEZES"                   { return VEZES; }

"cliente"                 { yylval.string = strdup("cliente"); return CLIENTE_ATTR; }
"sistema"                 { yylval.string = strdup("sistema"); return SISTEMA_ATTR; }

"=="                      { return EQ; }
">"                       { return GT; }
"<"                       { return LT; }

"="                       { return ASSIGN; }
";"                       { return ';' ; }
"{"                       { return '{' ; }
"}"                       { return '}' ; }
"."                       { return '.' ; }
","                       { return ',' ; }

[0-9]+(\.[0-9]+)?         { yylval.number = atof(yytext); return NUMBER; }

\"([^\"\n])*\"            {
                             int L = strlen(yytext);
                             char *s = malloc(L-1);
                             if (!s) { fprintf(stderr,"malloc failed\n"); exit(1); }
                             strncpy(s, yytext+1, L-2);
                             s[L-2] = '\0';
                             yylval.string = s;
                             return STRING;
                          }

[A-Za-z_][A-Za-z0-9_]*    { yylval.string = strdup(yytext); return IDENTIFIER; }

    /* ignora qualquer outro caractere */
.                         ;

%%
