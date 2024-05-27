#include <iostream>    // para entradas e saidas
#include <fstream>     // para arquivos
#include <sstream>     // para conversoes
#include <string>      // para cadeias de caracteres
#include <iomanip>     // para formatacao de entradas e saidas


class MyString
{
    private:
    std::string s;

    public:

    MyString()
    {
        this->s = "0";
    }

    
    std::string getString ()
    {
        return this->s;
    }

    void readString ()
    {
        std::cout << "Digite a string " << std::endl;
        std::cin >> s;
    }

    int toInt ()
    {
        if(s.length() <= 0)
        {
            
        }
        else
        {

        }
    }
};