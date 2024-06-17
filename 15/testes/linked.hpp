#include <iostream>
#include <cstdlib>

class NODE
{
    public:

    char data;
    NODE* next;

    NODE (char value)
    {
        data = value;
        next = nullptr;
    }

};

class LinkedList
{
    private: 
    NODE *head;         // ponteiro para o primeiro nó da lista (cabeça da lista)
    NODE *last;

    public:

    /**
     * Construtor padrao
     */
    LinkedList ()
    {
        head = nullptr;    // Construtor que inicializa head como nullptr, indicando que a lista está vazia no começo
        last = nullptr;
    }

    void insert (char value)
    {
        NODE* newNode = new NODE (value);  // Cria um novo nó com o valor fornecido
        newNode->next = head;   // Define o próximo nó como o atual head
        head = newNode; // Atualiza o head para o novo nó
                last = head;
    }

    void display ()
    {
        NODE* temp = last; // ponteiro temporário para percorrer a lista
        while (temp != nullptr)
        {   
            std::cout << temp->data << " -> ";
            temp = temp->next; // avança para o próximo nó
        }
        std::cout << nullptr << std::endl;
    }
};