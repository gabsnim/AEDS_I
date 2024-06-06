#include <iostream> // para entradas e saidas
#include <fstream>  // para arquivos
#include <sstream>  // para conversoes
#include <string>   // para cadeias de caracteres
#include <iomanip>  // para formatacao de entradas e saidas
#include <math.h>

class MyString
{
private:
    std::string str;

public:
    /**
     * Construtor padrao
     */
    MyString()
    {
        str = "0";
    }

    /**
     * Construtor alternativo
     */
    MyString(std::string s)
    {
        this->str = s;
    }

    /**
     * Definir a string
     */

    void setString(std::string s)
    {
        this->str = s;
    }

    /**
     * Retornar a string
     */

    std::string getString()
    {
        return this->str;
    }

    /**
     * Converter string para inteiro
     */

    int getInt()
    {
        int x = 0;
        int sum = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.' || str[i] == ',')
            {
                // setar erro;
            }
        }

        int i = str.size();
        int j = 0;
        int y = 0;

        while(i-1 > 0)
        {   
            x = str[j] - 48;
            y = pow(10, i-1);
            sum+= x * y;
            i--;
            j++;
        }
        
        sum+= str[j] - 48;;

        return sum;
    }
};