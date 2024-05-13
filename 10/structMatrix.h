#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null NULL;

typedef struct S_Matrix
{
    int rows;
    int columns;
    int** data;
    int ix, ij;
} int_Matrix;

typedef int_Matrix* pointer_int_Matrix;

pointer_int_Matrix new_int_matrix (int rows, int columns)
{
    pointer_int_Matrix matrix = (pointer_int_Matrix) malloc (sizeof(int_Matrix));

    if(matrix != NULL)
    {
        matrix->rows = 0;
        matrix->columns = 0;
        matrix->data = null;
        
        if(rows > 0 && columns > 0)
        {
            matrix->rows = rows;
            matrix->columns = columns;
            matrix->data = malloc (rows * sizeof(int*)); 

            if(matrix->data)
            {
                for(matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
                {
                    matrix->data[matrix->ix] = (int*)malloc(columns*sizeof(int));
                }
            }
        }
        matrix->ix = 0;
        matrix->ij = 0;
    }
    return ( matrix );
}

void free_int_Matrix ( pointer_int_Matrix matrix ) 
{ 
    if ( matrix != NULL ) 
    { 
       if ( matrix->data != NULL ) 
       { 
          for ( matrix->ix=0; 
                  matrix->ix<matrix->rows; 
                  matrix->ix=matrix->ix+1 ) 
          { 
                free ( matrix->data [ matrix->ix ] ); 
          } 
          free ( matrix->data ); 
       } 
       free ( matrix ); 
    } 
} 

void int_printMatrix ( pointer_int_Matrix matrix ) 
{ 
    if ( matrix != NULL && matrix->data != NULL ) 
    { 
        for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix++) 
        { 
             for ( matrix->ij=0; matrix->ij<matrix->columns; matrix->ij++) 
             { 
                 printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->ij ] ); 
             } 
             printf ( "\n" ); 
        }  
    } 
}

pointer_int_Matrix readMatrixfromfile (chars Filename)
{
    FILE* arquivo = fopen (Filename, "rt");
    pointer_int_Matrix matrix = null;
    int rows = 0;
    int columns = 0;

    if(arquivo)
    {
        fscanf(arquivo, "%d", &rows);
        fscanf(arquivo, "%d", &columns);

        if(rows > 0 && columns > 0)
        {
            matrix = new_int_matrix(rows, columns);
            if(matrix != NULL && matrix->data == NULL)
            {
                matrix->rows = 0; 
                matrix->columns = 0; 
                matrix->ix = 0; 
                matrix->ij = 0; 
            }
            else
            {
                if(matrix != NULL)
                {
                    matrix->ix = 0;
                    while (!feof(arquivo) && matrix->ix < matrix->rows)
                    {
                        matrix->ij = 0;
                        while (!feof(arquivo) && matrix->ij < matrix->columns)
                        {
                            fscanf(arquivo, "%d", &matrix->data[matrix->ix][matrix->ij]);
                            matrix->ij++;
                        }
                        matrix->ix++;
                    }
                    matrix->ix = 0;
                    matrix->ij = 0;
                }
            }
        }
        fclose(arquivo);
        return matrix;
    }
}

pointer_int_Matrix matrixTranspose (pointer_int_Matrix matrix)
{
    if(matrix == NULL)
    {
        printf("ERRO com os dados da matrix.");
    }
    pointer_int_Matrix matrixTrasnpose = malloc(sizeof(int_Matrix));
    if(matrixTrasnpose == NULL)
    {
        printf("ERRO ao alocar memoria para a nova matrix.");
    }
    else
    {
        matrixTrasnpose->rows = matrix->columns;
        matrixTrasnpose->columns = matrix->rows;

        matrixTrasnpose->data = malloc(matrixTrasnpose->rows * sizeof(int*));

        if(matrixTrasnpose->data == NULL)
        {   
            printf("ERRO ao alocar memoria para matrix");
        }
        else
        {
            for(int i = 0; i < matrixTrasnpose->rows; i++)
            {
                matrixTrasnpose->data[i] = malloc(matrixTrasnpose->columns * sizeof(int));

                for(int j = 0; j < matrixTrasnpose->columns; j++)
                {
                    matrixTrasnpose->data[i][j] = matrix->data[j][i];
                }
            }
        }
    }
    return matrixTrasnpose;
}

bool MatrixZero (pointer_int_Matrix matrix)
{
    bool zeros = true;
    if(matrix)
    {
        for(matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
        {
            for(matrix->ij = 0; matrix->ij < matrix->columns; matrix->ij++)
            {
                if(0 != matrix->data[matrix->ix][matrix->ij])
                {
                    zeros = false;
                }
            }
        }
    }
    return zeros;
}

bool MatrixCompare (pointer_int_Matrix matrix1, pointer_int_Matrix matrix2)
{
    bool equal = true;

    if(matrix1 != NULL && matrix2 != NULL)
    {
        for(matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
            for(matrix1->ij = 0; matrix1->ij < matrix1->columns; matrix1->ij++)
            {
                if(matrix1->data[matrix1->ix][matrix1->ij] != matrix2->data[matrix1->ix][matrix1->ij])
                {
                    equal = false;
                }
            }
        }
    }
    return equal;
}

pointer_int_Array MatrixAdd (pointer_int_Matrix matrix1, pointer_int_Matrix matrix2)
{
    pointer_int_Matrix matrix3 = null;

    if(matrix1 && matrix2)
    {
        matrix3 = new_int_matrix(matrix1->rows, matrix1->columns);

        for(matrix1->ix=0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
            for(matrix1->ij = 0; matrix1->ij < matrix1->columns; matrix1->ij++)
            {
                matrix3->data[matrix1->ix][matrix1->ij] = matrix1->data[matrix1->ix][matrix1->ij] + 
                matrix2->data[matrix1->ix][matrix1->ij];
            }
        }
    }
    return matrix3;
}

pointer_int_Array MatrixProduct (pointer_int_Matrix matrix1, pointer_int_Matrix matrix2)
{
    pointer_int_Matrix matrix3 = null;

    if(matrix1 && matrix2)
    {
        matrix3 = new_int_matrix(matrix1->rows, matrix1->columns);

        for(matrix1->ix=0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
            for(matrix1->ij = 0; matrix1->ij < matrix1->columns; matrix1->ij++)
            {
                matrix3->data[matrix1->ix][matrix1->ij] = matrix1->data[matrix1->ix][matrix1->ij] * 
                matrix2->data[matrix1->ix][matrix1->ij];
            }
        }
    }
    return matrix3;
}





