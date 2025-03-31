CFLAGS = -Wextra -Wall

build:
    gcc -o main.c lex.c preprocessor.c stringlib.c $(CFLAGS) out.o

run:

clean: