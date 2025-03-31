//main.c
#include <stdio.h>
#include "lex.h"

int main() {
	Lexer lexer;
	lexer.pos = NULL;
	lexer.source = NULL;
	lexer.length = 0;

	char src[] = "t";
	lexer_setsource(&src, &lexer);
	printf("%s\n", lexer.source);
	printf("%d\n", lexer.pos);
	printf("%d\n", lexer.length);
}