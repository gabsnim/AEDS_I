#include <iostream>
#include <cstdlib>
#include "Erro.hpp"

class NODE
{
    public:
    int data;
    class NODE *next;

    NODE (int x)
    {
        this->data = x;
        next = nullptr;
    }

};


class MyString : public Erro
{
      
};