#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null NULL;

typedef
struct S_Array
{
    int lenght;
    int* data;
    int ix;
} int_Array;

typedef int_Array* pointer_int_Array;

pointer_int_Array new_int_array (int n)
{
    pointer_int_Array array = null;
    if(n > 0) //tamanho existente
    {
        array = malloc(1 * sizeof(int_Array)); //criar
        
        if(array)
        {
            array->data = malloc(n * sizeof(int)); //reservar espaco
            if(array->data)
            {
                array->lenght = n;
            }
        }
    }
    return ( array );
}

pointer_int_Array init_int_Array (pointer_int_Array array, int x)
{
    if(array)
    {
        for(array->ix = 0; array->ix < array->lenght; array->ix++)
        {
            array->data[array->ix] = x;
        }
    }
    return ( array );   
}

void int_printArray (pointer_int_Array array)
{
    if(array)
    {
        for(array->ix=0; array->ix < array->lenght; array->ix++)
        {
            printf("%d ", array->data[array->ix]);
        }
    }
}