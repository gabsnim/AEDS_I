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
    std::string fone2;
    std::string Phones[10];
    int n_fone;
    std::string endResidencial;
    std::string endProfissional;

    bool foneIsvalid()
    {
        bool r = true;
        int i = 0;

        while (i < fone.length() && r)
        {
            if (('0' > fone[i] || fone[i] > '9') && fone[i] != '-')
            {
                r = false;
            }
            i++;
        }

        return r;
    }

    bool fone2Isvalid()
    {
        bool r = true;
        int i = 0;

        while (i < fone2.length() && r)
        {
            if (('0' > fone2[i] || fone2[i] > '9') && fone2[i] != '-')
            {
                r = false;
            }
            i++;
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
        fone = "";
        fone2 = "";
        n_fone = 0;
        endProfissional = "";
        endResidencial = "";
    }

    Contato(std::string nome, std::string fone, std::string fone2)
    {
        this->nome = nome;
        this->fone = fone;
        this->fone2 = fone2;

        if (foneIsvalid())
        {
            Phones[0] = fone;
            n_fone = n_fone + 1;
        }

        if (fone2Isvalid())
        {
            Phones[1] = fone2;
            n_fone = n_fone + 1;
        }
    }

    Contato(std::string nome, int n_fones)
    {
        this->nome = nome;
        this->n_fone = n_fone;
        Phones[n_fone];
    }

    void setNome(std::string nome)
    {
        this->nome = nome;
    }

    void setPhone1(std::string fone)
    {
        this->Phones[0] = fone;
    }

    void setPhone2(std::string fone)
    {
        this->Phones[1] = fone;
    }

    void removePhone2 ()
    {
        if(n_fone == 2)
        {
            this->Phones[1] = "";
            this->n_fone = n_fone - 1;
        }
    }

    void setFone(std::string fone)
    {
        this->fone = fone;
    }

    void setFone2(std::string fone2)
    {
        this->fone2 = fone2;
    }

    void setNfone(int x)
    {
        this->n_fone = x;
    }

    void readName()
    {
        std::cout << "Digite o nome para cadastro: " << std::endl;
        std::cin >> nome;
    }

    void readPhone()
    {
        std::cout << "Digite o telefone para cadastro: " << std::endl;
        cin >> fone;
        if (!foneIsvalid())
        {
            this->fone = "-1";
            n_fone = 0;
        }

        Phones[n_fone] = fone;
        n_fone = n_fone + 1;
    }

    void readPhone2()
    {
        std::cout << "Digite o segundo telefone para cadastro: " << std::endl;
        cin >> fone2;
        if (!fone2Isvalid())
        {
            this->fone2 = "-1";
            n_fone = 1;
        }

        Phones[n_fone] = fone2;
        n_fone = n_fone + 1;
    }

    void setEndProfissional (std::string end)
    {
        this->endProfissional = end;
    }

    void setEndResidencial (std::string end)
    {
        this->endResidencial = end;
    }

    std::string getNome()
    {
        return this->nome;
    }

    std::string getFone()
    {
        return this->fone;
    }

    std::string getFone2()
    {
        return this->fone2;
    }

    int getNfone()
    {
        return this->n_fone;
    }

    std::string getEndResidencial ()
    {
        return this->endResidencial;
    }

    std::string getEndProfissional ()
    {
        return this->endProfissional;
    }

    void print()
    {
        std::cout << "Nome: " << getNome() << std::endl;
        std::cout << "Fone1: " << getFone() << std::endl;
        std::cout << "Fone2: " << getFone2() << std::endl;
        std::cout << std::endl;
    }

    void read()
    {
        std::cout << "Digite o nome: " << std::endl;
        std::cin >> nome;

        std::cout << "Digite a quantidade de telefones: " << std::endl;
        std::cin >> n_fone;

        for (int i = 0; i < n_fone; i++)
        {
            std::cout << "Digite o telefone " << (i + 1) << ": " << std::endl;
            std::cin >> Phones[i];
            fone = Phones[i];
            if (!foneIsvalid())
            {
                Phones[i] = "-1";
            }
        }
        std::cout << "Digite o endereco profissional: " << std::endl;
        std::cin >> endProfissional;
        std::cout << "Digite o endereco residencial: " << std::endl;
        std::cin >> endResidencial;
    }

    void newPrint()
    {
        std::cout << "Nome: " << getNome() << std::endl;
        std::cout << "Quantidade de telefones: " << getNfone() << std::endl;
        for (int i = 0; i < n_fone; i++)
        {
            std::cout << "telefone " << (i + 1) << ": " << Phones[i] << std::endl;
        }
        std::cout << "Endereco Profissional: " << getEndProfissional() << std::endl;
        std::cout << "Endereco Residencial: " << getEndResidencial() << std::endl;
        std::cout << std::endl;
    }

    void readFromFile(std::string fileName)
    {
        std::ifstream file;

        int n = 0; // quantidade de dados
        std::string tempName;
        std::string tempFone;

        file.open(fileName);

        file >> n; // guardar quantidade de dados

        if (n <= 0)
        {
            cout << "Quantidade de dados invalida. " << std::endl;
        }
        else
        {
            file >> tempName;
            file >> tempFone;

            this->nome = tempName;
            this->fone = tempFone;

            if (!foneIsvalid()) // caso o telefone venha antes do fone;
            {
                this->fone = tempName;
                this->nome = tempFone;
            }
        }
    }

    void writeToFile(std::string fileName)
    {
        std::ofstream file;

        file.open(fileName);

        if (file.is_open())
        {
            file << this->nome << std::endl;
            file << this->fone << std::endl;
            file << this->n_fone << std::endl;
        }
    }
};

#endif