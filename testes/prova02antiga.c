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