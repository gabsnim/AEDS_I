#include <iostream>

#define null NULL


class NODE 
{
    public:
    int data;
    NODE* next;

    NODE(int data)
    {
        this->data = data;
        next = null;
    }
};
class intCell
{
    public:
    NODE* head;
    NODE* current;

    intCell ()
    {
        head = null;
    }

    // ~intCell ()
    // {
    //     while (current != null)
    //     {
    //         NODE* aux = head->next;
    //         delete aux;
    //         current = aux;      
    //     }       
    // }

        

};
