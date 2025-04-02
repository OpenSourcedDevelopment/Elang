#include <string.h>
#include <bool.h>
#include <stdio.h>
#include "stringutil.h" // function is_whitespace
#define DEFINE_SIZE 5

void preprocess(const char* src)
{
    char* after_occurence = str;
    while(1) {
        char* occurence = strstr(after_occurence, "#define");
        if(occurence == NULL) 
            return;
        // The file has preprocessor directives.
        char* token = strtok(occurence + DEFINE_SIZE + 1, " ");
        if(token == NULL) 
        {
            fprintf(stderr, "The preprocessor has ran into a unexpected error.\n");
            return; 
        }
        char* name, value;
        for(int i = 0; i <= 2; i++) {
            token = strtok(NULL, " ");
            if(i == 1) {
                name = malloc(strlen(token)); 
            } else {
                value = malloc(strlen(token));
            }
        }
        replace_a(src, name, value);
        after_occurence = loop_until_whitespace(value);
        free(name);
        free(value);
    }
    return;
}