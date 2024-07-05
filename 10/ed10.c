
/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/

#include "gxb.h"
#include "structArray.h"
#include "structMatrix.h"


void method_01(void) 
{
  int n = G_readint("Digite o tamanho do array: ");
  int a = G_readint("Digite o valor A do intervalo: ");
  int b = G_readint("Digite o valor B do intervalo: "); 
  pointer_int_Array array = null;
  array = new_int_array(n); 
  int x = 0; 
  if(array)
  {
    if(n > 0)
    {
      array->lenght = n;
      array->ix = 0; 
      if(array)
      {
        while (array->ix < n)
        {
          x = rand() % 100; 
          if(x >= a && x <= b)
          {
            array->data[array->ix] = x;
            array->ix++;
          }
        }
      }
      int_printArray(array);
      fprintArray(array, "DADOS.TXT");
      free(array->data); 
      free(array);
    }
  } 
}
void method_02(void) 
{
  pointer_int_Array array = readArrayfromfile("DADOS1.TXT");
  int x = G_readint("Digite o valor a ser procurado no array: ");

  int_printArray(array);
  
  printf("\no valor %d esta na posicao %d",x,  ArraySearch(array, x));

  free(array->data);
  free(array);

}
void method_03(void)
{
  pointer_int_Array array1 = readArrayfromfile("DADOS1.TXT");
  pointer_int_Array array2 = readArrayfromfile("DADOS2.TXT");

  if(array1 != NULL && array2 != NULL)
  {
    if (ArrayCompare(array1, array2)) 
    {
      printf("\nOs arrays sao iguais.");
    } 
    else 
    {  
      printf("Os arrays nao sao iguais.");
    }
  } 
  else 
  {
    printf("Erro ao ler os arrays dos arquivos.");
  }

  free(array1->data);
  free(array1);
  free(array2->data);
  free(array2);
}

void method_04(void) 
{
  pointer_int_Array array1 = readArrayfromfile("DADOS1.TXT");
  pointer_int_Array array2 = readArrayfromfile("DADOS2.TXT");
  pointer_int_Array array3 = null;

  array3 = ArrayAdd(array1, array2);
  int_printArray(array1);
  printf("\n");
  int_printArray(array2);
  printf("\nsoma:\n");
  int_printArray(array3);

  free(array1->data);
  free(array1);
  free(array2->data);
  free(array2);
  free(array3->data);
  free(array3);
}
void method_05(void) 
{
  pointer_int_Array array = null;
  array = readArrayfromfile("DADOS1.TXT");

  if(ArrayDecrescent(array))
  {
    int_printArray(array);
    printf("\nArray decrescente.\n");
  }
  else
  { 
    int_printArray(array);
    printf("\nArray nao decrescente.\n");
  }
  
  free(array->data);
  free(array);
}
void method_06(void)
{
  pointer_int_Matrix matrix = readMatrixfromfile("DADOS3.TXT");

  int_printMatrix(matrix);
  printf("\n");

  pointer_int_Matrix newMatrix = matrixTranspose(matrix);

  int_printMatrix(newMatrix);

  free_int_Matrix(matrix);
  free_int_Matrix(newMatrix);
}
void method_07(void) 
{
  pointer_int_Matrix matrix = readMatrixfromfile ("MATRIX1.TXT");

  if(MatrixZero(matrix))
  {
    int_printMatrix(matrix);
    printf("\nMatrix com todos dados iguais a 0.\n");
  }
  else
  {
    int_printMatrix(matrix);
    printf("\nMatrix nao tem todos dados iguais a 0.");
  }

  free_int_Matrix(matrix);
}
void method_08(void) 
{
  pointer_int_Matrix matrix1 = readMatrixfromfile("MATRIX1.TXT");
  pointer_int_Matrix matrix2 = readMatrixfromfile("MATRIX2.TXT"); 

  if(MatrixCompare(matrix1, matrix2))
  {
    int_printMatrix(matrix1);
    printf("\n");
    int_printMatrix(matrix2);
    printf("\nAs matrizes sao iguais.");
  } 
  else
  {
    int_printMatrix(matrix1);
    printf("\n");
    int_printMatrix(matrix2);
    printf("\nAs matrizes NAO sao iguais.");
  }
  free_int_Matrix(matrix1);
  free_int_Matrix(matrix2);  
}
void method_09(void)
{
  pointer_int_Matrix matrix1 = readMatrixfromfile("MATRIX1.TXT");
  pointer_int_Matrix matrix2 = readMatrixfromfile("MATRIX2.TXT"); 
  pointer_int_Matrix matrix3 = MatrixAdd(matrix1, matrix2); 

  int_printMatrix(matrix1);
  printf("\n");
  int_printMatrix(matrix2);
  printf("\nsoma:\n ");
  int_printMatrix(matrix3);

  free_int_Matrix(matrix1);
  free_int_Matrix(matrix2);
  free_int_Matrix(matrix3);
}
void method_10(void) 
{
  pointer_int_Matrix matrix1 = readMatrixfromfile("MATRIX1.TXT");
  pointer_int_Matrix matrix2 = readMatrixfromfile("MATRIX2.TXT"); 
  pointer_int_Matrix matrix3 = MatrixProduct(matrix1, matrix2); 

  printf("matrix1\n");
  int_printMatrix(matrix1);
  printf("\nmatrix2\n");
  int_printMatrix(matrix2);
  printf("\nproduto:\n ");
  int_printMatrix(matrix3);

  free_int_Matrix(matrix1);
  free_int_Matrix(matrix2);
  free_int_Matrix(matrix3);
}
void method_11e(void) 
{
  pointer_int_Array array = readArrayfromfile("DADOS2.TXT");
  int_printArray(array);
  printf("\n");
  SortArrayDown(array);
  int_printArray(array);
}
void method_12e(void) 
{

}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 10");
  printf("%s\n", "Autor: Gabriel Xavier Borges");
  printf("\n");

  do {

    printf("\n%s\n", "Opcoes:");
    printf("\n%s", "0 - Terminar");
    printf("\n%s", "1 - Method_01");
    printf("\n");
    printf("\n%s", "2 - Method_02");
    printf("\n");
    printf("\n%s", "3 - Method_03");
    printf("\n");
    printf("\n%s", "4 - Method_04");
    printf("\n");
    printf("\n%s", "5 - Method_05");
    printf("\n");
    printf("\n%s", "6 - Method_06");
    printf("\n");
    printf("\n%s", "7 - Method_07");
    printf("\n");
    printf("\n%s", "8 - Method_08");
    printf("\n");
    printf("\n%s", "9 - Method_09");
    printf("\n");
    printf("\n%s", "10 - Method_10");
    printf("\n");
    printf("\n%s", "11 - Method_11e");
    printf("\n");
    printf("\n%s", "12 - Method_12e");
    printf("\n");

    printf("\n%s", "Opcao = ");
    scanf("%d", &opcao);
    getchar();

    printf("\n%s%d", "Opcao = ", opcao);
    printf("\n");

    switch (opcao) {
    case 0:
      break;
    case 1:
      method_01();
      break;
    case 2:
      method_02();
      break;
    case 3:
      method_03();
      break;
    case 4:
      method_04();
      break;
    case 5:
      method_05();
      break;
    case 6:
      method_06();
      break;
    case 7:
      method_07();
      break;
    case 8:
      method_08();
      break;
    case 9:
      method_09();
      break;
    case 10:
      method_10();
      break;
    case 11:
      method_11e();
      break;
    case 12:
      method_12e();
      break;
    default:
      printf("\nERRO: Opcao invalida.\n");
      break;
    }
  } while (opcao != 0);

  printf("\n\nApertar ENTER para terminar.");
  getchar();
  return (0);
}