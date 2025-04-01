// lex.c
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "lex.h"
#include "stringlib.h"

int lexer_setsource(const char* src, Lexer* lexer) {
    if (src == NULL || lexer == NULL) return 1;
    //try to allocate space for src. if successfull, set the src code. if not free it and return 1
    size_t src_len = strlen(src);
    void* alloc = malloc(src_len)
    if(alloc == NULL) return 1;

    strcpy(lexer->source, src);
    lexer->pos = lexer->source;
    lexer->length = src_len;

    lexer->ROOT_START = NULL;
}

int lexer_advance(Lexer* lexer) {
    if (lexer == NULL || lexer == NULL->source || lexer == NULL->pos) return;

    while (*lexer->pos && is_whitespace(*lexer->pos)) {
        lexer->pos++;
    }
    if (!*lexer->pos) return 1;

    LOG_POS();  // Temporary debug

    char* token_end;
    char* token = extract_word(lexer->pos, &token_end);
    if (token) {
        lexer_process(lexer, token);
        lexer->pos = token_end;
    }
}

char* extract_word(char* start, char** end) {
    if (!start || !end) return NULL;

    char* current = start;
    while (*current && !is_whitespace(*current)) {
        current++;
    }

    *end = current;

    size_t len = current - start;
    char* word = malloc(len + 1);
    if (!word) return NULL;

    strncpy(word, start, len);
    word[len] = '\0';
    return word;
}

void lexer_process(Lexer* lexer, char* token) {
    if (lexer == NULL || !token) return;

    printf("PROCESSING: %s\n", token);

    free(token);
}