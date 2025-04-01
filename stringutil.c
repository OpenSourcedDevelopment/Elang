#include <stdbool.h>
#include <ctype.h>
#include <string.h>
/**
 * too lazy to write documentation rn
 * @brief Loop until no whitespace
 * 
 * @param c 
 * @return int 
 */
int loop_until_no_whitespace(char* c) {
    while(*c != '\0' && isspace(*c))
        c++;
    return c;
}

int loop_until_whitespace(char* c) {
    while(*c != '\0' && !isspace(*c))
        c++;
    return c;
}

char* replace(const char* str, const char* before, const char* new) {
    size_t str_len = strlen(str);
    size_t before_len = strlen(before);
    size_t new_len = strlen(new);
    
    char* dummyStr = (char* )malloc(str_len);
    
    char* after_last_occurence = str;
    size_t occurences = 0;
    
    while(1)
    {
        
    char* occurence = strstr(str, before);
    if(occurence == NULL) break;  
    after_last_occurence = loop_until_whitespace(occurence);
    occurences++;
        
    }
    if(occurences == 0) return NULL;

    // Get the length of all chars in each occurence, subtract from STR, 
    size_t new_str_len = str_len - (occurences * before_len) + (occurences * new_len);
    char* new_space = (char* )malloc(new_str_len) + 1;
    if(new_space == NULL) 
        return new_space;



}