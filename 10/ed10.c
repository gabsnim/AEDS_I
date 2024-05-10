/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
// #include "struct.h"


typedef
struct S_array_01
{
  int length; // tamanho do arranjo;
  int* data;  //   dados do arranjo;
  int ix ;    // lugares do arranjo;
} int_Array;

typedef int_Array* ref_int_Array; //int_Array* == ref_int_Array ou seja, onde estao os dados 

ref_int_Array new_int_Array (int n) //reservar espaco para array
{
  ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
  // int_Array* tmpArray = (int_Array*)malloc(n * sizeof(int_Array));
  if(tmpArray == null)
  {
    printf("ERRO ao alocar memoria.\n");
  }
  else
  {
    tmpArray->length = 0;
    tmpArray->data = null;
    tmpArray->ix = -1;

    if(n > 0) //dados maiores que 0, reservar espaco
    {
      //guardar quantidade de dados 
      tmpArray->length = n;
      //reservar espacos para os dados
      tmpArray->data = (int*)malloc(n * sizeof(int));
      //definir indicador para o primeiro elemento
      tmpArray->ix = 0;
    }
  }
  return ( tmpArray );
}

// int_Array init_Array (ref_int_Array array, int n)
// {
//   ref_int_Array init_Array = (ref_int_Array)malloc(array->length * sizeof(int));

//   for(init_Array->ix = 0; init_Array->ix < init_Array->length; init_Array->ix++)
//   {
//     init_Array->data[init_Array->ix] = n;
//   }
//   return *init_Array;
// }

void free_int_Array (ref_int_Array tmpArray)
{
  if(tmpArray != null)
  {
    free(tmpArray->data);
  }
  free(tmpArray);
}

void printintArray (int_Array array)
{
  if(array.data) //existir
  {
    for(array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
    {
      printf("%2d: %d\n", array.ix, array.data [ array.ix ]);
    }
  }
}

int_Array readArrayfromfile (chars Filename)
{
  FILE* arquivo = fopen (Filename, "rt");
  int_Array array; //"inicializar objeto"
  array.ix = 0;
  int y = 0;
  int x = 0;

  if(arquivo) //!= null
  {
    fscanf(arquivo, "%d", &array.length);
    
    if(array.length <= 0)
    {
      array.length = 0;
      printf("ERRO: Valor invalido.");
    }
    else
    {
      array.data = (int*)malloc(array.length * sizeof(int));

      if(array.data)
      {
        while(!feof(arquivo) && array.ix < array.length)
        {
          fscanf(arquivo, "%d", &array.data[array.ix]);
          array.ix++;
        }
      }
    }
  }
  return ( array );
}

int ArraySearch (int n, int_Array array)
{
  int position = 0;
  // printf("aqui.");
  // printintArray(array);
  bool teste = false;

  while (n == array.data[array.ix] && array.ix < array.length)
  {
    if(array.ix < array.length)
    {
      position = array.ix;
    }
  }
  
  return (position);
}

bool arrayCompare (int_Array array1, int_Array array2)
{
  bool result = true;
  int count = 0;
  // printintArray(array1);
  // printintArray(array2);
  for(array1.ix = 0; array1.ix < array1.length; array1.ix++)
  {
    if(array1.data[array1.ix] != array2.data[array1.ix])
    {
      result = false;
    }
  }
  return result;
}

int_Array arrayAdd (int_Array array1, int_Array array2, int_Array array3)
{
  // ref_int_Array array3;
  array3.data = malloc(array1.length * sizeof(int));
  // printf("lenght 3 = %d", array3.length);
  if(array1.data && array2.data && array3.data)
  {
    array3.length = array1.length;
    for(int i = 0; i < array1.length; i++)
    {
      array3.data[i] = array1.data[i] + array2.data[i];
      // printf("%d\n", array3.data[i]);
    }
  }

  return array3;
}

void method_01(void) 
{
  int_Array array; //como se estivesse inicializando um objeto
  int n = G_readint("Digite o tamanho do array: ");
  array.length = n;
  array.ix = 0;
  
  int a = G_readint("Digite o valor inferior do intervalo: ");
  int b = G_readint("Digite o valor superior do intervalo: ");
  int x = 0;

  array.data = (int*)malloc(array.length * sizeof(int));

  if(array.data) //!= null 
  {
    while (array.ix < array.length)
    {
      x = rand() % 100;
      if(x >= a && x <= b)
      {
        printf("x = %d\n", x);
        array.data[array.ix] = x;
        array.ix++;
      }
    }
  }

  printintArray(array);

  if(array.data)
  {
    free(array.data);
  }
}
void method_02(void) 
{
  int_Array array;
  array = readArrayfromfile("DADOS.TXT");
  int result = 0;

  if(array.data)
  {
    printintArray(array);
    result = ArraySearch(10, array);
    printf("%d", result);
  }

  if(array.data != null)
  {
    free (array.data);
  }
}
void method_03(void)
{
  int_Array array1;
  int_Array array2;
  array1 = readArrayfromfile("DADOS1.TXT");
  array2 = readArrayfromfile("DADOS2.TXT");

  printf("array1: \n");
  printintArray(array1);
  printf("array2: \n");
  printintArray(array2);
  if(array1.length == array2.length)
  {
    // printf("\nlenght1 = %d\n", array1.length);
    // printf("\nlenght2 = %d\n", array2.length);
    if(arrayCompare(array1, array2))
    {
      printf("Arrays iguais.\n");
    }
    else
    {
      printf("Arrays diferentes.\n");
    }
  }
}
void method_04(void) 
{
  int_Array array1;
  int_Array array2;
  int_Array array3;
  array1 = readArrayfromfile("DADOS1.TXT");
  array2 = readArrayfromfile("DADOS2.TXT");

  array3 = arrayAdd (array1, array2, array3);
  printf("1:\n");
  printintArray(array1);
  printf("2:\n");
  printintArray(array2);
  printf("3:\n");
  printintArray(array3);
}
void method_05(void) 
{

}
void method_06(void)
{
 
}
void method_07(void) 
{

}
void method_08(void) 
{

}
void method_09(void)
{
 
}
void method_10(void) 
{

}
void method_11e(void) 
{

}
void method_12e(void) 
{

}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 0?");
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