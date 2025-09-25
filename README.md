# restLang
Repositório criado para a realização da APS de Lógica Computacional

**Autor:** Gustavo Mendes

---

## 🍴 O restLang
O **restLang** é uma linguagem de domínio específico (DSL) criada para simular o funcionamento de um restaurante no estilo **self-service e rodízio**.  

Com ela, é possível:  
- Registrar clientes e definir o tipo de atendimento (self-service ou rodízio).  
- Calcular valores baseados no peso do prato, quantidade de bebidas e sobremesas.  
- Configurar regras condicionais (como promoções em determinados horários).  
- Utilizar estruturas de repetição para registrar múltiplos itens (ex.: várias bebidas).  
- Exibir o valor total da comanda do cliente.  

O objetivo é demonstrar conceitos de **linguagens de programação, análise léxica e sintática** em um domínio prático e próximo do cotidiano.  

---

## 📜 Gramática EBNF

```ebnf
PROGRAMA = { COMANDO } ;

/* --- Comandos Principais --- */
COMANDO = DEFINIR_CLIENTE | ADICIONAR | CALCULAR | FECHAR | MOSTRAR 
        | BLOCO_SE | BLOCO_REPETIR | ATRIBUICAO | COMENTARIO ;

/* --- Estruturas principais --- */
DEFINIR_CLIENTE = "CLIENTE", STRING, "{",
    "tipo", "=", ("SELF_SERVICE" | "RODIZIO"), ";",
    "peso", "=", NUMBER, ";",              (* usado se for self-service *)
    "bebidas", "=", NUMBER, ";",
    "sobremesas", "=", NUMBER, ";",
"}" ;

ADICIONAR = "ADICIONAR_ITEM", STRING, NUMBER, ";" ;
CALCULAR  = "CALCULAR_PESO", NUMBER, ";" ;
FECHAR    = "FECHAR_CONTA", ";" ;
MOSTRAR   = "MOSTRAR", (STRING | ATRIBUTO), ";" ;

/* --- Fluxo de controle --- */
BLOCO_SE = "SE", CONDICAO, "ENTAO", "{", { COMANDO }, "}", 
           [ "SENAO", "{", { COMANDO }, "}" ] ;

BLOCO_REPETIR = "REPETIR", NUMBER, "VEZES", "{", { COMANDO }, "}" ;

ATRIBUICAO = IDENTIFIER, "=", VALOR, ";" ;

/* --- Estruturas de condição --- */
CONDICAO = ATRIBUTO, OPERADOR, VALOR ;
ATRIBUTO = "cliente" "." ( "tipo" | "peso" | "bebidas" | "sobremesas" | "total" )
          | "sistema" "." ( "preco_kilo" | "preco_rodizio" | "preco_bebida" | "hora_atual" ) ;
OPERADOR = ">" | "<" | "==" ;
VALOR = NUMBER | STRING | ATRIBUTO ;

/* --- Literais e Tokens Básicos --- */
NUMBER = DIGIT, { DIGIT } ;
STRING = '"', { LETTER | DIGIT | " " }, '"' ;
IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
COMMENT = "/*", { ANY }, "*/" ;
LETTER = "a" | "b" | ... | "Z" ;
DIGIT = "0" | "1" | ... | "9" ;
