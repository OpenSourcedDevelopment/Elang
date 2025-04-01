#include <string.h>
#include <bool.h>
#include "stringlib.h" // function is_whitespace
#define DEFINE_SIZE 5

void preprocess_lex(const char* src)
{
    /* Should see if all of the code below malfunctions because of Off-by-one-error*/
    char* define_instance = strstr(after_src, "#define");
    char* name =  loop_until_no_whitespace(define_instance + DEFINE_SIZE + 1);
    char* after_name = loop_until_whitespace(name);
    char* value = loop_until_no_whitespace(after_name);
    char* value_end = loop_until_whitespace(value);

}