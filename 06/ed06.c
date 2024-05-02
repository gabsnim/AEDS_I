/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
#include "io.h"

void method01(int n)
{
    int x = 6;
    if(n > 0)
    {
      method01(n - 1);
      printf("%d ", x * n);
    }
}
void method_01(void) 
{
    int n = G_readint("x: ");
    method01(n);
}
void method02(int n)
{
  int x = 6;
  if(n > 0)
  {
    printf("%d ", x * n);
    method02(n - 1);
  }
}
void method_02(void)
{
  int n = G_readint("Digite o valor de N: ");
  method02(n);
}
// void method03 (int n)
// {
//   int x = 6;
//   if(n == 1)
//   {
//     printf("1/1 ");
//     // n = n - 1;
//     // method03(n - 1);
//   }
//   else
//   {
//   method03(n - 1);
//   printf("1/%d ", x * (n-1));
//   }
// }
// void method_03(void)
// {
//   int n = G_readint("Digite o valor de n: ");
//   method03(n);
// }
void method03 (int n) //outra versao descontando na entrada.
{
  int x = 6;
  if(n == 0)
  {
    printf("1/1 ");
  }
  else
  {
    method03(n - 1);
    printf("1/%d ", x * n);
  }
}
void method_03 (void) //outra versao descontando na entrada.
{
  int n = G_readint("Digite o valor de N: ");
  method03(n - 1);
}
void method04 (int n)
{
  int x = 6;
  if(n == 0)
  {
    printf("1/1 ");
  }
  else
  {
    printf("1/%d ", x * n);
    method04(n - 1);
  }
}
void method_04(void)
{
  int n = G_readint("Digite o valor de N: ");
  method04(n - 1);  
}
int method05 (int n)
{
  int soma = 6;
  int i = 2;
  if(n > 0)
  {
    soma = soma + i * method05(n - 1);
    printf("soma = %d i = %d\n", soma, i);
    // i = i + 2;
    // soma = i * 2;
  }
  return soma;
}
void method_05(void)
{
  int n = G_readint("Digite o valor de N: ");
  printf("%d", method05(n));
}
double method06 (int n)
{
  double x = 6.0;
  double soma = 0.0;
  if(n > 0)
  {
    method06(n - 1);
    // printf("1/%lf ", x * n);
    // printf("1/%lf ", x / n);
    soma = soma + (1.0 / (x * n));
    // printf("%lf ", (1.0 / (x / n)));
  }
  return soma;
}
void method_06(void) 
{
  int n = G_readint("Digite o valor de n: ");
  printf("%lf", method06(n));
}
void method07 (int size, chars string)
{
  
  if(size+1 > 0)
  {
    method07(size - 1, string);
    printf("%c ", string[size]);
  }
  // for(int i = 0; i < size; i++)
  // {
  //   printf("%c ", string[i]);
  // }
}
void method_07(void)
{
  chars string = G_readstring("Digite a string: ");
  method07(strlen(string),string);
}
int method08(int size, chars string, int count)
{
  if(size > 0)
  {
    if(G_isDigit(string[size]) == 1 && string[size] % 2 == 0)
    {
      count++;
    } 
    return method08(size - 1, string, count);
  }
  return count;
}
void method_08(void)
{
  chars string = G_readstring("Digite a string: ");
  printf("%d", method08(strlen(string), string, 0));
  // method08(strlen(string), string);
}
int method09 (int size, chars string, int count)
{
  if(size > 0)
  {
    if(string[size] >= 'A' && string[size] < 'L')
    {
      count++;
    }
    return method09(size - 1, string, count);
  }
  return count;
}
void method_09(void) 
{
  chars string = G_readstring("Digite a string: ");
  printf("%d ", method09(strlen(string), string, 0));
}

// int fibonacci (int n)
// {
//   int resposta = 0;
//   if(n == 1 || n == 2)
//   {
//     resposta = 1;
//   }
//   else
//   {
//     if(n > 2)
//     {
//       resposta = fibonacci(n - 1) + fibonacci(n - 2);
//     }
//   }
//   return resposta;
// } 
// int method10(int n)
// {
//   int soma = 0;
//   if(n == 1 || n == 2)
//   {
//     soma = 1;
//   }
// }
void method_10(void) 
{
  // int n = G_readint("Digite n: ");
  // printf("%d", method10(n));
}
int method11e (int x, int n, int pot)
{
  int soma = 1;
  if(n > 1)
  {
    soma = pow(x,pot) + method11e(x, n - 1, pot+2);
  }
  return soma;
}
void method_11e(void) 
{
  int x = G_readint("Digite x: ");
  int n = G_readint("Digite n: ");
  printf("%d ", method11e(x,n,2));
}
void method_12e(void) 
{

}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 06");
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
