/* 
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/ 

// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
#include "Mstring.hpp"
 
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
   MyString string ("00!.0.");
   cout << string.getInt () << endl;
} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
      MyString string ("0000");
      cout << string.getDouble () << endl;
} // end method_02 ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 

} // end method_03 ( ) 
 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 

} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
      MyString string ("abc0sdDAS123");
      cout << string.toUpperCase() << endl;
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
      MyString string ("ABC#@123LmO31masc");
      cout << string.toLowerCase() << endl;
} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
      MyString string ("1010110101010100");
      cout << string.replace('1', '4') << endl;
} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
   MyString string ("HELLO XYZ WORLD");
   cout << string.encrypt() << endl;
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
   MyString string ("KHOOR ABC ZRUOG");
   cout << string.decrypt() << endl;
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
   MyString string ("teste delim!tador");
   cout << string.extra01('!') << endl;
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
        cout << "EXEMPLO1101 - Programa - v0.0\n    " << endl; 
 
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