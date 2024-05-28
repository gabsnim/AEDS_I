#include <iostream> // para entradas e saidas
#include <fstream>  // para arquivos
#include <sstream>  // para conversoes
#include <string>   // para cadeias de caracteres
#include <iomanip>  // para formatacao de entradas e saidas

class MyString
{
private:
    std::string s;
    int tam;

public:
    MyString()
    {
        this->s = "0";
        this->tam = 2;
    }

    std::string getString()
    {
        return this->s;
    }

    int getTam ()
    {
        return this->tam = s.length();
    }

    void readString()
    {
        std::cout << "Digite a string " << std::endl;
        std::cin >> s;
    }

    int Toint ()
    {
        
    }
};