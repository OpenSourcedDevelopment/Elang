#include <string.h>
#include <bool.h>
#include "stringlib.h" // for checking whitespace
#define DEFINE_SIZE 5

void preprocess(const char* src)
{
    static char* after_define = src;
    char* define_instance = strstr(after_define, "#define"); //might want to see if it fucks up bc off by one

    char* name = define_instance;
    bool whitespace = false;
    /* Should consider checking if they don't provide a name it loops forever.. */
    while(whitespace == false)
    {
        name++;
        if(is_whitespace(*name)) whitespace = true;
    }
        

}