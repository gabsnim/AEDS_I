#include <iostream> // para entradas e saidas
#include <fstream>  // para arquivos
#include <sstream>  // para conversoes
#include <string>   // para cadeias de caracteres
#include <iomanip>  // para formatacao de entradas e saidas

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

//     /**
//      * Saber se a cadeia so tem digitos, pontos ou virgula
//     */

//    bool getIsOk ()
//    {
//         bool a = true;
//         for(int i = 0; i < str.length(); i++)
//         {
//             if(str[i] >= '0' && str[i] <= '9')
//             {
//                 a = a;
//             }
//             else if(str[i] == '.' || str[i] == ',')
//             {
//                 a = a;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//    }

    /**
     * Converter string para inteiro
     */
    
    int getInt()
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '.' || str[i] == ',')
            {
                //setar erro;
                
            }
        }
    }
};