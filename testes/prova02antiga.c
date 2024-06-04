/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"



void method_01(void) 
{

}   
void method_02(void) 
{

}
void method_03(void)
{
 
}

int f04(int x, char *s)
{
  int result = 0;
  if(0 <= x && x < strlen(s))
  {
    result = (s[x] == '0' || s[x]=='1') && f04 (x+1, s);
  }
  else
  {
    result = 1;
  }
  return result;
}
void method_04(void) 
{
  printf("%d", f04(3, "01|O"));
  printf("\n%d", f04(2, "0|10"));
  printf("\n%d", f04(1, "O101"));
  printf("\n%d", f04(0, "0101"));    
}
void method_05(void) 
{
  int array [] [3] = {{0,1,2}, {3,4,5}, {6,7,8}};
  int x = 0, y = 0, z = 0;
  
  for(x=0; x < 3; x++)
  {
    z = array[2-x][2-x];
    for(y = 2; y>= 0; y = y - 1)
    {
      array[y][x] = array [x][y];
      if(x == y) { array[x][y] = z;}
    }}
    for( x = 0; x < 3; x++)
    {
      for(y = 0; y < 3; y++)
      {
        printf("%d ", array[x][y]);}
        printf("\n");}
}

char* f06 (int start, int end, char *source)
{
  char *destiny = NULL;
  int x = 0, y = 0;
  destiny = malloc(strlen(source) * sizeof(char));
  destiny[y] = '\0';

  for(x = start; x < end; x++)
  {
    destiny[y] = source[x];
    y++;
  }
  return destiny;
}
void method_06(void)
{
  printf("1 = %s", f06(1,4, "abcde"));
    printf("\n 2= %s", f06(4,6, "abcde"));
      printf("\n3=%s", f06(0,3, "abcde"));
        printf("\n4=%s", f06(3,5, "abcde"));
}
void method_07(void) 
{

}
void method_08(void) 
{

    struct Squestao
    {
      int dia ;
      int mes ;
      int ano ;
    } questao;
    
    int dia, mes, ano = 0;
    int dia1, mes1, ano1 = 0;
    scanf("%d", &dia1);
    scanf("%d", &mes1);
    scanf("%d", &ano1);

    int aux;
    double boletos = 0.0;
    FILE* arquivo = fopen ("DATAS.TXT", "rt");
    FILE* arquivo1 = fopen ("BOLETOS.TXT", "wt");
    if (arquivo == NULL)
    {
        printf("ERRO no arquivo\n,");
    }
    else
    {
        fscanf(arquivo, "%d", &dia);
        while(!feof(arquivo))
        {
            fscanf(arquivo, "%d", &mes);
            fscanf(arquivo, "%d", &ano); //16
            fscanf(arquivo, "%lf", &boletos);
            // printf("%d\n", dia);
            // printf("%d\n", mes);
            // printf("%d\n", ano);
            // printf("%lf\n", boletos);

            if(dia > ano)
            {
                aux = ano; //aux = 16;
                ano = dia; //ano = 2004;
                dia = aux;
            }
            if(arquivo1 == NULL)
            {
                printf("ERRO no arquivo\n,");
            }
            else
            {  
                if(boletos == 0)
                {
                    fprintf(arquivo1, "0\n");
                }
                else if(dia == dia1 && mes == mes1 && ano == ano1)
                {
                    fprintf(arquivo1, "%lf\n", boletos);
                }
            }
            fscanf(arquivo, "%d", &dia);
            
        }
        fclose(arquivo);
        fclose(arquivo1);
    }
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
    }
  } while (opcao != 0);

  printf("\n\nApertar ENTER para terminar.");
  getchar();
  return (0);
}