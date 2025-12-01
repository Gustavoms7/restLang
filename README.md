# restLang 🍽️

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Tools](https://img.shields.io/badge/Tools-Flex%20%2B%20Bison-green.svg)](https://www.gnu.org/software/bison/)
[![License](https://img.shields.io/badge/License-Educational-orange.svg)](#)

> Uma linguagem de domínio específico (DSL) para gerenciamento de restaurantes, desenvolvida com Flex e Bison.

**Autor:** Gustavo Mendes  
**Disciplina:** Lógica Computacional - APS

---
>🚨Apresentação e EBNF mais detalhados na pasta docs

## 📖 Sobre o Projeto

O **restLang** é uma DSL criada para simular o funcionamento de um restaurante no estilo **self-service e rodízio**.

### Funcionalidades

| Recurso | Descrição |
|---------|-----------|
| 👤 **Clientes** | Registrar clientes com tipo de atendimento |
| ⚖️ **Peso** | Calcular valores baseados no peso do prato |
| 🍺 **Itens** | Adicionar bebidas e sobremesas |
| 🔄 **Condicionais** | Regras com SE/ENTAO |
| 🔁 **Repetição** | Loops com REPETIR/VEZES |
| 💰 **Conta** | Exibir valor total da comanda |

---

## 🛠️ Requisitos

| Ferramenta | Versão Mínima |
|------------|---------------|
| GCC | 7.0+ |
| Flex | 2.6+ |
| Bison | 3.0+ |
| Make | 4.0+ |

### Instalação (Ubuntu/Debian/WSL)

```bash
sudo apt update
sudo apt install gcc flex bison make
```

---

## 🚀 Compilação e Execução

> ⚠️ **Este projeto deve ser executado em ambiente Linux/WSL**

### No WSL (Windows Subsystem for Linux):

```bash
# Navegar até o diretório do projeto
cd /mnt/c/caminho/para/restLang

# Compilar
make

# Executar um programa
./rest_parser sample.rest && ./restvm

# Executar todos os testes
make test-all
```

---

## 📝 Exemplo de Código

Crie um arquivo `meu_restaurante.rest`:

```
CLIENTE "Maria" {
    tipo = SELF_SERVICE;
    peso = 1.5;
    bebidas = 2;
    sobremesas = 1;
}

MOSTRAR "Bem-vinda ao Restaurante!";
CALCULAR_PESO 1.0;
ADICIONAR_ITEM "Refrigerante" 2;

SE cliente.peso > 1 ENTAO {
    MOSTRAR "Prato generoso!";
}

REPETIR 3 VEZES {
    MOSTRAR "Processando...";
}

MOSTRAR cliente.total;
FECHAR_CONTA;
```

Execute:

```bash
./rest_parser meu_restaurante.rest && ./restvm
```

Saída esperada:

```
Bem-vinda ao Restaurante!
Prato generoso!
Processando...
Processando...
Processando...
========================================
           CONTA DO CLIENTE
========================================
Maria
SELF_SERVICE
----------------------------------------
Total:
45
========================================
```

---

## 🧪 Testes

### Executar todos os testes

```bash
make test-all
```

### Executar teste individual

```bash
./rest_parser tests/test1_self_service.rest && ./restvm
```

### Testes Disponíveis

| Arquivo | Funcionalidade Testada |
|---------|------------------------|
| `test1_self_service.rest` | Cliente self-service completo |
| `test2_rodizio.rest` | Cliente tipo rodízio |
| `test3_repetir.rest` | Loop REPETIR X VEZES |
| `test4_condicional.rest` | Condicionais SE/ENTAO |
| `test5_completo.rest` | Todos os recursos |
| `test6_atribuicao.rest` | Variáveis customizadas |

---

## 📜 Sintaxe da Linguagem

### Definir Cliente

```
CLIENTE "Nome" {
    tipo = SELF_SERVICE;   // ou RODIZIO
    peso = 1.5;            // peso em kg
    bebidas = 2;           // quantidade
    sobremesas = 1;        // quantidade
}
```

### Comandos Disponíveis

| Comando | Sintaxe | Descrição |
|---------|---------|-----------|
| `MOSTRAR` | `MOSTRAR "texto";` | Exibe mensagem |
| `MOSTRAR` | `MOSTRAR cliente.peso;` | Exibe atributo |
| `CALCULAR_PESO` | `CALCULAR_PESO 1.5;` | Multiplica peso e calcula valor |
| `ADICIONAR_ITEM` | `ADICIONAR_ITEM "nome" qtd;` | Adiciona item ao pedido |
| `FECHAR_CONTA` | `FECHAR_CONTA;` | Exibe e fecha conta |

### Estruturas de Controle

```
// Condicional
SE cliente.peso > 2 ENTAO {
    MOSTRAR "Cliente comeu bastante!";
}

// Repetição
REPETIR 5 VEZES {
    MOSTRAR "Executando...";
}
```

### Operadores

| Operador | Descrição |
|----------|-----------|
| `=` | Atribuição |
| `==` | Igualdade |
| `>` | Maior que |
| `<` | Menor que |

### Atributos do Sistema

| Atributo | Valor Padrão | Descrição |
|----------|--------------|-----------|
| `sistema.preco_kilo` | 20 | Preço por kg |
| `sistema.preco_rodizio` | 50 | Preço fixo rodízio |
| `sistema.preco_bebida` | 5 | Preço por bebida |

### Atributos do Cliente

| Atributo | Descrição |
|----------|-----------|
| `cliente.nome` | Nome do cliente |
| `cliente.tipo` | SELF_SERVICE ou RODIZIO |
| `cliente.peso` | Peso consumido |
| `cliente.bebidas` | Qtd de bebidas |
| `cliente.sobremesas` | Qtd de sobremesas |
| `cliente.total` | Total da conta |

---

## 🔧 Arquitetura

```
┌──────────────┐     ┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│   Código     │────▶│    Lexer     │────▶│    Parser    │────▶│   out.asm    │
│   .rest      │     │   (Flex)     │     │   (Bison)    │     │  (Assembly)  │
└──────────────┘     └──────────────┘     └──────────────┘     └──────────────┘
                                                                      │
                                                                      ▼
                                                               ┌──────────────┐
                                                               │    restvm    │
                                                               │     (VM)     │
                                                               └──────────────┘
                                                                      │
                                                                      ▼
                                                               ┌──────────────┐
                                                               │    Saída     │
                                                               │   (stdout)   │
                                                               └──────────────┘
```

### Componentes

| Arquivo | Descrição |
|---------|-----------|
| `lexer.l` | Analisador léxico (Flex) - tokenização |
| `parser.y` | Analisador sintático (Bison) - gramática e geração de código |
| `restvm.c` | Máquina virtual - executa o assembly gerado |

---

## 📂 Estrutura do Projeto

```
restLang/
├── lexer.l              # Analisador léxico (Flex)
├── parser.y             # Analisador sintático (Bison)
├── restvm.c             # Máquina virtual
├── Makefile             # Script de compilação
├── README.md            # Este arquivo
├── sample.rest          # Exemplo básico
├── docs/
│   └── EBNF.md          # Gramática formal EBNF
└── tests/
    ├── test1_self_service.rest
    ├── test2_rodizio.rest
    ├── test3_repetir.rest
    ├── test4_condicional.rest
    ├── test5_completo.rest
    └── test6_atribuicao.rest
```

---

## 📜 Gramática EBNF

```ebnf
PROGRAMA     = { COMANDO } ;

COMANDO      = DEFINIR_CLIENTE | ADICIONAR | CALCULAR | FECHAR 
             | MOSTRAR | BLOCO_SE | BLOCO_REPETIR | ATRIBUICAO ;

DEFINIR_CLIENTE = "CLIENTE" STRING "{" 
                    "tipo" "=" ("SELF_SERVICE" | "RODIZIO") ";"
                    "peso" "=" NUMBER ";"
                    "bebidas" "=" NUMBER ";"
                    "sobremesas" "=" NUMBER ";"
                  "}" ;

ADICIONAR    = "ADICIONAR_ITEM" STRING NUMBER ";" ;
CALCULAR     = "CALCULAR_PESO" NUMBER ";" ;
FECHAR       = "FECHAR_CONTA" ";" ;
MOSTRAR      = "MOSTRAR" (STRING | ATRIBUTO) ";" ;

BLOCO_SE     = "SE" CONDICAO "ENTAO" "{" {COMANDO} "}" ;
BLOCO_REPETIR = "REPETIR" NUMBER "VEZES" "{" {COMANDO} "}" ;

ATRIBUICAO   = IDENTIFIER "=" VALOR ";" ;
CONDICAO     = ATRIBUTO (">" | "<" | "==") VALOR ;
ATRIBUTO     = ("cliente" | "sistema") "." IDENTIFIER ;
VALOR        = NUMBER | STRING | ATRIBUTO ;
```

> 📄 Documentação completa em [docs/EBNF.md](docs/EBNF.md)

---

## 🧹 Limpeza

```bash
make clean      # Remove arquivos gerados
make distclean  # Remove tudo incluindo backups
```

---

## 📚 Referências

- [Flex Manual](https://westes.github.io/flex/manual/)
- [Bison Manual](https://www.gnu.org/software/bison/manual/)
- [Writing Your Own Toy Compiler](https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/)

---

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais como parte da disciplina de Lógica Computacional.

---

<p align="center">
  Feito com ❤️ por <a href="https://github.com/Gustavoms7">Gustavo Mendes</a>
</p>
