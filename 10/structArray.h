#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null NULL;

typedef struct S_Array
{
    int length;
    int *data;
    int ix;
} int_Array;

typedef int_Array *pointer_int_Array;

pointer_int_Array new_int_array(int n)
{
    pointer_int_Array array = null;
    if (n > 0) // tamanho existente
    {
        array = malloc(1 * sizeof(int_Array)); // criar

        if (array)
        {
            array->data = malloc(n * sizeof(int)); // reservar espaco
            if (array->data)
            {
                array->length = n;
            }
        }
    }
    return (array);
}

pointer_int_Array init_int_Array(pointer_int_Array array, int x)
{
    if (array)
    {
        for (array->ix = 0; array->ix < array->length; array->ix++)
        {
            array->data[array->ix] = x;
        }
    }
    return (array);
}

void int_printArray(pointer_int_Array array)
{
    if (array)
    {
        for (array->ix = 0; array->ix < array->length; array->ix++)
        {
            printf("%d ", array->data[array->ix]);
        }
    }
}

void fprintArray(pointer_int_Array array, chars Filaneme)
{
    FILE *arquivo = fopen(Filaneme, "wt");

    if (arquivo)
    {
        fprintf(arquivo, "%d\n", array->length);
        for (array->ix = 0; array->ix < array->length; array->ix++)
        {
            fprintf(arquivo, "%d\n", array->data[array->ix]);
        }

        fclose(arquivo);
    }
}

// int_Array readArrayfromfile (chars Filename)
// {
//     FILE* arquivo = fopen (Filename, "rt"); 
//     int_Array array;
//     array.ix = 0;

//     if(arquivo)
//     {
//         fscanf(arquivo, "%d", &array.length);

//         if(array.data <= 0)
//         {
//             printf("ERRO valor invalido ");
//         }
//         else
//         {
//             array.data = (int*)malloc(array.length * sizeof(int));

//             if(array.data)
//             {
//                 while (!feof(arquivo) && array.ix < array.length)
//                 {
//                     fscanf(arquivo, "%d", &array.data[array.ix]);
//                     array.ix++;
//                 }
//             }
//         }
//     }
//     return array; 
// }

pointer_int_Array readArrayfromfile(chars Filename)
{
    FILE* arquivo = fopen(Filename, "rt");
    pointer_int_Array array = null;

    if (arquivo)
    {
        int length;
        fscanf(arquivo, "%d", &length); 

        if (length > 0)
        {
            array = new_int_array(length);

            if (array)
            {
                array->length = length;
                for (array->ix = 0; array->ix < array->length; array->ix++)
                {
                    fscanf(arquivo, "%d", &array->data[array->ix]);
                }
            }
        }
        fclose(arquivo);
    }
    return array;
}

int ArraySearch (pointer_int_Array array, int x)
{
    int search = 0;
    if(array)
    {
        for(array->ix = 0; array->ix < array->length; array->ix++)
        {
            if(x == array->data[array->ix])
            {
                search = array->ix;
            }
        }
    }
    return search;
} 

bool ArrayCompare (pointer_int_Array array1, pointer_int_Array array2)
{
    bool compare = true;

    if(array1 == NULL || array2 == NULL)
    {
        printf("Algum array nao esta com dados.\n");
    }
    else
    {
        for(array1->ix = 0; array1->ix < array1->length; array1->ix++)
        {
            if(array1->data[array1->ix] != array2->data[array2->ix])
            {
                compare = false;
            }
        }
    }
    return compare;
}

pointer_int_Array ArrayAdd (pointer_int_Array array1, pointer_int_Array array2)
{
    pointer_int_Array array3 = null;
    if(array1 == NULL || array2 == NULL)
    {
        printf("ERRO nos dados dos arranjos.\n");
    }
    else
    {
        // printf("%d", array1->length);
        if(array1->length == array2->length)
        {
            array3 = new_int_array (array1->length);
            for(array1->ix = 0; array1->ix < array1->length; array1->ix++)
            {
                array3->data[array1->ix] = array1->data[array1->ix] + array2->data[array1->ix];
            }
        }
    }
    return array3;
}

bool ArrayDecrescent (pointer_int_Array array)
{
    bool resposta = true;
    int count = 0;
    if(array == NULL)
    {
        printf("ERRO nos dados dos arranjos.\n");
    }
    else
    {
        for(array->ix = 0; array->ix < array->length-1; array->ix++)
        {
            if(array->data[array->ix] < array->data[array->ix + 1])
            {
                resposta = false;
            }
        }
    }
    return resposta;
}

pointer_int_Array SortArrayDown (pointer_int_Array array)
{
    int aux = 0;
    if(array)
    {
        for(int i = 0; i < array->length; i++)
        {
           for(int j = 0; j < array->length - i - 1; j++)
           {
            if(array->data[j] < array->data[j + 1])
            {
                aux = array->data[j];
                array->data[j] = array->data[j + 1];
                array->data[j + 1] = aux;
            }
           }
        }
    }
    return array;
}



