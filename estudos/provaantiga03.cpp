#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

char *f1a(const char *s)
{
    char *r = nullptr;
    int x = 0, y = 0;

    if (s)
    {
        while (*(s + x)) // contar x até a chegada do /0 na string S;
        {
            x++;
        }

        r = (char *)calloc(x + 1, sizeof(char));
        y = x;
        while (x >= 0)
        {
            *(r + y) = *(s + x);
            y--;
            x--;
        }
    }
    return r;
}

char *f2a (const char* s)
{
    char *r = nullptr;
    int x = 0, y = 0;

    if (s)
    {
        while (*(s + x)) // contar x até a chegada do /0 na string S;
        {
            x++;
        }

        r = (char*)calloc(x+1, sizeof(char));
        x--;
        while (x>=0)
        {
            *(r+y) = *(s+x);
            y++;
            x--;
        } 
    }    
    return r;
}

char *f3a (const char*s, const char c)
{
    char *r = nullptr;
    int x = 0, y = 0;

    if (s)
    {
        while (*(s + x)) // contar x até a chegada do /0 na string S;
        {
            x++;
        }

        r = (char*)calloc(x+2, sizeof(char));
        y = x;
        while(x >= 0)
        {
            *(r+x) = *(s+x);
            x--;
        }
        *(r+y) = c;
    }
    return r;
}
int main(void)
{
    char *s = f1a("abcde");
    printf("%s\n", s);

    char *t = f2a("abcde");
    printf("%s\n", t);

    char *v = f3a("abcd", 'e');
    printf("%s\n", v);
}
