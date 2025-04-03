#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* loop_until_no_whitespace(char* c) 
{
    while(*c != '\0' && isspace(*c))
        c++;
    return c;
}

char* loop_until_whitespace(char* c) 
{
    while(*c != '\0' && !isspace(*c))
        c++;
    return c;
}

char* replace_a(char* str, const char* before, const char* new)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = str;
    size_t before_len = strlen(before);
    size_t repl_len = strlen(new);

    while (1) {
        const char *p = strstr(tmp, before);

        // walked past last occurrence of before; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before before
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy new string
        memcpy(insert_point, new, repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + before_len;
    }

    // write altered string back to str
    strcpy(str, buffer);
}