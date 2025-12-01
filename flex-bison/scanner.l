%{
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>

void yyerror(const char *s);
extern int yylineno;

/* seta yylval.str (o parser declara %union { char *str; }) */
static void set_yylval_str(const char *s) {
    if (s == NULL) yylval.str = NULL;
    else yylval.str = strdup(s);
}

/* start condition para comentários em bloco */
%x COMMENT
%}

/* Regras */
%%
[ \t\r\n]+                      { /* ignora espaços */ }

/* comentários de linha */
"//".*                          { /* ignora */ }

/* comentário de bloco usando start condition */
"/*"                            { BEGIN(COMMENT); }
<COMMENT>[^*]+                  { /* consumir texto dentro do comentário */ }
<COMMENT>"*"+[^*/]*             { /* consumir sequências com * */ }
<COMMENT>"*/"                   { BEGIN(INITIAL); }

/* palavras-chave */
"CLIENTE"                       { return CLIENTE; }
"tipo"                          { set_yylval_str(yytext); return TIPO; }
"SELF_SERVICE"                  { set_yylval_str(yytext); return SELF_SERVICE; }
"RODIZIO"                       { set_yylval_str(yytext); return RODIZIO; }
"peso"                          { set_yylval_str(yytext); return PESO; }
"bebidas"                       { set_yylval_str(yytext); return BEBIDAS; }
"sobremesas"                    { set_yylval_str(yytext); return SOBREMESAS; }
"ADICIONAR_ITEM"                { return ADICIONAR_ITEM; }
"CALCULAR_PESO"                 { return CALCULAR_PESO; }
"FECHAR_CONTA"                  { return FECHAR_CONTA; }
"MOSTRAR"                       { return MOSTRAR; }
"SE"                            { return SE; }
"ENTAO"                         { return ENTAO; }
"SENAO"                         { return SENAO; }
"REPETIR"                       { return REPETIR; }
"VEZES"                         { return VEZES; }

/* atributos/literals do sistema e referencias cliente/sistema */
"preco_kilo"                    { set_yylval_str(yytext); return SISTEMA_PRECO_KILO; }
"preco_rodizio"                 { set_yylval_str(yytext); return SISTEMA_PRECO_RODIZIO; }
"preco_bebida"                  { set_yylval_str(yytext); return SISTEMA_PRECO_BEBIDA; }
"hora_atual"                    { set_yylval_str(yytext); return SISTEMA_HORA_ATUAL; }
"cliente"                       { set_yylval_str(yytext); return CLIENTE_ATTR; }
"sistema"                       { set_yylval_str(yytext); return SISTEMA_ATTR; }

/* pontuação (caracteres literais entre aspas para evitar ambiguidade) */
"{"                             { return '{'; }
"}"                             { return '}'; }
";"                             { return ';'; }
","                             { return ','; }
"."                             { return '.'; }

/* comparadores (ordem: '==' primeiro) */
"=="                            { return EQ; }
">"                             { return '>'; }
"<"                             { return '<'; }

/* string literal: aceita escapes simples */
\"([^\\\"]|\\.)*\"              {
                                    int len = yyleng;
                                    char *buf = malloc(len-1);
                                    if (!buf) exit(1);
                                    int i = 1, j = 0;
                                    while (i < yyleng-1) {
                                        if (yytext[i] == '\\' && i+1 < yyleng-1) {
                                            char esc = yytext[i+1];
                                            if (esc == 'n') { buf[j++] = '\n'; }
                                            else if (esc == 't') { buf[j++] = '\t'; }
                                            else if (esc == '\\') { buf[j++] = '\\'; }
                                            else if (esc == '"') { buf[j++] = '"'; }
                                            else { buf[j++] = esc; }
                                            i += 2;
                                        } else {
                                            buf[j++] = yytext[i++];
                                        }
                                    }
                                    buf[j] = '\0';
                                    set_yylval_str(buf);
                                    free(buf);
                                    return STRING;
                                }

/* número inteiro ou decimal (guardar como string) */
[0-9]+(\.[0-9]+)?               {
                                    set_yylval_str(yytext);
                                    return NUMBER;
                                }

/* identificadores (variáveis, nomes de atributos usados em ATRIBUICAO etc) */
[A-Za-z_][A-Za-z0-9_]*          {
                                    set_yylval_str(yytext);
                                    return IDENTIFIER;
                                }

/* qualquer caractere inválido */
.                               {
                                    char msg[256];
                                    snprintf(msg, sizeof(msg), "Lexical error near '%s' (line %d)", yytext, yylineno);
                                    yyerror(msg);
                                }

%%

int yywrap(void) { return 1; }
