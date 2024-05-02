/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

#include "gxb.h"
#include "io.h"


void method_01a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", y ); 
     // passar ao proximo 
        y = y + 1; 
    } // end if 
} // end method_01a( ) 
void method_01(void) 
{
   // identificar 
    IO_id ( " Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_01a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}

void method_02a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 2; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo par 
        z = z + 2; 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
} // end method_02a( ) 

void method_02(void)
{
// identificar 
    IO_id ( "Method_02 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_02a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
}

void method_03a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 0; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // vincular o valor a ser mostrado ao controle 
        z = 2 * y; 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
} // end method_03a( )
void method_03(void)
{
     // identificar 
    IO_id ( " Method_03 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_03a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
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
