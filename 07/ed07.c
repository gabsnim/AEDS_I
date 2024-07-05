/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/

#include "gxb.h"
#include "io.h"

// Exercicio 01

void exercicio01 (chars Filename, int n)
{
    FILE* arquivo = fopen(Filename, "wt");
    if(arquivo == NULL)
    {
        G_printERROFILE();
    }
    else
    {
        for(int i = 4; i <= 4*n; i = i + 4)
        {
            fprintf(arquivo, "%d\n", i);
        }
        printf("Dados gravados com sucesso em %s", Filename);
    }
    fclose(arquivo);
}

void method_01(void) 
{
    int n = G_readint("Digite um numero: ");
    exercicio01("DADOS1.TXT", n);
}

// Exercicio 02

void exercicio02 (FILE* arquivo, int n, int x)
{
    if(n > 0)
    {
      if(x % 2 != 0)
      {
        exercicio02(arquivo, n - 1, x + 5);
        fprintf(arquivo, "%d\n", x);
        // printf("%d ", x);
      }
      else
      {
        exercicio02(arquivo, n, x + 5);
      }
    }
}

void method_02(void)
{
  int n = G_readint("Digite um numero: ");

  FILE* arquivo = fopen("DADOS2.TXT", "wt");

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    exercicio02(arquivo, n, 25);
    printf("Dados gravados com sucesso em DADOS2.TXT");
    fclose(arquivo);
  }
}

// Exercicio 03

void exercicio03 (chars Filename, int n)
{
  FILE* arquivo = fopen(Filename, "wt");

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }

  for(int i = 0; i < n; i++)
  {
    // G_pow(5, i);
    fprintf(arquivo, "%d\n", G_pot(5, i));
  }
  printf("Dados gravados com sucesso em %s", Filename);
  fclose(arquivo);
}
void method_03(void)
{
  int n = G_readint("Digite um numero: ");
  exercicio03("DADOS3.TXT", n);  
}

// Exercicio 04

void exercicio04(chars Filename, int n)
{
  FILE* arquivo = fopen(Filename, "wt");

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }

  else
  {
    for(int i = n-1; i >= 0; i--)
    {
     if(i > 0)
      {
        fprintf(arquivo, "1/%d\n", G_pot(5, i));
      }
      else
     {
        fprintf(arquivo, "1\n");
      }
    }
    printf("Dados gravados com sucesso em %s", Filename);
    fclose(arquivo);
  }
}
void method_04(void)
{
  int n = G_readint("Digite um numero: ");
  exercicio04("DADOS4.TXT", n);
}

// Exercicio 05

void exercicio05 (chars Filename, int n, double x)
{
  FILE* arquivo = fopen (Filename, "wt");
  int y = 3;
  double aux = 0.0;
  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  { 
    for(int i = 0; i < n; i++)
    {
      if(i == 0)
      {
        fprintf(arquivo, "1\n");
      }
      else
      { 
        aux = 1.0 / (pow(x, y));
        // printf("1/%lf^%d\n", x, y);
        // printf("%lf\n", aux);
        fprintf(arquivo, "%lf\n", aux);
        y = y + 2;
      }
    }
    printf("Dados gravados com sucesso em %s", Filename);
    fclose(arquivo);
  }
}
void method_05(void)
{
  int n = G_readint("Digite uma quantidade: ");
  double x = G_readdouble("Digite um numero: ");

  exercicio05("DADOS5.TXT", n, x);
}

// Exercicio 06

void exercicio06 (chars Filename, int n)
{
  FILE* arquivo1 = fopen("DADOS5.TXT", "rt");
  FILE* arquivo2 = fopen(Filename, "wt");
  double x = 0.0;
  double y = 0.0;
  int aux = n;

  if(arquivo1 == NULL || arquivo2 == NULL)
  {
    printf("ERRO ao abrir arquivo(s)");
  }
  else
  {
    fscanf(arquivo1, "%lf", &x);

    while (! feof(arquivo1) && n > 0)
    {
      fscanf(arquivo1, "%lf", &y);
      x = x + y;
      n--;
    }
    fprintf(arquivo2, "%d\n%lf", aux, x);
  }
  fclose(arquivo1);
  fclose(arquivo2);
}
void method_06(void) 
{
  int n = G_readint("Digite a quantidade de valores a serem somados: ");
  exercicio06("RESULTADO06.TXT", n);
}

// Exercicio 07

void exercicio07 (chars Filename, int n)
{
  // FILE* arquivo1 = fopen(Filename, "wt");
  // FILE* arquivo2 = fopen("DADOS4.TXT", "rt");
  // double x = 0.0;
  // double soma = 0.0;
  // if(arquivo1 == NULL || arquivo2 == NULL)
  // {
  //   printf("ERRO ao abrir arquivo(s)");
  // }
  // else
  // {
  //   while (! feof(arquivo2) && n > 0)
  //   {
  //     if(fscanf(arquivo2, "%lf", &x) != EOF)
  //     {
  //       soma = soma + x;
  //     }
  //     n--;
  //   }
    
  //   fprintf(arquivo1, "%lf\n", soma);
  //   printf("Dados gravados com sucesso em %s", Filename);
  //   fclose(arquivo1);
  //   fclose(arquivo2);
  // }
}
void method_07(void)
{
  // int n = G_readint("Digite uma quantidade: ");
  // exercicio07("RESULTADO07.TXT", n);
}

// Exercicio 08

void exercicio08 (chars Filename, int n)
{
  FILE *arquivo = fopen(Filename, "w");
  int i = 0;
  int x = 1;
  int y = 0;  //termo1
  int z = 1;  //termo2
  if (arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    while(i < n)
    {
      if(x % 2 == 0)
      {
        printf("%d\n", x);
        fprintf(arquivo, "%d\n", x);
        i++;
      }
      x = y + z;
      y = z;
      z = x;
      x = z;
    }
    fclose(arquivo);
  }
}
void method_08(void)
{
  int n = G_readint("Digite uma quantidade: ");
  exercicio08("RESULTADO08.TXT", n);
}

// Exercicio 09

void exercicio09 (chars Filename)
{
  FILE* arquivo1 = fopen("STRING1.TXT", "rt"); // arquivo criado manualmente para guardar a string desejada
  FILE* arquivo2 = fopen(Filename, "wt");

  char c;
  int count = 0;

  if(arquivo1 == NULL || arquivo2 == NULL)
  {
    printf("ERRO ao abrir arquivo(s)");
  }
  else
  {
    while (! feof(arquivo1))
    {
      fscanf(arquivo1, "%c", &c);
      if(G_isMaiuscula(c))
      {
        count++;
        fprintf(arquivo2, "%c\n", c);
      }
    } 
    fprintf(arquivo2, "quantidade = %d\n", count);
    printf("Dados gravados com sucesso em %s", Filename);
    fclose(arquivo1);
    fclose(arquivo2);
  }
}
void method_09(void) 
{
  exercicio09("RESULTADO09.TXT");
}

// Exercicio10

void exercicio10 (chars Filename)
{
  FILE* arquivo1 = fopen("STRING2.TXT", "rt"); // Arquivo criado manualmente para guardar a string desejada
  FILE* arquivo2 = fopen(Filename, "wt");

  char c;
  int count = 0;

  if(arquivo1 == NULL || arquivo2 == NULL)
  {
    printf("ERRO ao abrir arquivo(s)");
  }
  else
  {
    while(! feof(arquivo1))
    {
      fscanf(arquivo1, "%c", &c);
      
      if(G_isDigit(c) == 1 && c >= '5')
      {
        fprintf(arquivo2, "%c ", c);
        count++;
      }
    }
    fprintf(arquivo2, "\n%d\n", count);
    fclose(arquivo1);
    fclose(arquivo2);
  }
}
void method_10(void) 
{
  exercicio10("RESULTADO10.TXT");
}

void method_11e(void) 
{

}

// Exercicio 12

void exercicio12(chars Filename)       // Resultados errados
{
  FILE *arquivo = fopen(Filename, "rt");

  char string [80];
  int count = 0;
  int i = 0;

  if (arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    while(fgets(string, sizeof(string), arquivo) != NULL)
    {
      fscanf(arquivo, "%s", string);
      if(string[0] == 'c' || string[0] == 'C')
      {
        count++;
        string[i] = '\0';
      }
      i++;
    }
    printf("%d\n", count);
    fclose(arquivo);
  }
}
void method_12e(void) 
{
  exercicio12("EXTRA2.TXT");
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 07");
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
