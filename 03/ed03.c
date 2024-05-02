/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
#include "io.h"

void method_01(void) 
{
  char* string = G_readstring ("Digite a palavra: ");
  int size = strlen(string);

  for(int i = 0; i < size; i++)
    {
      if(G_isMaiuscula(string[i]) == 1)
      {
        printf("%c", string[i]);
      }
    }
}

void method_02(void)
{
  char *string = G_readstring("Digite a palavra: ");
  int size = strlen(string);
  int count = 0;
  for(int i = 0; i < size; i++)
    {
      if(G_isMaiuscula(string[i]) == 1)
      {
        printf("%c", string[i]);
        count = count + 1;
      }
    }
  printf("\n%d", count);
}

void method_03(void)
{
  char *string = G_readstring( "Digite a palavra: ");
  int size = strlen(string);
  int count = 0;

  for(int i = size; i >= 0; i--)
    {
      if(G_isMaiuscula(string[i]) == 1)
      {
        printf("%c", string[i]);
        count = count + 1;
      }
    }
  printf("\n%d", count);
}

void method_04(void)
{
  char *string = G_readstring( "Digite a palavra: ");
  int size = strlen(string);
  int count = 0;

  for(int i = 0; i < size; i++)
    {
      if(G_isMaiuscula(string[i]) == 1 || G_isMinuscula(string[i]) == 1)
      {
        printf("%c", string[i]);	
        count = count + 1;
      }
    }
  printf("\n%d", count);
}

void method_05(void)
{
  char *string = G_readstring( "Digite a palavra: ");
  int size = strlen(string);
  int count = 0;

  for(int i = size; i >= 0; i--)
    {
      if(G_isDigit(string[i]) == 1)
      {
        printf("%c", string[i]);
        count = count + 1;
      }
    }
  printf("\n%d", count);
}

void method_06(void) 
{
  char *string = G_readstring( "Digite a palavra: ");
  int size = strlen(string);
  int count = 0;

  for(int i = 0; i < size; i++)
    {
      if(G_isSpecial(string[i]) == 1)
      {
        printf("%c", string[i]);
        count = count + 1;
      }
    }
  printf("\n%d", count);
}

void method_07(void)
{
  int n = G_readint("Digite a quantidade de vezes para testar: ");
  int a = G_readint("Digite o valor de a: ");
  int b = G_readint("Digite o valor de b: ");
  int count = 0;
  
  for(int i = 0; i < n; i++)
    {
      int x = G_readint("Digite o valor de x: ");
      if(x >= a && x <= b && x % 6 == 0)
        {
          count = count + 1;
        }
    }
  printf("\n%d", count);
}

void method_08(void)
{
  int n = G_readint("Digite a quantidade de vezes para testar: ");
  int a = G_readint("Digite o valor de a: ");
  int b = G_readint("Digite o valor de b: ");
  int count = 0;

  for(int i = 0; i < n; i++)
    {
      int x = G_readint("Digite o valor de x: ");
      if(x > a && x < b && x % 4 == 0 && x % 5 != 0)
      {
        count = count + 1;
      }
    }
   printf("\n%d", count);
}

void method_09(void) 
{
  int count = 0;
  double a = G_readdouble("Digite o valor de a: ");
  double b = 0.0;
  do
  {
    b = G_readdouble("Digite o valor de b: ");
    
  }while(a >= b);

  int n = G_readint("Digite a quantidade de vezes para testar: ");

  for(int i = 0; i < n; i++)
    {
      double x = G_readdouble("Digite o valor de x: ");

      if(x >= a && x <= b)
      {
        if((int)x % 2 == 0)
        {
          printf("%.2lf\n", x);
          count = count + 1;
        }
      }
    }
  printf("\nquantidade = %d", count);
}

void method_10(void) 
{
  double a = 0.0;
  double b = 0.0;
  double r = 0.0;
  int count  = 0;

  do
  {
      a = G_readdouble("Digite o valor de A: "); 
  }while(a <= 0.0 && a >= 1.0);

  do
  {
      b = G_readdouble("Digite o valor de B: "); 
  }while(b <= 0.0 && b >= 1.0);

  int n = G_readint("Digite a quantidade de vezes para testar: ");

  while(n > 0)
    {
      double x = G_readdouble("Digite o valor de x: ");
      r = x - (int) x;
      if(r <= a || r >= b)
      {
        printf("\n%.2lf", r);
        count = count + 1;
      }
      n = n - 1;
    }
  printf("\n%d", count);
}

char* method_11(char *string)
{
  int size = strlen(string);
  char* NewString = (char*)calloc(size + 1, sizeof(char));
  for(int i = 0; i < size; i++)
    {
      if(G_isSpecial(string[i]) == 1)
      {
        char* teste = IO_toString_c(string[i]);
        strcat(NewString, teste);
      }
    }
  
  return NewString;
}
void method_11e(void) 
{
  char *string = IO_readln("Digite a string: ");
  int size = strlen(string);

  char* resposta = method_11(string);
  printf("%s", resposta);
}
void method_12e(void) 
{
  char *string = G_readstring("Digite a string: ");
  int size = strlen(string);
  int count;

  for(int i = 0; i < size; i++)
    {
      if(G_isSpecial(string[i]) == 1 || G_isDigit(string[i]) == 1)
      {
        count = count + 1;
      }
    }
  if(count >= 1)
  {
    printf("A cadeia nao e feita apenas de letras");
  }
  else
  {
    printf("A cadeia e feita apenas de letras");
  }
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 03");
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