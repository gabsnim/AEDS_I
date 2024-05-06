/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
#include "io.h"


void exercicio01 (int rows, int columns, double matrix[][columns])  //printar matriz real
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      printf("%.2lf ", matrix[i][j]);
    }
    printf("\n");
  }
}
void method_01(void) 
{
  int rows = 0, columns = 0;
  double x = 0.0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  
  double matrix [rows][columns];

  // for(int i = 0; i < rows; i++)    
  // {
  //   for(int j = 0; j < columns; j++)
  //   {
  //     do
  //     {
  //       printf("linha %d coluna %d = ", i, j);
  //       x = G_readdouble("");        
  //     } while (x > 0);
  //     matrix[i][j] = x;
  //   }
  // }
  G_readdoubleNegativeMatrix(rows, columns, matrix);
  exercicio01(rows, columns, matrix);
}

void exercicio02 (chars Filename, int rows, int columns, double matrix[][columns])  //gravar a matriz em arquivo
{
  FILE* arquivo = fopen (Filename, "wt");
  // exercicio01(rows, columns, matrix);
  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fprintf(arquivo, "%d\n", rows);
    fprintf(arquivo, "%d\n", columns);
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        fprintf(arquivo, "%.2lf ", matrix[i][j]);
      }
      fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Dados gravados com sucesso em %s.", Filename);
  }
}

void exercicio02_1 (chars Filename) //ler matriz do arquivo e mostrar na tela
{
  int rows = 0;
  int columns = 0;
  int x = 0;
  int y = 0;
  double z = 0.0;

  FILE* arquivo = fopen (Filename, "rt");
  if(arquivo == NULL)
  {
    G_printERROFILE();
  }
  else
  {
    fscanf(arquivo, "%d", &rows);
    fscanf(arquivo, "%d", &columns);
    printf("rows = %d\ncolumns = %d\n", rows, columns);
    double matrix[rows][columns];

    x = 0;
    while(!feof(arquivo) && x < rows)
    {
      y = 0;
      while(!feof(arquivo) && y < columns)
      { 
        fscanf(arquivo, "%lf", &z);
        // printf("z = %lf\n", z);
        matrix[x][y] = z;
        y++;
      }
      x++;
    }
    fclose(arquivo);
    G_printdoubleMatrix(rows, columns, matrix);
  }
} 
void method_02(void)
{
  int rows = 0, columns = 0;
  
  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);

  double matrix[rows][columns];

  G_readdoubleNegativeMatrix(rows, columns, matrix);

  exercicio02("MATRIX_01.TXT", rows, columns, matrix);

  exercicio02_1("MATRIX_01.TXT");
}

void exercicio03 (int rows, int columns, double matrix[][columns]) //mostrar diagonal principal
{
  double z = 0.0;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < rows; j++)
    {
      if(i == j)
      {
        z = matrix[i][j];
        printf("%.2lf ", z);
      }
    }
  }
}
void method_03(void)
{
  int rows = 0, columns = 0;
  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);

  if(rows == columns) //matriz quadrada
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio03(rows, columns, matrix);
  }
  else
  {
    printf("A matriz nao e quadrada.\n");
  }
  
}

void exercicio04 (int rows, int columns, double matrix[][columns]) //mostrar diagonal secundaria
{
  double z = 0.0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      // printf("i = %d j = %d\n", i, j);
      if((j + i) == (rows - 1))
      {
        printf("%.2lf ", matrix[i][j]);
      }
    }
  }
}
void method_04(void)
{
  int rows = 0, columns = 0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);

  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio04(rows, columns, matrix);
  }
  
}

void exercicio05 (int rows, int columns, double matrix[][columns]) //mostrar diagonal principal e triangulo inferior
{
  double z = 0.0;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(i > j || i == j)  //tirar i == j para mostrar apenas triangulo inferior;
      {
        z = matrix[i][j];
        printf("%.2lf ", z);
      }
    }
  }
}
void method_05(void)
{
  int rows = 0, columns = 0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio05(rows, columns, matrix);
  }
}

void exercicio06 (int rows, int columns, double matrix[][columns])  //mostrar diagonal principal e triangulo superior
{
  double z = 0.0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(j > i || i == j)
      {
        z = matrix[i][j];
        printf("%.2lf ", z);
      }
    }
  }
}
void method_06(void) 
{
  int rows = 0, columns = 0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio06(rows, columns, matrix);
  }
}

void exercicio07 (int rows, int columns, double matrix[][columns]) //mostrar diagonal secundaria e triangulo inferior secundario
{
  double z = 0.0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if((j + i) == (rows - 1) || (i+j) > (rows - 1))
      {
        z = matrix[i][j];
        printf("%.2lf ", z);
      }
      // else if((i+j) > (rows - 1)) 
      // {
      //   z = matrix[i][j];
      //   printf("%.2lf ", z);
      // }
    }
  }
}
void method_07(void)
{
  int rows = 0, columns = 0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio07(rows, columns, matrix);
  }
}

void exercicio08 (int rows, int columns, double matrix[][columns]) //mostrar diagonal secundaria e triangulo superior secundario
{
  double z = 0.0;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if((i + j) < (rows - 1) || (i + j) == (rows - 1))
      {
        z = matrix[i][j];
        printf("%.2lf ", z);
      }
    }
  }
}
void method_08(void)
{
  int rows = 0, columns = 0;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    exercicio08(rows, columns, matrix);
  }
}

bool exercicio09 (int rows, int columns, double matrix[][columns])
{
  int count = 0;
  double z = 0.0;
  bool result = true;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(i > j) //triangulo inferior 
      {
        z = matrix[i][j];
        if(z != 0)
        {
          result = false;
        }
      }
    }
  }
  return result;
}
void method_09(void) 
{
  int rows = 0, columns = 0;
  bool result = false;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    result = exercicio09(rows, columns, matrix);

    if(result == true)
    {
      printf("Os elementos abaixo da diagonal principal sao todos zeros.");
    }
    else
    {
      printf("Os elementos abaixo da diagonal principal NAO sao todos zeros.");
    }
  }
}

bool exercicio10 (int rows, int columns, double matrix[][columns])
{
  int count = 0;
  double z = 0.0;
  bool result = true;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(j > i) //triangulo superior
      {
        z = matrix[i][j];
        if(z != 0)
        {
          result = false;
        }
      }
    }
  }
  return result;
}
void method_10(void) 
{
  int rows = 0, columns = 0;
  bool result = false;

  do
  {
    rows = G_readint("Digite o numero de linhas da matriz: ");
    columns = G_readint("Digite o numero de colunas da matriz: ");
  } while (rows <= 0 && columns <= 0);
  if(rows != columns)
  {
    printf("A matriz nao e quadrada.\n");
  }
  else
  {
    double matrix[rows][columns];
    G_readdoubleNegativeMatrix(rows, columns, matrix);
    result = exercicio10(rows, columns, matrix);

    if(result == true)
    {
      printf("Os elementos acima da diagonal principal sao todos zeros.");
    }
    else
    {
      printf("Os elementos acima da diagonal principal NAO sao todos zeros.");
    }
  }
}

void extra01(int rows, int columns, int matrix[][columns])
{
  int count = 1;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      matrix[i][j] = count;
      count++;
    }
  }
}
void method_11e(void) 
{
  int rows = 0, columns = 0;
  do {
     rows = G_readint("Digite o numero de linhas da matriz: ");
     columns = G_readint("Digite o numero de colunas da matriz: ");
  } while(rows <= 0 && columns <= 0);

  if(rows != columns)
  {
    printf("A matriz nao e quadrada.");
  }   
  else
  {
    int matrix[rows][columns];
    extra01(rows, columns, matrix);
    G_printMatrix(rows, columns, matrix);

    FILE* arquivo = fopen ("EXTRA01.TXT", "wt");

    if(arquivo == NULL)
    {
      G_printERROFILE();
    }
    else
    {
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < columns; j++)
        {
          fprintf(arquivo, "%d ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
      }
      fclose(arquivo);
      printf("Dados gravados com sucesso em EXTRA01.TXT");
    }
  }
}

void extra02 (int rows, int columns, int matrix[][columns])
{
  int count = rows*columns;

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      matrix[i][j] = count;
      count--;
    }
  }
}
void method_12e(void) 
{
  int rows = 0, columns = 0;
  do {
     rows = G_readint("Digite o numero de linhas da matriz: ");
     columns = G_readint("Digite o numero de colunas da matriz: ");
  } while(rows <= 0 && columns <= 0);

  if(rows != columns)
  {
    printf("A matriz nao e quadrada.");
  }   
  else
  {
    int matrix[rows][columns];
    extra02(rows, columns, matrix);
    G_printMatrix(rows, columns, matrix);

    FILE* arquivo = fopen ("EXTRA02.TXT", "wt");

    if(arquivo == NULL)
    {
      G_printERROFILE();
    }
    else
    {
      for(int i = 0; i < rows; i++)
      {
        for(int j = 0; j < columns; j++)
        {
          fprintf(arquivo, "%d ", matrix[i][j]);
        }
        fprintf(arquivo, "\n");
      }
      fclose(arquivo);
      printf("Dados gravados com sucesso em EXTRA02.TXT");
    }
  }
}

int main(int argc, char *argv[]) {

  int opcao = 0;

  printf("%s\n", "Estudo dirigido 09");
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
