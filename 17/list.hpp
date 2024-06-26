#include <iostream>

#define null NULL

class NODE
{
public:
    int data;
    NODE *next;

    NODE(int data)
    {
        this->data = data;
        next = null;
    }
};
class intCell
{
public:
    NODE *head;
    NODE *current;

    intCell()
    {
        head = null;
        current = null;
    }

    intCell(intCell *head, intCell *current)
    {
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

    intCell *setNpilha(intCell *cel, int n)
    {
        if (cel->head == nullptr)
        {
            NODE *a = new NODE(0);
            cel->head = a;
            cel->current = a;
        }

            for (int i = 1; i < n; i = i + 1)
            {
                NODE *b = new NODE(i);
                //  std::cout << "aq1";
                if (b != nullptr)
                {
                    // std::cout << "aq2";
                    cel->current->next = b;
                    cel->current = b;
                }
            }

        return cel;
    }

    intCell *push_back(intCell *cel, int x)
    {
        NODE *a = new NODE(x);
        if (cel->head == null)
        {
            cel->head = a;
            cel->current = a;
        }
        else
        {
            cel->current->next = a;
            cel->current = a;
        }
        return cel;
    }

    void print()
    {
        NODE *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
