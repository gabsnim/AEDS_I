/*
   Contato.hpp  - v0.0. - __ / __ / _____
   Author: _______________________

 */

// ----------------------------------------------- definicoes globais

#ifndef _CONTATO_H_
#define _CONTATO_H_

// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo


// outras dependencias

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )

#include "Erro.hpp"


class Contato
{
    private:

    std::string nome;
    std::string fone;
    int n_fone;

    
    bool foneIsvalid ()
    {
        bool r = false;

        if(fone.length() > 0)
        {
            r = true;
        }

        return r;
    }


    public:
    /**
        Construtor padrao
    */
    Contato()
    {
        nome = "AAAAAAA";
        fone = "9999-9999";
        n_fone = 1;
    }

    Contato (std::string nome, std::string fone, int x)
    {
        this->nome = nome;
        this->fone = fone;
        this->n_fone = x;
    }

    void setNome (std::string nome)
    {
        this->nome = nome;
    }

    void setFone (std::string nome)
    {
        this->nome = nome;
    }

    void setNfone (int x)
    {
        this->n_fone = x;
    }

    void readName ()
    {
        std::cout << "Digite o nome para cadastro: " << std::endl;
        std::cin >> nome;
    }

    void readPhone ()
    {
        std::cout << "Digite o telefone para cadastro: " << std::endl;
        std::cin >> fone;
    }

    void readn_Phone ()
    {
        std::cout << "Digite o numero de telefones para cadastro: " << std::endl;
        std::cin >> n_fone;
    }

    std::string getNome ()
    {
        return this->nome;
    }

    std::string getFone ()
    {
        return this->fone;
    }

    int getN_fone ()
    {
        return this->n_fone;
    }

    void print ()
    {
        std::cout << getNome() << std::endl;
        std::cout << getFone() << std::endl;
        std::cout << getN_fone() << std::endl;
        std::cout << std::endl;
    }
};

#endif