/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/

#include "gxb.h"
#include "io.h"

// void exercicio01 (int n, int array [])
// {
    
// }
void method_01(void) 
{
    int n = 0;
    int *array = NULL;
    int x = 0;

    do
    {
        n = G_readint("Digite um valor para o tamanho do arranjo: ");
    } while (n < 1);

    // array = (int *)malloc(n * sizeof(int));
    array = malloc(n * sizeof(int));

    if(array == NULL)
    {
        printf("ERRO ao alocar memoria para o array\n");
    }
    else
    {   
        for(int i = 0; i < n; i++)
        {
            do
            {
                printf("Elemento %d = ", i);
                x = G_readint("");
            } while (x % 2 != 0 && x > 0);
            array[i] = x;
        }
        G_printarray(n, array);

        free(array);
    }
}

// Exercicio 02

void exercicio02 (chars Filename, int *array)
{
    // FILE* arquivo = fopen (Filename, "rt");  //arquivo para leitura 
    // FILE* arquivo1 = fopen ("DADOS1.TXT", "wt");  //arquivo para escrita
    // int i = 0;
    // int y = 0;
    // int x = 0;


    // if(arquivo1 == NULL || arquivo == NULL)
    // {
    //     printf("ERRO ao abrir arquivo(s)\n");
    // }
    // else
    // {
    //     fscanf(arquivo, "%d", &n);

    //     if(n > 1)
    //     {
            
    //     }
    //     array = malloc(n * sizeof(int));

    //     if(array == NULL)
    //     {
    //         printf("ERRO ao alocar memoria para o arranjo\n");
    //     }

    //     while (! feof(arquivo) && i < n)
    //     {
    //         fscanf(arquivo, "%d", &y);
    //         array[i] = y;               // armazenar
    //         i++;
    //     }
    //     // G_printarray(n, array);

    //     for(int j = 0; j < n; j++)
    //     {
    //         if(array[j] % 2 != 0 && array[j] > 0)
    //         {
    //             x = array[j];
    //             fprintf(arquivo1, "%d\n", x);
    //         }
    //     }
    // }
    // fclose(arquivo1);
    // fclose(arquivo);
}
void method_02(void)
{
    // int *array = NULL;
    // int n = 0;

    // do
    // {
    //     G_readint("Digite um valor para o tamanho do array: \n");
    // } while (1 < n);
    
    // array = malloc(n * sizeof(int));

    // if(array == NULL)
    // {
    //     printf("ERRO ao alocar memoria para o arranjo\n");
    // }
    // else
    // {
    //     exercicio02("LEITURA1.TXT", n, array);
    // }
    // exercicio02("LEITURA1.TXT", array);
    
}

void exercicio03 (int a, int b, int n)
{
  FILE* arquivo = fopen("DADOS.TXT", "wt");
  int *array = NULL;
  int i = 0;
  int x = 0;

  array = malloc(n * sizeof(int));

  if(array == NULL)
  {
    printf("ERRO ao alocar memoria para arranjo\n");
  }
  else
  {
    while(i < n)
    {
      x = rand() % 100;
      if(x >= a && x <= b)
      {
        array[i] = x;
        i++;
      }
    }
  }
  // G_printarray(n, array);
  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fprintf(arquivo, "%d\n", n);
    for(int j = 0; j < n; j++)
    {
      fprintf(arquivo, "%d\n", array[j]);
    }
    printf("Dados gravados com sucesso em DADOS.TXT\n");
  }
  fclose(arquivo);
}
void method_03(void)
{
  int a = G_readint("Digite o inferior do intervalo: ");
  int b = G_readint("Digite o superior do intervalo: ");
  int n = G_readint("Digite o valor de numeros a serem gerados: ");
  exercicio03(a, b, n);
}

int *exercicio04 (chars Filename, int *ref)  // ler os dados do arquivo, passar como referencia o tamanho do arranjo e retornar o arranjo
{
  FILE* arquivo = fopen(Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));
    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para arranjo.\n");
    }
    else
    {
      while(!feof (arquivo) && x < n)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;
      }
    }
  }
  fclose(arquivo);
  // G_printarray(n, array);
  return ( array );
}
int exercicio04_1(int *array, int n)  // retornar o menor valor impar do arranjo
{
  int x = 0;
  int y = 0;
  y = array[0];
  for(int i = 0; i < n; i++)
  {
    if(array[i] % 2 != 0)
    {
      x = array[i];
      if(y > x)
      {
        y = x;
      }
    }
  }
  return y;
}
void method_04(void)
{
  int n = 0;
  int *array = exercicio04("DADOS.TXT", &n);
  int resposta = exercicio04_1(array, n);
  printf("menor valor impar do arranjo = %d\n", resposta);
}

int *exercicio05 (chars Filename, int *ref) // ler os dados do arquivo, passar como referencia o tamanho do arranjo e retornar o arranjo
{
  FILE* arquivo = fopen (Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));
    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para arranjo.\n");
    }
    else
    {
      while(!feof(arquivo) && x < n)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;      
      }
    }
  }
  fclose(arquivo);
  return (array);
}
int exercicio05_1 (int *array, int n) // retornar o maior valor impar do arranjo
{
  int y = 0;
  int x = 0;

  for(int i = 0; i < n; i++)
  {
    if(array[i] % 2 != 0)
    {
      x = array[i];
      if(y < x)
      {
        y = x;
      }  
    }
  }
  return y;
}
void method_05(void)
{
  int n = 0;
  int *array = exercicio05("DADOS.TXT", &n);
  int resposta = exercicio05_1(array, n);
  // G_printarray(n, array);
  printf("maior valor impar do arranjo = %d\n", resposta);
}


int *exercicio06 (chars Filename, int *ref) // ler os dados do arquivo, passar o tamanho como referencia e retornar o arranjo
{
  FILE* arquivo = fopen (Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));
    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para arranjo.\n");
    }
    else
    {
      while(!feof(arquivo) && n > x)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;
      }
    }
  }
  // G_printarray(n, array);
  fclose (arquivo);
  return (array);
}

int exercicio06_1 (int *array, int n) // achar e retornar a media  
{
  int media = 0;

  for(int i = 0; i < n; i++)
  {
    media += array[i];
  }
  media = media / n;

  return (media);
}

void method_06(void) // gravar os valores em arquivos
{
  int n = 0;
  int *array = exercicio06("DADOS.TXT", &n);
  
  int media = exercicio06_1(array, n);
  int x = 0;
  // G_printarray(n, array);

  FILE* arquivo1 = fopen ("EXERCICIO06_1.TXT", "wt");
  FILE* arquivo2 = fopen ("EXERCICIO06_2.TXT", "wt");

  if(arquivo1 == NULL || arquivo2 == NULL)
  {
    printf("ERRO ao abrir arquivo(s).\n");
  }
  else
  {
    for(int i = 0; i < n; i++)
    {
      x = array[i];
      if(array[i] <= media)
      {
        fprintf(arquivo1, "%d\n", x);
      }
      else
      {
        fprintf(arquivo2, "%d\n", x);
      }
    }
  }
  fclose(arquivo1);
  fclose(arquivo2);
  printf("Valores <= a media gravados em EXERCICIO06_1\n");
  printf("Valores > a media gravados em EXERCICIO06_2\n");
}

bool exercicio07 (int *array, int n)
{
  int count = 0;
  bool resposta = false;

  for(int i = 1; i < n; i++)
  {
    if(array[i] > array[i - 1])
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

void method_07(void)
{
  int *array = NULL;
  int n = G_readint("Digite o tamanho do array: ");
  array = malloc(n * sizeof(int));

  G_readarray(n, array);

  bool resposta = exercicio07(array, n);
  // exercicio07(array, n);

  if(resposta == true)
  {
    printf("O array esta em ordem decrescente. ");
    G_printarray(n, array);
  }
  else
  {
    printf("O array nao esta em ordem decrescente. ");
    G_printarray(n, array);
  }
}

int *exercicio08 (chars Filename, int *ref) //ler dados do arquivo e guardar num arranjo
{
  FILE* arquivo = fopen (Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));

    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para arranjo. ");
    }
    else
    {
      while(!feof(arquivo) && x < n)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;
      }
    }
  }
  fclose(arquivo);
  return (array);
}

bool exercicio08_1 (int *array, int n, int valor, int posicao)
{
  bool resposta = true;
  int count = 0;
  int i = posicao;

  while(i < n)
  {
    if(array[i] == valor)
    {
      count++;
    }
    i++;
  }

  if(count == 0)
  {
    resposta = false;
  }

  return (resposta);
}
void method_08(void)
{ 
  int *array = NULL;
  int n = 0;
  array = exercicio08("DADOS.TXT", &n);

  int valor = G_readint("Digite o valor a ser procurado no arranjo: ");
  int posicao = G_readint("Digite a posicao para comecar a procura: ");

  bool resposta = exercicio08_1(array, n, valor, posicao);

  for(int i = 0; i < n; i++)
  {
    printf("posicao %d = %d\n",i, array[i]);
  }

  if(resposta)
  {
    printf("O valor %d EXISTE no arranjo a partir da posicao %d.\n", valor, posicao);
  }
  else
  {
    printf("O valor %d NAO existe no arranjo a partir da posicao %d.\n", valor, posicao);
  }
}
int *exercicio09 (chars Filename, int *ref)
{
  FILE* arquivo = fopen (Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));
    
    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para arranjo.\n");
    }
    else
    {
      while (!feof(arquivo) && x < n)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;
      }
    }
  }
  fclose(arquivo);
  return (array);
}

int exercicio09_1 (int *array, int n, int posicao, int valor)
{
  int resposta = 0;
  int i = posicao;
  int count = 0;
  while(i < n)
  {
    if (array[i] == valor)
    {
      resposta = i;
      count++;
    }
    i++;
  }
  if(count >= 1)
  {
    return resposta;
  }
  else
  {
    return -1;
  }
}

void method_09(void) 
{
  int *array = NULL;
  int n = 0;
  array = exercicio09("DADOS.TXT", &n);

  // G_printarray(n, array);
  
  int valor = G_readint("Digite o valor para ser procurado no array: ");
  int posicao = G_readint("Digite a posicao para comecar a busca: ");

  int resposta = exercicio09_1(array, n, posicao, valor);

  G_printarray(n, array);
  if(resposta > 0)
  {
    printf("\na posicao que o valor foi encontrada e: %d", resposta);
  }
  else
  {
    printf("\nO valor nao foi encontrado no array.\n");
  }
}

int *exercicio10 (chars Filename, int *ref)
{
  FILE* arquivo = fopen (Filename, "rt");
  int *array = NULL;
  int n = 0;
  int x = 0;
  int y = 0;

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &n);
    *ref = n;
    array = malloc(n * sizeof(int));

    if(array == NULL)
    {
      printf("ERRO ao alocar memoria para array.\n");
    }
    else
    {
      while (!feof(arquivo) && x < n)
      {
        fscanf(arquivo, "%d", &y);
        array[x] = y;
        x++;
      }
    }
  }
  fclose(arquivo);
  return (array);
}

int exercicio10_1 (int *array, int n, int valor, int posicao)
{
  int count = 0;
  int i = 0;
  // G_printarray(n, array);
  for(int i = posicao; i < n; i++)
  {
    if(array[i] == valor)
    {
      count++;
    }
  }
  return count;
}
void method_10(void) 
{
  int *array = NULL;
  int n = 0;
  int count = 0;
  array = exercicio10("DADOS.TXT", &n);

  int valor = G_readint("Digite o valor para ser encontrado no array: ");
  int posicao = G_readint("Digite a posicao para comecar a procura do valor: ");

  count = exercicio10_1(array, n, valor, posicao);

  printf("O valor %d foi encontrado %d vezes no array.\n", valor, count);
}

int *extra11 (int n, int *quantidade)
{
  int x = 0;
  int y = 0;
  int count = 0;
  int *array = NULL;

  for(int i = 1; i <= n; i++)
  {
    if(n % i == 0 && i % 2 != 0)
    {
      count = count + 1;
    }
  }
  // printf("count = %d\n", count);
  array = malloc(count * sizeof(int));
  if(array == NULL)
  {
    printf("ERRO ao alocar memoria para arranjo.\n");
  }
  else
  {
    for(int i = 1; i <= n; i++)
    {
      if(n % i == 0 && i % 2 != 0)
      {
        x = i;
        array[y] = x;
        y++;
      }
    }
  }
  *quantidade = count;

  return (array);
}
void method_11e(void) 
{
  int *array = NULL;
  int y = 0;
  FILE* arquivo = fopen ("DIVISORES.TXT", "wt");
  int n = G_readint("Digite o numero: ");

  array = extra11(n, &y);
  G_printarray(y, array);

  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fprintf(arquivo, "%d\n", y);
    for(int i = 0; i < y; i++)
    {
      fprintf(arquivo, "%d\n", array[i]);
    }
    fclose(arquivo);
    printf("\nDados gravados com sucesso em DIVISORES.TXT.\n");
  }
}

char *extra12 (chars Filename)
{
  // char *string;
  // int tamanho = 0;
  // FILE* arquivo = fopen (Filename, "rt");
  // if(arquivo == NULL)
  // {
  //   G_printERROFILE();
  // }
  // else
  // {
  //   while (!feof(arquivo))
  //   {
  //     fscanf(arquivo, "%s", string);
  //     printf("%s\n", string);
  //     // if(string[0] != 'c' && string[0] != 'C')
  //     // {
  //     //   if(string[tamanho] != 'c' && string[tamanho] != 'C')
  //     //   {
  //     //     return string;
  //     //     printf("%s\n", string);
  //     //   }
  //     // }
  //   }
  // }
}
void method_12e(void) 
{
  // // char *string;
  // // string = extra12("PALAVRAS.TXT");
  // extra12("PALAVRAS.TXT");

  // // printf("%s\n", string);

}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 08");
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
