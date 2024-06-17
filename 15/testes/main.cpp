#include "linked.hpp"



int main ( void )
{
    LinkedList lista;
    // lista.insert('a');
    // lista.insert('b');
    // lista.insert('c');
    for(int i = 0; i < 10; i++)
    {
        lista.insert('a'+i);
    }
    lista.display();
 
    return 0;
}