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
                return ( -1 );
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

    double getDouble ()
    {   
        // int i = 0;
        // bool r = true;
        // while(i < str.length() || r != false)
        // {   
        //     std::cout << i << std::endl;
            
        //     i++;
        // }

        // if(r == false)
        // {
        //     return ( 0.0 );
        // }
        // else
        // {
        //     return 1;
        // }
    }

    bool getBoolean ()
    {
        bool result = false;

        if(str == "T" || str == "true" || str == "1" || str == "TRUE")
        {
            result = true;
        }
        else if(str == "F" || str == "false" || str == "0" || str == "FALSE")
        {
            result = false;
        }
        
        return ( result );
    }

    bool contains (std::string text)
    {

    }

    /**  
     Funcao para converter letras para maiusculas. 
     @return valor equivalente em maiusculas, se houver; 
     o proprio valor, caso contrario 
    */
    std::string toUpperCase()
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
            else
            {
                str[i] = str[i];
            }
        }
        return str;
    }

    /**  
     Funcao para converter letras para minusculas. 
     @return valor equivalente em minusculas, se houver; 
     o proprio valor, caso contrario 
    */ 
    std::string toLowerCase()
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
            else
            {
                str[i] = str[i];
            }
        }
        return str;
    } 

    /**  
     Funcao para trocar todas as ocorrencias de certo caractere por outro novo. 
     @return valor com substituicoes, se houver; 
     o proprio valor, caso contrario 
    */ 
    std::string replace (char original, char novo)
    {   
        int i = 0;
        while(i < str.length())
        {
            if(str[i] == original)
            {
                str[i] = novo;
                i++;
            }
            i++;
        }
        return ( str );
    }

    /**  
     Funcao para codificar o conteudo segundo a cifra de César. 
     @return valor equivalente codificado, se houver; 
     o proprio valor, caso contrario 
    */ 
    std::string encrypt ()
    {   
        char aux = 0;

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'A' && str[i] <= 'W')
            {
                str[i] = str[i] + 3;
            }
            else if(str[i] >= 'X' && str[i] <= 'Z')
            {
                // str[i] = ((str[i] + 3) % 10) + 62;
                str[i] = str[i] - 23;
            }
        }
        return str;
    } 

    /**  
     Funcao para decodificar o conteudo previamente cifrado pela funcao acima. 
     @return valor equivalente decodificado, se houver; 
     o proprio valor, caso contrario 
    */ 
    std::string decrypt ()
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'D' && str[i] <= 'Z')
            {
                str[i] = str[i] - 3;
            }
            else if(str[i] >= 'A' && str[i] <= 'C')
            {
                str[i] = str[i] + 23;
            }
        }
        return str;
    }

    /**  
     Funcao para separar todas as sequencias de caracteres separadas por espaços em branco. 
     @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas 
     @return quantidade de sequencias de caracteres identificadas, se houver; 
     zero, caso contrario 
    */ 
    int split ( std::string sequencia [] )
    {

    }


    char* extra01 (char delimitador)
    {   
        int i = 0, count = 0;
        do
        {
            count++;
            i++;
        } while (str[i] != delimitador);
        // std::cout << count;

        char* aux = new char [count + 1];

        for(int i = 0; i < count; i++)
        {
            aux[i] = str[i];
        }

        aux[count+1] = '\0';

        return ( aux ); 
    }
};