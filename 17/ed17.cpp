/* 
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/ 

// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
#include "list.hpp"
 
// ----------------------------------------------- definicoes globais 
 
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 
 
// ----------------------------------------------- classes / pacotes 
 
 
using namespace std; 
 
// ----------------------------------------------- metodos 
 
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 
 
/** 
   Method_01.
 */ 
void method_01 ( ) 
{ 
   intCell *LIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      LIFO = LIFO->intStack_push(LIFO, x);
   }
   LIFO->print();

   std::cout << "Digite um elemento para ser inserido no final: " << std::endl;
   std::cin >> x;
   LIFO = LIFO->intStack_push(LIFO, x);
   LIFO->print();
   
   
} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
   intCell *LIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      LIFO = LIFO->intStack_push(LIFO, x);
   }
   LIFO->print();

   LIFO = LIFO->intStack_pop(LIFO);

   std::cout << "Elemento retirado do final." << std::endl;
   
   LIFO->print();
} // end method_02 ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
   intCell *LIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      LIFO = LIFO->intStack_push(LIFO, x);
   }
   LIFO->print();

   LIFO = LIFO->intStack_dup(LIFO);

   std::cout << "Elemento do final foi duplicado." << std::endl;
   
   LIFO->print();
} // end method_03 ( ) 
 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
   intCell *LIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      LIFO = LIFO->intStack_push(LIFO, x);
   }
   LIFO->print();

   LIFO = LIFO->intStack_swap(LIFO);

   std::cout << "o ultimo elemento foi trocado com o penultimo." << std::endl;
   
   LIFO->print();
} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
   intCell *LIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      LIFO = LIFO->intStack_push(LIFO, x);
   }
   LIFO->print();

   LIFO = LIFO->intStack_invert(LIFO);

   std::cout << "os elementos foram trocados de ordem." << std::endl;
   
   LIFO->print();
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
   intCell *FIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      FIFO = FIFO->intQueue_push(FIFO, x);
   }
   FIFO->print();

   std::cout << "Digite um valor para ser inserido no final" << std::endl;

} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
   intCell *FIFO = new intCell();
   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      FIFO = FIFO->intStack_push(FIFO, x);
   }
   FIFO->print();

   FIFO = FIFO->intQueue_pop(FIFO);

   std::cout << "Elemento retirado do comeco." << std::endl;
   
   FIFO->print();
} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
   // intCell *FILA1 = new intCell();
   // intCell *FILA2 = new intCell();

   // int n = 0, x = 0;

   // std::cout << "Digite quantos elementos voce deseja inserir na FILA1: " << std::endl;
   // std::cin >> n;

   // for(int i = 0; i < n; i++)
   // {
   //    std::cout << "Digite o elemento " << i+1 << std::endl;
   //    std::cin >> x;
   //    FILA1 = FILA1->intStack_push(FILA1, x);
   // }

   // std::cout << "Digite quantos elementos voce deseja inserir na FILA2: " << std::endl;
   // std::cin >> n;

   // for(int i = 0; i < n; i++)
   // {
   //    std::cout << "Digite o elemento " << i+1 << std::endl;
   //    std::cin >> x;
   //    FILA2 = FILA2->intStack_push(FILA2, x);
   // }

   // int y = FILA1->intQueue_compare(FILA1, FILA2);

   // std::cout << "Diferenca entre as duas filas = " << y << std::endl;

   // FILA1->print();
   // FILA2->print();
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
   intCell *FILA1 = new intCell();
   intCell *FILA2 = new intCell();

   int n = 0, x = 0;

   std::cout << "Digite quantos elementos voce deseja inserir na FILA1: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      FILA1 = FILA1->intStack_push(FILA1, x);
   }

   std::cout << "Digite quantos elementos voce deseja inserir na FILA2: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      FILA2 = FILA2->intStack_push(FILA2, x);
   }

   FILA1 = FILA1->intQueue_join(FILA1, FILA2);

   std::cout << "Duas filas juntas:" << std::endl;

   FILA1->print();
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
   intCell *FILA = new intCell();

   int n = 0, x = 0, y = 0;
   int z = 0;

   std::cout << "Digite quantos elementos voce deseja inserir na FILA: " << std::endl;
   std::cin >> n;

   for(int i = 0; i < n; i++)
   {
      std::cout << "Digite o elemento " << i+1 << std::endl;
      std::cin >> x;
      FILA = FILA->intStack_push(FILA, x);
   }

   FILA->print();

   std::cout << "Digite o elemento que voce deseja procurar na FILA: " << std::endl;
   std::cin >> y;

   z = FILA->intQueue_search(FILA, y);

   if(z == 0)
   {
      std::cout << "O elemento nao foi encontrado na FILA: " << std::endl;
      FILA->print();
   }
   else
   {
      std::cout << "O elemento foi encontrado na FILA: " << std::endl;
      FILA->print();
   }
} // end method_10 ( ) 
 
// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;   // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "Estudo dirigido 17 - Gabriel Xavier\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes      " << endl; 
        cout << " 0 - parar  " << endl; 
        cout << " 1 -        " << endl; 
        cout << " 2 -        " << endl; 
        cout << " 3 -        " << endl; 
        cout << " 4 -        " << endl; 
        cout << " 5 -        " << endl; 
        cout << " 6 -        " << endl; 
        cout << " 7 -        " << endl; 
        cout << " 8 -        " << endl; 
        cout << " 9 -        " << endl; 
        cout << "10 -        " << endl; 
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0:   method_00 ( );   break; 
          case 1:   method_01 ( );   break; 
          case 2:   method_02 ( );   break; 
          case 3:   method_03 ( );   break; 
          case 4:   method_04 ( );   break; 
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
          case 10: method_10 ( );   break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( )