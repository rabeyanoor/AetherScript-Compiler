BISON = ../local_bison/usr/bin/bison
FLEX = flex
CC = gcc
CFLAGS = -Wall -g

minilang: lexer.l parser.y main.c ast.c ast.h
	BISON_PKGDATADIR=../local_bison/usr/share/bison $(BISON) -d parser.y
	$(FLEX) lexer.l
	$(CC) $(CFLAGS) lex.yy.c parser.tab.c main.c ast.c -o minilang

clean:
	rm -f minilang lex.yy.c parser.tab.c parser.tab.h
