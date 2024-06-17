#include <iostream>
#include <cstdlib>


class MyString
{
private:
    char *str;
    int length;
    unsigned int size;

public:
    /**
     * Construtor padrao
     */

    MyString()
    {
        length = 80;
        str = new char[length + 1];
        size = 0;
    }

    // void setString(char *str)
    // {
    //     this->str = str;
    // }

    void setString(char *s)
    {
        int x = 0;
        if (s)
        {
            while (*(s + x)) // semelhante ao ! '\0';
            {
                *(str + x) = *(s + x);
                x++;
            }
            *(str + x) = '\0';
            // std::cout << "x = " << x << std::endl;
            size = strLen();
        }
    }

    char *getString()
    {
        return this->str;
    }

    int getSize()
    {
        return this->size;
    }

    char getCharPosition (int position)
    {
        return this-> str[position];
    }

    int strLen()
    {
        int count = 0;
        if (str)
        {
            while (*(str + count))
            {
                count++;
            }
        }
        return count;
    }

    char *str_push_back(char c)
    {
        int x = 0;
        char *aux = str;
        if (str && (int)size < length)
        {
            while (*(str + x)) // enquanto ! '\0'
            {
                x++;
            }
            *(str + x) = c;
            size++;
            *(str + x + 1) = '\0';
        }
        str = aux;

        return str;
    }

    char *str_pop_back()
    {
        int x = 0;

        if (str && size > 0)
        {
            while (*(str + x))
            {
                x++;
            }
            *(str + x - 1) = '\0';
        }
        return str;
    }

    char *str_push_front(char c)
    {
        int x = 0;

        if (str && size < length)
        {
            for (int i = size; i > 0; i--)
            {
                *(str + i) = *(str + i - 1);
            }
            *(str + x) = c;
            size++;
            *(str + size) = '\0';
        }
        return str;
    }

    char *str_pop_front()
    {
        int x = 0;
        if (str && size > 0)
        {
            *(str + size) = '\0';
            for (int i = 0; i < size; i++)
            {
                *(str + i) = *(str + i + 1);
            }
            *(str + size - 1) = '\0';
            size--;
        }
        return str;
    }

    char *str_push_mid(char c)
    {
        if (str && size >= 2)
        {
            for (int i = size; i > size / 2; i--)
            {
                *(str + i) = *(str + i - 1);
            }
            *(str + (size / 2)) = c;
            size++;
            *(str + size) = '\0';
        }
        return str;
    }

    char *str_pop_mid()
    {
        if (str && size < length)
        {
            if (size <= 2)
            {
                *(str + 0) = *(str + 1);
                *(str + 1) = '\0';
                size--;
            }
            else
            {
                for (int i = size / 2; i < size; i++)
                {
                    *(str + i) = *(str + i + 1);
                }
                *(str + size) = '\0';
                size--;
            }
        }
        return str;
    }

    char *str_insert(char c, int index)
    {
        if (str && size < length)
        {
            // index--;  // index posicao 3 -> abXde // index 3 na cadeia -> abdXe
            for (int i = size; i > index; i--)
            {
                *(str + i) = *(str + i - 1);
            }
            *(str + index) = c;
            size++;
            *(str + size) = '\0';
        }
        return str;
    }

    char *str_insert2(char c, int index) // trocar o caracter;
    {
        if (str)
        {
            *(str + index) = c;
        }
        return str;
    }

    char *str_remove(int index)
    {
        if (str)
        {
            for (int i = index; i < size; i++)
            {
                *(str + i) = *(str + i + 1);
            }
            size--;
            *(str + size) = '\0';
        }
        return str;
    }

    int str_chr(char c)
    {
        int i = 0;
        bool a = true;
        if (str)
        {
            while (*(str) && a == true)
            {
                if (*(str + i) == c)
                {
                    a = false;
                }
                i++;
            }
        }
        return i-1;
    }

    char* str_tok (char delimiter)
    {   
        bool a = true;
        if(str)
        {
            int i = 0;
            while (*(str + i) && a == true)
            {
                if(*(str + i) == delimiter)
                {
                    *(str + i) = '\0';
                    a = false;
                }
                i++;
            }
            size = size - (i-2);
        }
        if(a == true)
        {
            str = nullptr;
        }
        return str;
    }
};