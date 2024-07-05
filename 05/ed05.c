/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/

#include "gxb.h"
#include "io.h"


void method01 (int n)
{
  int y = 6;
  for(int i = 0; i < n; i++)
  {
    printf("%d\n", y);
    y = y + 6;
  }
}
void method_01(void) 
{
    int n = G_readint("valor de N: ");
    method01(n);
}

void method02 (int n)
{
  int y = 15;
  while(1 <= n)
  {
    if((y % 5 == 0) && (y % 3 == 0))
    {
    printf("%d\n", y);
    n--;
    }
    y = y + 5;
  }
}
void method_02(void)
{
  int n = G_readint("valor de N: ");
  method02(n);
}

void method03 (int n)
{
  while(n > 0)
  {
    printf("%d\n", G_pot(4, n));
    n = n - 1;
  }
}
void method_03(void)
{
    int n = G_readint("Digite o valor de N: ");
    method03(n);
}

int method04 (int x)
{
  return x = x + 6;
}
void method_04(void)
{
  int x = 0;
  int n = G_readint("Digite o valor de N: ");
  for(int i = 0; i < n; i++)
  {
    printf("1/%d\n",  x = method04(x));
  }
}

void method_05(void)
{

}

int method06(int n)
{
  int soma = 0;
  int x = 3;
  while(0 < n)
  {
    if((x % 5 != 0) && (x % 3 == 0))
    {
      soma = soma + x;
      n = n - 1;
    }
    x = x + 1;
  }
  return soma;
}
void method_06(void) 
{
  int n = G_readint("Digite o valor n: ");
  printf("%d\n", method06(n));
}

double method07 (int n)
{
  double soma = 1.0;
  int y = 6;
  while(n > 0)
  {
    if((y % 6 == 0) && (y % 5 != 0))
    {
      // printf("%lf   /   %d\n", soma, y);
      soma = soma + (1.0 / y);
      n = n - 1;
    }
    y = y + 6.0;
  }
  return soma;
}
void method_07(void)
{
  int n = G_readint("Digite o valor de N: ");
  printf("%lf\n", method07(n));
}

int method08 (int n)
{
  int soma = 0;
  int x = 6;
  int y = 1;
  while(n > 0)
  {
    soma = soma + x;
    // printf("x = %d y = %d\n ", x, y);
    x = x + y;
    y++;
    n = n - 1;
  }
  return soma;
}
void method_08(void)
{
  int n = G_readint("Digite o valor de N: ");
  printf("%d",method08(n));
}

int method09 (int n)
{
  int soma = 0;
  int x = 6;
  while (n > 0)
  {
    soma = soma + G_pot(x, 2);
    // printf("soma  = %d  x = %d\n", soma, x);
    x = x + 1;
    n = n - 1;
  }
  return soma;
}
void method_09(void) 
{
  int n = G_readint("Digite o valor de N: ");
  printf("%d", method09(n));
}

int method10_1 (int n)
{
  int soma = 6;
  n = n - 1;
  while(n > 0)
  {
    soma = soma + n;
    n--;
  }
  return soma;
}
double method10 (int n)
{
  double soma = 0.0;

  int aux = method10_1(n);
  int aux1 = n - 1;
  for(int i = 1; i <= n; i++)          
  {
    soma = soma + (1.0 / aux);
    aux = aux - aux1;
    aux1 = aux1 - 1; //3 
  }
  return soma;
}
void method_10(void) 
{
  int n = G_readint("Digite o valor de N: ");
  printf("%lf", method10(n));
  // printf("%d",method10_1(n));
}

// double method10 (int n)
// {
//     int  y, soma = 0;
//     double resultado = 0.0;

//     y = 6;
//     for (int i = 0; i < n; i++) {
//         if(y != 0)
//         {
//         resultado = resultado + (1.0 / y);
//         soma = soma + y;
//         y = soma - y; 
//         }
//     }
//     return resultado;
// }
// void method_10(void)
// {
//   int n = G_readint("Digite o valor de N: ");
//   printf("%lf", method10(n));
// }

int method11e (int n)
{
    if(n == 0 || n == 1)
    {
      return 1;
    }
    else
    {
      return n * method11e(n - 1);
    }
}
void method_11e(void) 
{
  int n = G_readint("Digite o numero para calcular o fatorial: ");
  printf("%d", method11e(n));
}

double method12e(int n)
{
  double soma = 1.0;
  int x = 2;
  int y = 5;
  for(int i = 0; i < n; i++)
  {
    soma = soma * (1 + (x / G_fac(y)));
    x = x * 2;
    y = y + 2;
  }
  return soma;
}
void method_12e(void) 
{
  int n = G_readint("Digite o valor de N: ");
  printf("%lf", method12e(n));
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 05");
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
