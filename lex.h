//lex.h
#pragma once

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum  {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_BOOL,
    TOKEN_VOID,

    TOKEN_USING,
    TOKEN_HERE,
    TOKEN_FUNCTION,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_ASSIGN,
    TOKEN_BAND,           // &&
    TOKEN_BOR,            // ||
    TOKEN_XOR,            // ^
    TOKEN_PLUS_ASSIGN,    // +=
    TOKEN_MINUS_ASSIGN,   // -=
    TOKEN_MULTIPLY_ASSIGN,// *=
    TOKEN_DIVIDE_ASSIGN,  // /=
    TOKEN_EQUAL,          // ==
    TOKEN_NOT_EQUAL,      // !=
    TOKEN_GREATER,        // >
    TOKEN_GREATER_EQUAL,  // >=
    TOKEN_LESS,           // <
    TOKEN_LESS_EQUAL,     // <=
    TOKEN_AND,            // &
    TOKEN_OR,             // |

    TOKEN_POINTER,        // *
    TOKEN_ADDRESS_OF,     // &

    TOKEN_COMMA,          // ,
    TOKEN_SEMICOLON,      // ;
    TOKEN_PERIOD,         // .

    TOKEN_BRACKET_L,      // (
    TOKEN_BRACKET_R,      // )
    TOKEN_CURLY_L,        // {
    TOKEN_CURLY_R,        // }

    TOKEN_COMMENT,        // // (single-line comment)

    TOKEN_NAME,           // Variable, function names

    TOKEN_INTEGER_LITERAL,// Integer literal (e.g., 5)
    TOKEN_FLOAT_LITERAL,  // Floating-point literal (e.g., 3.14)
    TOKEN_STRING_LITERAL, // String literal (e.g., "Hello World")
    TOKEN_BOOL_LITERAL,   // Boolean literal (true or false)

    TOKEN_EOF             // End of file/input
} TokenType;

enum NODE_TYPE {
    ROOT_NODE,
    NORM_NODE
};

typedef struct
{
    char* source;
    char* pos;
    size_t length;
    RootNode* ROOT_START;
    char* lastTokenEnd;
} Lexer;

typedef struct 
{
    struct RootNode* next;
    struct RootNode* prev;
    Node* left;
    Node* right;
} RootNode;

typedef struct 
{
    bool PARENT_TYPE;
    void* parent;
    struct Node* left;
    struct Node* right;
    Token* token;
} Node;

typedef struct
{
    TokenType type;
    char* value;
    size_t line;
} Token;

void lexer_setsource(const char* src, Lexer* lexer);
void lexer_advance(void);
void lexer_process(Lexer* lexer);