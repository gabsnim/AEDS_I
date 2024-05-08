#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char *chars;

#define null NULL //ref null

/*
  Funcao para ler um inteiro
  @param texto a ser imprimido na hora da leitura
  @return numero tipo inteiro
*/

int G_readint(char *text)
{
  int x = 0;
  printf("%s", text);
  scanf("%d", &x);
  getchar();
  return (x);
}

/*
  Funcao para ler um double
  @param texto a ser imprimido na hora da leitura
  @return numero tipo double
*/

double G_readdouble(char *text)
{
  double x = 0;
  printf("%s", text);
  scanf("%lf", &x);
  getchar();
  return (x);
}

/*
  Funcao para ler um float
  @param texto a ser imprimido na hora da leitura
  @return numero tipo float
*/

float G_readfloat(char *text)
{
  float x = 0;
  printf("%s", text);
  scanf("%f", &x);
  getchar();
  return (x);
}

/*
  Funcao para ler um caractere
  @param texto a ser imprimido na hora da leitura
  @return caractere
*/

char G_readchar(char *text)
{
  char x = '0';
  printf("%s", text);
  scanf("%c", &x);
  getchar();
  return (x);
}

/*
  Funcao para ler uma string
  @param texto a ser imprimido na hora da leitura
  @return string
*/

char *G_readstring(char *text)
{
  char *x = (char *)malloc(100 * sizeof(char));
  printf("%s", text);
  scanf("%s", x);
  getchar();
  return (x);
}

// char* G_readln(char *text)
// {
//   //substituir /n por /0
// }

/*
  Funcao para verificar se um numero e par
  @param numero para ser verificado
  @return true ou false
*/

bool G_isPar(int x)
{
  if (x % 2 == 0)
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um numero esta em um determinado intervalo fechado
  @param numero a ser verificado e extremos
  @return true ou false
*/

bool G_fIntervalo(int x, int a, int b)
{
  if (x >= a && x <= b)
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um numero esta em um determinado intervalo aberto
  @param numero a ser verificado e extremos
  @return true ou false
*/

bool G_aIntervalo(int x, int a, int b)
{
  if (x > a && x < b)
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um caracter e uma letra maiuscula
  @param caracter a ser verificado
  @return true ou false
*/

bool G_isMaiuscula(char x)
{
  if (x >= 'A' && x <= 'Z')
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um caracter e uma letra minuscula
  @param caracter a ser verificado
  @return true ou false
*/

bool G_isMinuscula(char x)
{
  if (x >= 'a' && x <= 'z')
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um caracter e um digito
  @param caracter a ser verificado
  @return true ou false
*/

bool G_isDigit(char x)
{
  if (x >= '0' && x <= '9')
  {
    return true;
  }
  return false;
}

/*
  Funcao para verificar se um caracter e um caracter especial
  @param caracter a ser verificado
  @return true ou false
*/

bool G_isSpecial(char x)
{
  if (G_isDigit(x) != 1 && G_isMaiuscula(x) != 1 && G_isMinuscula(x) != 1) // ou = 0
  {
    return true;
  }
  return false;
}

/*
  Funcao para retornar uma potencia de x^y
  @param base e expoente
  @return potencia
*/

int G_pot(int x, int y)
{
  if (y == 0)
  {
    return 1;
  }
  else
  {
    return x * G_pot(x, y - 1);
  }
}

/*
  Funcao para retornar uma potencia double de x^y
  @param base(double) e expoente
  @return potencia
*/

double G_pot_real(double x, int y)
{
  if (y == 0)
  {
    return 1;
  }
  else
  {
    return x * G_pot(x, y - 1);
  }
}

/*
  Funcao para retornar o fatorial de um numero
  @param numero
  @return fatorial
*/

int G_fac(int x)
{
  if (x == 0 || x == 1)
  {
    return 1;
  }
  else
  {
    return x * G_fac(x - 1);
  }
}

/*
  Funcao para retornar a sequencia N de fibonacci
  @param  numero da sequencia
  @return numero N da sequencia
*/

int G_fibonacci(int n)
{
  int resposta = 0;
  if (n == 1 || n == 2)
  {
    resposta = 1;
  }
  else
  {
    if (n > 2)
    {
      resposta = G_fibonacci(n - 1) + G_fibonacci(n - 2);
    }
  }
  return resposta;
}

/*
  Procedimento para mostrar na tela os elementos de um array
  @param int = tamanho, int array [] = array para ser percorrido e mostrar os elementos
*/

void G_printarray(int n, int array[])
{
  int x = 0;
  for (int i = 0; i < n; i++)
  {
    x = array[i];
    printf("%d ", x);
  }
}

/*
  Procedimento para ler dados e armazerar em um array de tamanho N
  @param int n = tamanho, int array [] = lugar a ser armazenado os valores de N
*/

void G_readarray(int n, int array[])
{
  int x = 0;
  for (int i = 0; i < n; i++)
  {
    printf("Elemento %d = ", i);
    scanf("%d", &x);
    array[i] = x;
  }
}

/*
  Funcao para somar elementos inteiros dentro de um arranjo
  @param int n = tamanho, int array [] = elementos do array
  @return soma dos elementos
*/

int G_SumIntArray(int n, int array[])
{
  int soma = 0;
  for (int i = 0; i < n; i++)
  {
    soma = soma + array[i];
  }
  return soma;
}

// void G_printdoublearray (int n, double array [])
// {
//   for(int i = 0; i < n; i++)
//   {
//     printf("%lf ", array[i]);
//   }
// }

/*
  Funcao para duplicar um array
  @param int n = tamanho, int array [] = elementos do array
  @return um array duplicado
*/

int *G_dupArray(int n, int array[])
{
  // G_printarray(n, array);
  int *array1 = NULL;
  int x = 0;
  array1 = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    x = array[i];
    array1[i] = x;
  }

  return (array1);
}

/*
  Funcao para comparar dois arrays de tamanhos iguais
  @param int n = tamanho, int array1/int array2[] = elementos do array
  @return 1 caso os arrays sejam iguais e -1 para caso nao sejam iguais
*/

int G_compArray(int n, int array1[], int array2[])
{
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    if (array1[i] == array2[i])
    {
      a++;
    }
  }

  if (a == n)
  {
    return 1;
  }
  else if (a > n || n > a)
  {
    return -1;
  }
}

/*
  Funcao para copiar um array para o outro
  @param int n = tamanho, int array [] = elementos do array
  @return um novo array com os elementos dos dois arrays
*/

int *G_cpyArray(int n, int array[], int array1[])
{
  int *newArray = NULL;

  newArray = (int *)malloc((n * 2) * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    newArray[i] = array[i];
  }

  for (int i = n; i < (n * 2); i++)
  {
    newArray[i] = array1[i - n];
  }

  return (newArray);
}

/*
  Funcao para verificar o tamanho de um array
  @param int array []
  @return tamanho
*/

int G_arrayLenAux(chars Filename)
{
  FILE *arquivo = fopen(Filename, "wt");
  int x = 0;
  char *string;
  do
  {
    x = G_readint("x = ");
    string = G_readstring("Digite S para continuar e N para parar: ");
    fprintf(arquivo, "%d\n", x);
  } while (strcmp(string, "N"));
  fclose(arquivo);

  FILE *arquivo1 = fopen("ARRAYLEN.TXT", "rt");

  int count = 0;

  while (!feof(arquivo))
  {
    fscanf(arquivo1, "%d", &x);
    count++;
    // printf("count %d =  x = %d\n", count, x);
  }

  return (count - 1);
}

void G_printERROFILE(void)
{
  printf("Erro ao abrir o arquivo.\n");
}

void G_printMatrix (int rows, int coloumns, int matrix[][coloumns])
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < coloumns; j++)
    {
      printf("%3d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void G_readMatrix (int rows, int columns, int matrix[][columns])
{
  int y = 0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      printf("linha %d coluna %d = ",i , j);
      y = G_readint("");
      matrix[i][j] = y;
    }
  }
}

void G_readdoubleNegativeMatrix (int rows, int columns, double matrix[][columns]) // negative;
{
  double x = 0.0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      do
      {
        printf("linha %d coluna %d = ", i, j);
        x = G_readdouble("");
      } while (x > 0);
      matrix[i][j] = x;
    }
  }
}

void G_printdoubleMatrix (int rows, int columns, double matrix[][columns])
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns  ; j++)
    {
      printf("%.2lf ", matrix[i][j]);
    }
    printf("\n");
  }
}
