# Compilador e flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lfl

# Arquivos fonte
LEXER = lexer.l
PARSER = parser.y
VM = restvm.c

# Arquivos gerados
LEX_OUT = lex.yy.c
PARSER_OUT = parser.tab.c
PARSER_HEADER = parser.tab.h

# Executáveis
COMPILER = rest_parser
VM_EXEC = restvm

# Alvo principal
all: $(COMPILER) $(VM_EXEC)

# Gerar parser com Bison
$(PARSER_OUT) $(PARSER_HEADER): $(PARSER)
	bison -d $(PARSER)

# Gerar lexer com Flex
$(LEX_OUT): $(LEXER) $(PARSER_HEADER)
	flex -o $(LEX_OUT) $(LEXER)

# Compilar o compilador (parser + lexer)
$(COMPILER): $(PARSER_OUT) $(LEX_OUT)
	$(CC) $(CFLAGS) -o $(COMPILER) $(PARSER_OUT) $(LEX_OUT) $(LDFLAGS)

# Compilar a VM
$(VM_EXEC): $(VM)
	$(CC) $(CFLAGS) -o $(VM_EXEC) $(VM)

# Testar um arquivo específico
test: $(COMPILER) $(VM_EXEC)
	@echo "=== Compilando sample.rest ==="
	./$(COMPILER) sample.rest
	@echo "=== Executando na VM ==="
	./$(VM_EXEC)

# Rodar todos os testes
test-all: $(COMPILER) $(VM_EXEC)
	@for f in tests/*.rest; do \
		echo "=== Testando $$f ==="; \
		./$(COMPILER) $$f && ./$(VM_EXEC); \
		echo ""; \
	done

# Limpar arquivos gerados
clean:
	rm -f $(LEX_OUT) $(PARSER_OUT) $(PARSER_HEADER) $(COMPILER) $(VM_EXEC) out.asm

# Limpar tudo incluindo backups
distclean: clean
	rm -f *~ *.bak

.PHONY: all clean distclean test test-all
