#include <iostream>

#define null NULL

class intCell
{
private:
    int data;       // dado
    intCell *left;  // anterior
    intCell *right; // proximo

public:
    intCell()
    {
        int data = 0;
        left = null;
        right = null;
    }

    intCell(int value, intCell *ant, intCell *prox)
    {
        this->data = value;
        this->left = ant;
        this->right = prox;
    }

    int getTam(intCell *list)
    {
        if (list == null)
        {
            return 0;
        }
        int count = 0;
        while (list != null)
        {
            count++;
            list = list->right;
        }
        return count;
    }

    void print()
    {
        intCell *tmp = this;
        while (tmp)
        {
            printf("%d ", tmp->data);
            tmp = tmp->right;
        }
        printf("\n");
    }

    /**
     * Funcao para adicionar elemento no final da lista.
     * @param lista e valor
     * @return lista atualizada
     */
    intCell *array_push_back(intCell *list, int value)
    {
        if (list == null)
        {
            intCell *newHead = new intCell(value, null, null);
            return newHead;
        }

        intCell *tmp = this;
        while (tmp->right != null)
        {
            tmp = tmp->right;
        }

        intCell *newNode = new intCell(value, tmp, null);
        tmp->right = newNode;
        // tmp->left = null;

        return list;
    }

    /**
     * Funcao para remover elemento do final da lista
     * @return lista atualizada
     */
    intCell *array_pop_back(intCell *list) //problema ao tirar quando existe apenas 1 elemento na lista, devido ao pushback
    {
        if (list == null)
        {
            return null;
        }

        intCell *tmp = list;

        while (tmp->right != null)
        {
            tmp = tmp->right;
        }

        if (tmp->left == null)
        {
            delete tmp;
            return null;
        }
        tmp->left->right = null;

        delete tmp;
        return list;
    }

    /**
     * Funcao para adicionar elemento no comeco da lista
     * @param lista e valor
     * @return lista atualizada
     */
    intCell *array_push_front(intCell *list, int value)
    {
        if (list == null)
        {
            return null;
        }
        intCell *tmp = new intCell(value, null, this);

        if (list != null)
        {
            list->left = tmp;
        }
        list = tmp;
        return list;
    }

    /**
     * Funcao para remover elemento do inicio da lista
     * @param lista
     * @return lista atualizada
     */
    intCell *array_pop_front(intCell *list)
    {
        if (list == null)
        {
            return null;
        }

        intCell *tmp = list;
        list = tmp->right;
        delete list->left;
        return list;
    }

    /**
     * Funcao para adicionar elemento no meio da lista
     * @param lista e valor
     * @return lista atualizada
     */

    intCell *array_push_mid(intCell *list, int value)
    {
        intCell *newNode = new intCell(value, null, null);

        if (list == null)
        {
            list = newNode;
            return list;
        }
        intCell *tmp = list;

        int x = (getTam(list) / 2) - 1;

        while (x > 0)
        {
            tmp = tmp->right;
            x--;
        }

        newNode->right = tmp->right;
        tmp->right = newNode;
        delete tmp;
        return list;
    }

    /**
     * Funcao para remover elemento do meio (aproximadamente) da lista
     * @param lista
     * @return lista atualizada
     */

    intCell *array_pop_mid(intCell *list)
    {
        if (list == null)
        {
            return null;
        }

        int x = (getTam(list) / 2);

        intCell *tmp = list;
        while (x > 0)
        {
            tmp = tmp->right;
            x--;
        }

        if (tmp->left != null)
        {
            tmp->left->right = tmp->right;
        }

        if (tmp->right != null)
        {
            tmp->right->left = tmp->left;
        }

        if (tmp == list)
        {
            list = tmp->right;
        }

        delete tmp;
        return list;
    }

    int intArray_cmp(intCell *array1, intCell *array2)
    {
        intCell *tmp1 = array1;
        intCell *tmp2 = array2;

        while (tmp1 != null && tmp2 != null)
        {
            if (tmp1->data != tmp2->data)
            {
                return tmp1->data - tmp2->data;
            }
            tmp1 = tmp1->right;
            tmp2 = tmp2->right;
        }

        if (getTam(tmp1) > getTam(tmp2))
        {
            return 1;
        }
        else if (getTam(tmp1) < getTam(tmp2))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    intCell *intArray_cat(intCell *array1, intCell *array2)
    {
        if (array1 == nullptr)
        {
            return array2;
        }
        if (array2 == nullptr)
        {
            return array1;
        }

        intCell *tmp = array1;
        while(tmp->right != null)
        {
            tmp = tmp->right;
        }

        tmp->right = array2;
        array2->left = tmp;

        return array1;
    }

    intCell *intArray_seek (intCell *array, int value)
    {
        if(array == null)
        {
            return null;
        }
        bool r = false;
        intCell *tmp = array;
        while(tmp->right != null && !r)
        {
            if(tmp->data == value)
            {
                r = true;
            }
            tmp = tmp->right;
        }
        return tmp;
    }
};
