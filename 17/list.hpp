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

    intCell *intStack_push(intCell *cel, int x)
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

    intCell *intStack_pop(intCell *cel)
    {
        if (cel->head == nullptr)
        {
            return nullptr;
        }

        if (cel->head == cel->current)
        {
            delete cel->head;
            cel->head = nullptr;
            cel->current = nullptr;
        }
        else
        {
            NODE *tmp = cel->head;

            while (tmp->next != cel->current)
            {
                tmp = tmp->next;
            }
            delete cel->current;
            cel->current = tmp;
            cel->current->next = nullptr;
        }
        return cel;
    }

    intCell *intStack_dup(intCell *cel)
    {
        if (cel->head == nullptr)
        {
            return nullptr;
        }

        NODE *dup = new NODE(cel->current->data);
        cel->current->next = dup;
        cel->current = dup;

        return cel;
    }

    intCell *intStack_swap(intCell *cel)
    {
        if (cel->head == nullptr)
        {
            return nullptr;
        }

        if (cel->head == cel->current)
        {
            return cel;
        }
        else
        {
            NODE *tmp = cel->current;
            cel->intStack_pop(cel);
            NODE *tmp2 = cel->current;
            cel->intStack_pop(cel);
            cel->intStack_push(cel, tmp->data);
            cel->intStack_push(cel, tmp2->data);
        }

        return cel;
    }

    intCell *intStack_invert(intCell *cel)
    {
        if (cel->head == nullptr)
        {
            return nullptr;
        }

        intCell *aux = new intCell();

        NODE *tmp1 = new NODE(cel->current->data);

        aux->intStack_push(aux, tmp1->data);

        while (cel->current != cel->head)
        {
            cel->intStack_pop(cel);
            NODE *tmp2 = new NODE(cel->current->data);
            aux->intStack_push(aux, tmp2->data);
        }

        return aux;
    }

    intCell *intQueue_push(intCell *cel, int x)
    {
        /**
         * Inserir no final
         */

        // NODE *tmp = new NODE(x);
        // if(cel->head == nullptr)
        // {
        //     cel->head = tmp;
        //     cel->current = tmp;
        // }
        // else
        // {
        //     cel->current->next = tmp;
        //     cel->current = tmp;
        // }

        // return cel;

        /**
         * Inserir no inicio
         */

        NODE *newNODE = new NODE (x);
        if(cel == nullptr)
        {
            cel->head = newNODE;
        }
        else
        {
            NODE *tmp = cel->head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNODE;
        }
        return cel;
    }

    intCell *intQueue_pop(intCell *cel)
    {
        if (cel->head == nullptr)
        {
            return nullptr;
        }

        if (cel->head == nullptr)
        {
            return nullptr;
        }

        cel->head = cel->head->next;

        // delete cel->head;

        return cel;
    }

    // int intQueue_compare(intCell *aux1, intCell *aux2)
    // {
    //     NODE *tmp1 = new NODE(aux1->head->data);
    //     NODE *tmp2 = new NODE(aux2->head->data);
    // }

    intCell *intQueue_join(intCell *aux1, intCell *aux2)
    {
        if (aux1->head == nullptr)
        {
            aux1->head = aux2->head;
            aux1->current = aux2->current;
        }
        else
        {
            aux1->current->next = aux2->head;
            aux1->current = aux2->current;
        }
        return aux1;
    }

    int intQueue_search(intCell *cel, int x)
    {
        int n = 0;

        NODE *current = cel->head;

        while (current != nullptr)
        {
            if (current->data == x)
            {
                n = 1;
            }
            current = current->next;
        }

        return n;
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
