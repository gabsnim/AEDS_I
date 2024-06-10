#include <iostream> // para entradas e saidas
#include <fstream>  // para arquivos
#include <sstream>  // para conversoes
#include <string>   // para cadeias de caracteres
#include <iomanip>  // para formatacao de entradas e saidas
#include <math.h>
#include "Erro.hpp"

class MyString : public Erro
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
         Funcao para converter conteudo para valor inteiro, se possivel.
         @return valor inteiro equivalente, se valido;
                       (-1), caso contrario
      */
    int getInt()
    {
        int x = 0;
        int sum = 0;

        if (str.empty())
        {
            setErro(1);
            return (-1);
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '.' || str[i] == ',')
                {
                    setErro(1);
                    return (-1);
                }
            }

            int i = str.size();
            int j = 0;
            int y = 0;

            while (i - 1 > 0)
            {
                x = str[j] - 48;
                y = pow(10, i - 1);
                sum += x * y;
                i--;
                j++;
            }
            sum += str[j] - 48;
        }
        return sum;
    }

    /**
         Funcao para converter conteudo para valor real, se possivel.
         @return valor real equivalente, se valido;
                       (0.0), caso contrario
      */
    double getDouble()
    {
        double sum = 0.0;
        bool negativo = false;
        bool Pdecimal = true;
        double decimal = 0.1;
        int i = 0;
        if (str.empty())
        {
            setErro(2);
            return 0.0;
        }
        else
        {
            if (str[0] == '-')
            {
                negativo = true;
                i++;
            }

            while (str[i] != '\0' && str[i] != '.')
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    sum = sum * 10 + (str[i] - 48);
                }
                else
                {
                    setErro(2);
                    return 0.0;
                }
                i++;
            }

            if (negativo)
            {
                sum *= -1;
            }

            if (str[i] == '.')
            {
                i++;

                while (str[i] != '\0')
                {
                    if (str[i] >= '0' && str[i] <= '9')
                    {
                        sum += (str[i] - 48) * decimal;
                        decimal *= 0.1;
                    }
                    else
                    {
                        setErro(2);
                        return 0.0;
                    }
                    i++;
                }
            }

            return sum;
        }
    }

    /**
         Funcao para converter conteudo para valor lógico, se possivel.
         Nota: Considerar válidos: { true, false, T, F, 0, 1 }
         @return valor logico equivalente, se valido;
                       false, caso contrario
      */
    bool getBoolean()
    {
        bool result = false;

        if (str == "T" || str == "true" || str == "1" || str == "TRUE")
        {
            result = true;
        }
        else if (str == "F" || str == "false" || str == "0" || str == "FALSE")
        {
            result = false;
        }
        else
        {
            setErro(3);
            result = false;
        }
        return (result);
    }

    /**
         Funcao para verificar se o parametro esta’ contido no conteudo.
         @return true , se contiver (em qualquer posicao);
                       false, caso contrario
      */
    bool contains(std::string text)
    {
        bool r = false;
        int i = 0, j = 0;
        if (text.length() > 0 && text.length() <= str.length())
        {
            while (i < str.length())
            {
                if (str[i] == text[j])
                {
                    j++;
                }
                if (j == text.length())
                {
                    r = true;
                }
                i++;
            }
        }
        else
        {
            setErro(4);
        }
        return r;
    }

    /**
     Funcao para converter letras para maiusculas.
     @return valor equivalente em maiusculas, se houver;
     o proprio valor, caso contrario
    */
    std::string toUpperCase()
    {
        if (str.empty())
        {
            setErro(5);
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    str[i] = str[i] - 32;
                }
                else
                {
                    str[i] = str[i];
                }
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
        if (str.empty())
        {
            setErro(6);
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    str[i] = str[i] + 32;
                }
                else
                {
                    str[i] = str[i];
                }
            }
        }
        return str;
    }

    /**
     Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
     @return valor com substituicoes, se houver;
     o proprio valor, caso contrario
    */
    std::string replace(char original, char novo)
    {
        int i = 0;
        if (str.empty())
        {
            setErro(7);
        }
        else
        {
            while (i < str.length())
            {
                if (str[i] == original)
                {
                    str[i] = novo;
                    i++;
                }
                i++;
            }
        }
        return (str);
    }

    /**
     Funcao para codificar o conteudo segundo a cifra de César.
     @return valor equivalente codificado, se houver;
     o proprio valor, caso contrario
    */
    std::string encrypt()
    {
        char aux = 0;

        if (str.empty())
        {
            setErro(8);
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 'A' && str[i] <= 'W')
                {
                    str[i] = str[i] + 3;
                }
                else if (str[i] >= 'X' && str[i] <= 'Z')
                {
                    // str[i] = ((str[i] + 3) % 10) + 62;
                    str[i] = str[i] - 23;
                }
            }
        }
        return str;
    }

    /**
     Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
     @return valor equivalente decodificado, se houver;
     o proprio valor, caso contrario
    */
    std::string decrypt()
    {
        if (str.empty())
        {
            setErro(9);
        }
        else
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] >= 'D' && str[i] <= 'Z')
                {
                    str[i] = str[i] - 3;
                }
                else if (str[i] >= 'A' && str[i] <= 'C')
                {
                    str[i] = str[i] + 23;
                }
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
    int split(std::string sequencia[])
    {
        setErro(10);
    }

    char *extra01(char delimitador)
    {
        // int i = 0, count = 0;
        // do
        // {
        //     count++;
        //     i++;
        // } while (str[i] != delimitador);
        // // std::cout << count;

        // char* aux = new char [count + 1];

        // for(int i = 0; i < count; i++)
        // {
        //     aux[i] = str[i];
        // }

        // aux[count+1] = '\0';

        // return ( aux );

        int count = 0;
        int size = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == delimitador)
            {
                count++;
            }
        }

        size = str.length() + count;
        char *aux = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            if (str[i] != delimitador)
            {
                aux[i] = str[i];
            }
            else
            {
                aux[i] = ' ';
            }
        }

        return aux;
    }

    std::string extra02()
    {
        char aux;
        int x = str.length();
        for (int i = 0; i < str.length() / 2; i++)
        {
            aux = str[i];
            str[i] = str[x - 1 - i];
            str[x - 1 - i] = aux;
        }
        return str;
    }

    std::string getErroMsg()
    {
        std::string erroMsg = "";

        switch (getErro())
        {
        case 0:
            erroMsg = NO_ERROR;
            break;
        case 1:
            erroMsg = "[ERRO] Nao foi possivel converter para inteiro.";
            break;
        case 2:
            erroMsg = "[ERRO] Nao foi possivel converter para real.";
            break;
        case 3:
            erroMsg = "[ERRO] Nao foi possivel converter para valor logico.";
            break;
        case 4:
            erroMsg = "[ERRO] Nao foi possivel encontrar a substring.";
            break;
        case 5:
            erroMsg = "[ERRO] Nao foi possivel converter para maiusculas.";
            break;
        case 6:
            erroMsg = "[ERRO] Nao foi possivel converter para minusculas.";
            break;
        case 7:
            erroMsg = "[ERRO] Nao foi possivel trocar um caractere por outro.";
            break;
        case 8:
            erroMsg = "[ERRO] Nao foi possivel codificar a string.";
            break;
        case 9:
            erroMsg = "[ERRO] Nao foi possivel decodificar a string.";
            break;
        case 10:
            erroMsg = "[ERRO] Nao foi possivel separar as cadeias de caractere.";
            break;
        default:
            erroMsg = "Codigo de erro invalido.";
            break;
        }

        return (erroMsg);
    }
};