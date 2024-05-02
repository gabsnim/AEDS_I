/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
#include "io.h"
#include <math.h>

void method_01(void)
{
  int count = 0;
  int count1 = 0;
  double a = G_readdouble("Digite o valor de A: ");
  double b = G_readdouble("Digite o valor de B: ");

  int n = G_readint("Digite a quantidade de vezes para testar: ");
  count1 = n;
  while (n > 0)
  {
    double x = G_readdouble("Digite o valor de x: ");
    if (x >= a && x <= b)
    {
      count = count + 1;
    }
    n = n - 1;
  }
  count1 = count1 - count;
  printf("Quantidade de valores dentro do intervalo: %d\n", count);
  printf("Quantidade de valores fora do intervalo: %d\n", count1);
}
void method_02(void)
{
  char *string = G_readstring("Digite a cadeia de caracteres: ");
  int count = 0;
  for (int i = 0; i < strlen(string); i++)
  {
    if (G_isMaiuscula(string[i]) == 1)
    {
      if (string[i] > 'L')
      {
        printf("%c\n", string[i]);
        count = count + 1;
      }
    }
  }
  printf("%d\n", count);
}

int method03(chars string) // char*
{
  int x;
  for (int i = 0; i < strlen(string); i++)
  {
    if (G_isMaiuscula(string[i]) == 1 && string[i] > 'L')
    {
      x = x + 1;
    }
  }
  return x;
}
void method_03(void)
{
  chars string = G_readstring("Digite a string");
  int r = method03(string);
  printf("Maiusculas > L = %d", r);
}

chars method04(chars string)
{

  chars NewString = (char *)calloc(strlen(string) + 1, sizeof(char));
  for (int i = 0; i < strlen(string); i++)
  {
    if ((G_isMaiuscula(string[i]) == 1))
      if (string[i] > 'L')
      {
        {
          chars new = IO_toString_c(string[i]);
          strcat(NewString, new);
        }
      }
  }
  return NewString;
}
void method_04(void)
{
  chars string = G_readstring("Digite a string: ");
  chars NewString = method04(string);
  for(int i = 0; i < strlen(NewString); i++)
  {
    printf("%c ", NewString[i]);
  }
}
int method05(chars string)
{
  int count;
  for(int i = 0; i < strlen(string); i++)
  {
    if(G_isLetra(string[i]) == 1 )
    {
      printf("%c ", string[i]);
    }
  }
  return count;
}
void method_05(void)
{
  chars string = G_readstring("Digite a string: ");
  int count = method05(string);
  printf("%d", count);
}
void method_06(void)
{
  char *string = "ABCd3321@LDA";
  for(int i = 0; i < strlen(string); i++)
  {
    if(G_isSpecial(string[i]) == 1)
    {
      printf("%c ", string[i]);
    }
  }
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

int main(int argc, char *argv[])
{

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 03");
  printf("%s\n", "Autor: Gabriel Xavier Borges");
  printf("\n");

  do
  {

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

    switch (opcao)
    {
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
