/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
Recuperacao 01
*/

#include "gxb.h"
#include "io.h"
#include "recuperacao.h"

/*
  int exercicio01 (int x) 
  recebe x como parametro e calcula a soma dos divisores de x que sao impares
  retorna a soma
*/
int exercicio01 (int x)
{
  int soma = 0;

  for(int i = 1; i < x; i++)
  {
    if(x % i == 0 && i % 2 != 0)
    {
      // printf("%d\n", i);
      soma+= i;
    }
  }
  return soma;
}
/*
  void method_01 (void)
  recebe a quantidade de valores que serao digitados
  recebe os valores de x
  chama a funcao exercicio01 para cada valor de x
  mostra a soma dos divisores de x que sao impares
*/
void method_01(void) 
{
  int n = G_readint("Digite a quantidade: ");
  int x = 0;
  int soma = 0;

  while (n > 0)
  {
    x = G_readint("Digite o valor de x: ");
    soma = exercicio01(x);
    printf("soma = %d\n", soma);
    n--;
  }
  
}
/*
  bool exercicio02 (int x)
  recebe um valor de x
  retorna true se x for primo
  retorna false se x nao for primo
*/
bool exercicio02 (int x)
{
  bool resposta = false;
  int count = 0;

  for(int i = 2; i < x/2; i++)
  {
    if(x % i == 0)
    {
      count++;
    }
  }
  if(count == 0)
  {
    resposta = true;
  }

  return resposta;
}
/*
  void method02
  recebe uma quantidade de valores a serem digitados
  recebe os valores de x
  chama a funcao exercicio02
  imprime se o valor de x e primo ou nao
*/
void method_02(void)
{
  int n = G_readint("Digite a quantidade: ");
  int x = 0;

  for(int i = 0; i < n; i++)
  {
    x = G_readint("x = ");
    
    if(exercicio02(x))
    {
      printf("Primo\n");
    }
    else
    {
      printf("Nao e primo.\n");
    }
  }
}
/*
  int exercicio03
  recebe um caracter C e verifica se ele e um operador logico, aritmetico, relacional ou separador
  retorna o valor relacionado a cada tipo
*/
int exercicio03 (char c)
{
  int count = 0;

  if(c == '!' || c == '&' || c == '|')
  {
    count+= 1;
  }
  else if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
  {
    count+= 2;
  }
  else if(c == '>' || c == '<' || c == '=')
  {
    count+=3;
  }
  // else if (c == '.' || c == ';' || c == ',' || c == ':' || c == '_')
  else
  {
    count+=4;
  }

  return count;
}
/*
  void method03
  recebe um caracter C e manda para a funcao exercicio03
  usa o switch para verificar o retorno da funcao exercicio03
  e imprimir o tipo de operador
*/
void method_03(void)
{
  char c = G_readchar("Digite o caracter: ");
  int x = exercicio03(c);

  switch (x)                    //ou if else
  {
  case 1:
    printf("operador logico.\n");
    break;
  case 2:
    printf("aritmetico.\n");
    break;
  case 3:
    printf("relacional.\n");
    break;
  case 4:
    printf("separador.\n");
    break;
  default:
    break;
  }
}
/*
  Le uma string e manda para uma funcao
  se a funcao retornar true, aumenta um contador
*/
void method_04(void)
{
  int maiuscula = 0;
  int minuscula = 0;
  int digitos = 0;
  int operadores = 0;

  int count = 0;

  char *string;
  string = G_readstring("Digite a string: ");

  for(int i = 0; i < strlen(string); i++)
  {
    if(isMaiuscula(string[i]))
    {
      maiuscula++;
    }
    else if(isMinuscula(string[i]))
    {
      minuscula++;
    }
    else if(isOperador(string[i]))
    {
      operadores++;
    }
    else if(isDigit(string[i]))
    {
      digitos++;
    }
  }

  printf("Digitos = %d\n", digitos);
  printf("Maiusculas = %d\n", maiuscula);
  printf("Minusculas = %d\n", minuscula);
  printf("Operadores = %d\n", operadores);
}

/*
  Recebe 3 numeros double e verifica qual e o maior
  retorna o maior
*/
double exercicio05 (double media1, double media2, double media3)
{
  double media = 0.0;
  if(media1 > media2 && media1 > media3)
  {
    media = media1;
  }
  else if(media2 > media1 && media2 > media3)
  {
    media = media2;
  }
  else
  {
    media = media3;
  }

  return media;
}
/*
  Le 
*/
void method_05(void)
{
  int n = G_readint("Digite a quantidade: ");
  double x = 0.0;
  double count1 = 0.0;
  double count2 = 0.0;
  double count3 = 0.0;
  double soma1 = 0.0;
  double soma2 = 0.0;
  double soma3 = 0.0;


  for(int i = 0; i < n; i++)
  {
    x = G_readdouble("x = ");

    if(x < -17.25)
    {
      soma1 += x;
      count1++;
    } 
    else if(x >= -17.25 && x <= 93.75)
    {
      soma2 += x;
      count2++;
    }
    else 
    {
      soma3 += x;
      count3++;
    }
  }

  // printf("%lf\n", soma1);
  // printf("%lf\n", soma2);
  // printf("%lf\n", soma3);
  // printf("%lf\n", count1);
  // printf("%lf\n", count2);
  // printf("%lf\n", count3);
  if(count1 > 0 && count2 > 0 && count3 > 0)
  {
    double media1 = soma1 / count1;
    double media2 = soma2 / count2;
    double media3 = soma3 / count3;

    printf("%lf", exercicio05(media1, media2, media3));
  }
  else
  {
    printf("erro ao dividir por 0");
  }

}
/*
  recebe A e B
  le e identifica se X faz parte deste intervalo
  soma o cubo dos inversos 
  retorna soma
*/
double exercicio06 (int a, int b)
{
  int x = 0;
  double y = 1.0;
  double cubo = 0.0;
  double soma = 0.0;
  do
  {
    x = G_readint("Digite o valor de x: ");
    if(x > a && x < b)
    {
      if(x % 2 != 0)
      {
        y = y / x;
        cubo = y * y * y;
        soma += cubo;
      }
    }  
  } while (x != -1);

  return soma;

}
/*
  Envia para a funcao exercicio06 o valor de A e B e imprime a resposta dada pela funcao
*/
void method_06(void) 
{
  int a = G_readint("Digite o valor de A: ");
  int b = G_readint("Digite o valor de B: ");

  printf("%lf", exercicio06(a, b));
  
}
/*
  recebe A e B como limites de um intervalo
  retorna se X esta dentro ou nao deste intervalo
*/
bool exercicio07 (double a, double b, double x)
{
  bool resposta = false;
  if(x > a && x < b)
  {
    resposta = true;
  }
  return resposta;
}
/*
  Envia para a funcao exercicio07 o valor de A e B
  Calcula a porcentagem de valores acima e abaixo do intervalo
*/
void method_07(void)
{
  double a = G_readdouble("Digite o valor de A: ");
  double b = G_readdouble("Digite o valor de B: ");
  double x = 0.0;
  int count1 = 0; //dentro
  int count2 = 0; //fora
  int acima = 0;
  int abaixo = 0;
  int total = 0;

  do
  {
    x = G_readdouble("x = ");
    if(x != 0)
    {
      if(exercicio07(a, b, x) == false)
      {
        count2++;
      }
      else
      {
        count1++;
      }

      if(x > b)
      {
        acima++;
      }
      else if(a > x)
      {
        abaixo++;
      }
      total++;
    }
  } while (x != 0);

  double porc1 = (100.0 / total) * acima;
  double porc2 = (100.0 / total) * abaixo;

  printf("total = %d\n", total);
  printf("dentro do intervalo %d\n", count1);
  printf("fora do intervalo %d\n", count2);
  printf("acima = %d\n", acima);
  printf("abaixo = %d\n", abaixo);
  printf("%lf porcento acima\n", porc1);
  printf("%lf porcento abaixo\n", porc2);
  
}
/*
  recebe X, Y e Z
  retorna se estao em ordem crescente, decrescente, se sao iguais ou nenhuma dessas alternativas
*/
int exercicio08 (double x, double y, double z)
{
  int count = 0;
  if(x > y && y > z)  //decrescente
  {
    return 1;
  }
  else if(x < y && y < z) //crescente
  {
    return 2;
  }
  else if(x == y && x == z)
  {
    return 3;
  }
  else
  {
    return 0;
  }
}
void method_08(void)
{
  double x = G_readdouble("Digite o valor de x: ");
  double y = G_readdouble("Digite o valor de y: ");
  double z = G_readdouble("Digite o valor de z: ");

  if(exercicio08(x, y, z) == 1)
  {
    printf("decrescente.");
  }
  else if(exercicio08(x, y, z) == 2)
  {
    printf("crescente.");
  }
  else if(exercicio08(x, y, z) == 3)
  {
    printf("maior.");
  }
  else
  {
    printf("menor.");
  }
}

/*
  Recebe 3 caracteres e retorna 1 se X < Y < Z, 2 se X > Y > Z e 3 se nenhum deles 
*/
int exercicio09 (char x, char y, char z)
{
    int a = x - 48;
    int b = y - 48;
    int c = z - 48;

    if(a < b && b < c)
    {
        return 1;
    }
    else if(a > b && b > c)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
/*
  Le e envia 3 caracteres para a funcao exercicio09
  armazena o retorno na variavel resposta
  mostra na tela o resultado de acordo com o retorno da funcao
*/
void method_09(void) 
{
    char x =  G_readchar("Digite x:");
    char y =  G_readchar("Digite y:");
    char z =  G_readchar("Digite z:");

    int resposta = exercicio09(x, y, z);

    if(resposta == 1)
    {
        printf("crescente");
    }
    else if(resposta == 2)
    {
        printf("decrescente");
    }
    else
    {
        printf("sucessor");
    }
}
/*
  Recebe 3 strings e verifica se elas estao em ordem crescente, decrescente ou nenhuma delas
*/
int exercicio10(char *x, char *y, char *z)
{
  if(strcmp(x, y) < 0)
  {
    if(strcmp(y, z) < 0)
    {
      // printf("crescente");
      return 1;
    }
  }
  else if(strcmp(x, y) > 0)
  {
    if(strcmp(y, z) > 0)
    {
      // printf("decrescente");
      return 2;
    }
  }
  else if(strcmp(x, y) == 0)
  {
    if(strcmp(y, z) == 0)
    {
      // printf("iguais");
      return 3;
    }
  }
  else
  {
      // printf("diferentes");
      return 0;
  }
}
/*
  Envia para a funcao exercicio10 as strings x, y e z
  mostra na tela se elas sao crescentes, decrescentes, iguais ou se nao estao em ordem 
  de acordo com o inteiro retornado
*/
void method_10(void) 
{
  char *x;
  char *y;
  char *z;
  x = G_readstring("Digite a string x: ");
  y = G_readstring("Digite a string y: ");
  z = G_readstring("Digite a string z: ");

  int tamanhoX = strlen (x);
  int tamanhoY = strlen (y);
  int tamanhoZ = strlen (z);
  
  int resposta = exercicio10(x, y, z);

  if(resposta == 1)
  {
    printf("crescente.");
  }
  else if(resposta == 2)
  {
    printf("decrescente.");
  }
  else if(resposta == 3)
  {
    printf("iguais.");
  }
  else
  {
    printf("não está em ordem.\n");
  }

  if(resposta == 0)
  {
    if(tamanhoX > tamanhoY && tamanhoX > tamanhoZ)
    {
      printf("\nmaior = %s", x);
    }
    else if(tamanhoY > tamanhoX && tamanhoY > tamanhoZ)
    {
      printf("\nmaior = %s", y);
    }
    else
    {
      printf("\nmaior = %s", z);
    }

    if(tamanhoX < tamanhoY && tamanhoX < tamanhoZ)
    {
      printf("\nmenor = %s", x);
    }
    else if(tamanhoY < tamanhoX && tamanhoY < tamanhoZ)
    {
      printf("\nmenor = %s", y);
    }
    else
    {
      printf("\nmenor = %s", z);
    }
  }
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Recuperacao 01");
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
    default:
      printf("\nERRO: Opcao invalida.\n");
      break;
    }
  } while (opcao != 0);

  printf("\n\nApertar ENTER para terminar.");
  getchar();
  return (0);
}
