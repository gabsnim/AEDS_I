/* 
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/ 

// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
#include "cel.hpp"
 
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
    intCell* array = nullptr;
    std::cout << "Push back: " << std::endl;
    array = array->array_push_back(array, 10);
    array = array->array_push_back(array, 20);
    array = array->array_push_back(array, 30);
    array->print();
    std::cout << std::endl;
    std::cout << "tamanho = " << array->getTam(array) << std::endl;
} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
    intCell* array = nullptr;
    std::cout << "Pop back: " << std::endl;
    for(int i = 1; i <= 5; i++)
    {
        array = array->array_push_back(array, i);
    }
        std::cout << "tamanho antes = " << array->getTam(array) << std::endl;
    array->print();
    std::cout << std::endl;
    array = array->array_pop_back(array);
        std::cout << "tamanho depois = " << array->getTam(array) << std::endl;
    array->print();
} // end method_02 ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
    intCell* array = nullptr;
    std::cout << "Push front: " << std::endl;
    array = array->array_push_back(array, 10);
    array = array->array_push_back(array, 20);
    array = array->array_push_back(array, 30);
    array->print();
    std::cout << "tamanho antes = " << array->getTam(array) << std::endl;
    array = array->array_push_front(array, 100);
    array->print();
       std::cout << "tamanho depois = " << array->getTam(array) << std::endl;
} // end method_03 ( ) 
 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
    intCell* array = nullptr;
    std::cout << "Pop front: " << std::endl;
    array = array->array_push_back(array, 10);
    array = array->array_push_back(array, 20);
    array = array->array_push_back(array, 30);
    array->print();
    std::cout << "tamanho antes = " << array->getTam(array) << std::endl;
    array = array->array_pop_front(array);
    array->print();
    std::cout << "Tamanho depois = " << array->getTam(array) << std::endl;
} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
    intCell* array = nullptr;
    std::cout << "Push mid: " << std::endl;
    array = array->array_push_back(array, 10);
    array = array->array_push_back(array, 20);
    array = array->array_push_back(array, 30);
    array = array->array_push_back(array, 40);
    array->print();
    std::cout << "tamanho antes = " << array->getTam(array) << std::endl;
    array = array->array_push_mid(array, 25);
    array->print();
        std::cout << "tamanho depois = " << array->getTam(array) << std::endl;
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
    intCell* array = nullptr;
    std::cout << "Pop mid: " << std::endl;
    array = array->array_push_back(array, 10);
    array = array->array_push_back(array, 20);
    array = array->array_push_back(array, 30);
    array->print();
        std::cout << "tamanho antes = " << array->getTam(array) << std::endl;
    array = array->array_pop_mid(array);
    array->print();
        std::cout << "tamanho depois = " << array->getTam(array) << std::endl;
} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
    intCell* array1 = nullptr;
    intCell* array2 = nullptr;
    std::cout << "Array comper: " << std::endl;
    for(int i = 1; i <= 5; i++)
    {
        array1 = array1->array_push_back(array1, i);
    }
    for(int i = 1; i <= 5; i++)
    {
        array2 = array2->array_push_back(array2, i);
    }
    array2 = array2->array_push_mid(array2, 10);
    std::cout<< array1->intArray_cmp(array1,array2);

} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
    intCell* array1 = nullptr;
    intCell* array2 = nullptr;
    std::cout << "Array add: " << std::endl;
    for(int i = 1; i <= 5; i++)
    {
        array1 = array1->array_push_back(array1, i);
    }
    for(int i = 6; i <= 10; i++)
    {
        array2 = array2->array_push_back(array2, i);
    }

    array1 = array1->intArray_cat(array1, array2);
    array1->print();
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
    intCell* array1 = nullptr;
    for(int i = 1; i <= 5; i++)
    {
        array1 = array1->array_push_back(array1, i);
    }
    array1->print();
    array1 = array1->intArray_seek(array1, 2);
    array1->print();
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 

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
        cout << "\nestudo dirigido 16 - Gabriel Xavier\n    " << endl; 
        // std::cout << "  ________    _____ __________________   \n"
        // << " /  _____/   /  _  \\\\______   \\______ \\  \n"
        // << "/   \\  ___  /  /_\\  \\|    |  _/|    |  \\ \n"
        // << "\\    \\_\\  \\/    |    \\    |   \\|    `   \\\n"
        // << " \\______  /\\____|__  /______  /_______  /\n"
        // << "        \\/         \\/       \\/        \\/ \n";
 
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