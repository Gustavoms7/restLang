# Makefile para gerar parser e executar VM
all: parser vm

parser: parser.tab.c lex.yy.c
	gcc -o parser parser.tab.c lex.yy.c -lfl

parser.tab.c parser.tab.h: parser.y
	bison -d -o parser.tab.c parser.y

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

vm: vm.c
	gcc -o vm vm.c -std=c99

clean:
	rm -f parser parser.tab.c parser.tab.h lex.yy.c lex.yy.o parser.o vm saida.asm
