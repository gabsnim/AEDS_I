/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"


void q01(int *a, int *b)
{
    int c = 0;
    if(*a > *b)
    {
        c = *a;
        *a = *b;
        *b = c;
    }
}
void method_01(void) 
{
    int x = 5, y = 3;
    q01(&x,&y);
    printf("x = %d y = %d", x, y);
}

double q02 (int matriz[][3], int rows, int cols)
{
    int soma1, soma2 = 0;
    double razao = 0.0;
    if(rows != cols)
    {
        printf("ERRO");
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if((i + j) > rows - 1)
                {
                    soma1+= matriz[i][j];
                }
                else if(j > i)
                {
                    soma2+= matriz[i][j] - 1;
                }
            }
        }
        razao = soma1 / soma2;
    }
    return razao;
}
void method_02(void) 
{
    int matriz [3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    printf("%lf", q02(matriz, 3,3));
}
void method_03(void)
{
 
}
void method_04(void) 
{

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