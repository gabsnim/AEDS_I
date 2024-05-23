#include <stdlib.h>
#include <stdio.h>

int my_strlen (char* string)
{
    int count = 0;
    if(string)
    {
        while (string[count] != '\0')
        {
            count = count + 1;
        }
    }
    return count;
}

char* str_push_back (char* str, char c)
{
    int len = my_strlen(str);
    char* auxstr = (char*)calloc(len + 2, sizeof(char));
    
    for(int i = 0; i < len; i++)
    {
        auxstr[i] = str[i];
    }

    auxstr[my_strlen(str)] = '\0';
    str = (char*)calloc(len + 2, sizeof(char));

    str = auxstr;

    str[len] = c;

    return str;
}