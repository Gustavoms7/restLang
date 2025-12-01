# Gramática EBNF - restLang

## Descrição
restLang é uma linguagem de domínio específico (DSL) para gerenciamento de restaurantes,
permitindo definir clientes, calcular contas, e controlar pedidos.

## Gramática Formal (EBNF)

```ebnf
(* Programa principal *)
programa        = { comando } ;

(* Comandos disponíveis *)
comando         = definir_cliente
                | adicionar_item
                | calcular_peso
                | fechar_conta
                | mostrar
                | bloco_se
                | bloco_repetir
                | atribuicao
                ;

(* Definição de cliente *)
definir_cliente = "CLIENTE" STRING "{"
                    "tipo" "=" tipo_valor ";"
                    "peso" "=" NUMBER ";"
                    "bebidas" "=" NUMBER ";"
                    "sobremesas" "=" NUMBER ";"
                  "}" ;

tipo_valor      = "SELF_SERVICE" | "RODIZIO" ;

(* Adicionar item ao pedido *)
adicionar_item  = "ADICIONAR_ITEM" STRING NUMBER ";" ;

(* Calcular peso da comida *)
calcular_peso   = "CALCULAR_PESO" NUMBER ";" ;

(* Fechar conta do cliente *)
fechar_conta    = "FECHAR_CONTA" ";" ;

(* Mostrar mensagem ou atributo *)
mostrar         = "MOSTRAR" ( STRING | atributo ) ";" ;

(* Bloco condicional *)
bloco_se        = "SE" condicao "ENTAO" "{" { comando } "}" ;

(* Bloco de repetição *)
bloco_repetir   = "REPETIR" NUMBER "VEZES" "{" { comando } "}" ;

(* Atribuição de variável *)
atribuicao      = IDENTIFIER "=" valor ";" ;

(* Condição para SE *)
condicao        = atributo operador valor ;

operador        = ">" | "<" | "==" ;

(* Atributo de cliente ou sistema *)
atributo        = ( "cliente" | "sistema" ) "." IDENTIFIER ;

(* Valores possíveis *)
valor           = NUMBER | STRING | atributo ;

(* Tokens léxicos *)
STRING          = '"' { caractere } '"' ;
NUMBER          = digito { digito } [ "." digito { digito } ] ;
IDENTIFIER      = letra { letra | digito | "_" } ;

(* Definições básicas *)
letra           = "A" | "B" | ... | "Z" | "a" | "b" | ... | "z" | "_" ;
digito          = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
caractere       = (* qualquer caractere exceto aspas e nova linha *) ;
```

## Palavras Reservadas

| Palavra        | Descrição                              |
|----------------|----------------------------------------|
| CLIENTE        | Inicia definição de cliente            |
| tipo           | Define tipo do serviço                 |
| SELF_SERVICE   | Tipo self-service (por peso)           |
| RODIZIO        | Tipo rodízio (preço fixo)              |
| peso           | Peso da comida em kg                   |
| bebidas        | Quantidade de bebidas                  |
| sobremesas     | Quantidade de sobremesas               |
| ADICIONAR_ITEM | Adiciona item ao pedido                |
| CALCULAR_PESO  | Calcula valor baseado no peso          |
| FECHAR_CONTA   | Fecha e exibe conta do cliente         |
| MOSTRAR        | Exibe mensagem ou valor                |
| SE             | Início de bloco condicional            |
| ENTAO          | Parte do bloco condicional             |
| SENAO          | Parte alternativa (não implementado)   |
| REPETIR        | Início de bloco de repetição           |
| VEZES          | Parte do bloco de repetição            |
| cliente        | Prefixo para atributos do cliente      |
| sistema        | Prefixo para atributos do sistema      |

## Operadores

| Operador | Descrição        |
|----------|------------------|
| =        | Atribuição       |
| ==       | Igualdade        |
| >        | Maior que        |
| <        | Menor que        |

## Atributos do Sistema

| Atributo              | Valor Padrão | Descrição                    |
|-----------------------|--------------|------------------------------|
| sistema.preco_kilo    | 20           | Preço por kg (self-service)  |
| sistema.preco_rodizio | 50           | Preço fixo do rodízio        |
| sistema.preco_bebida  | 5            | Preço por bebida             |
| sistema.hora_atual    | 12           | Hora atual do sistema        |

## Atributos do Cliente

| Atributo           | Descrição                  |
|--------------------|----------------------------|
| cliente.nome       | Nome do cliente            |
| cliente.tipo       | Tipo de serviço            |
| cliente.peso       | Peso consumido             |
| cliente.bebidas    | Quantidade de bebidas      |
| cliente.sobremesas | Quantidade de sobremesas   |
| cliente.total      | Total da conta             |
