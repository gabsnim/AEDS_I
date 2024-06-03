/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
#include "Contato.hpp"

// ----------------------------------------------- definicoes globais

// ----------------------------------------------- classes / pacotes

using namespace std;

// ----------------------------------------------- metodos

/**
   Method_00 - nao faz nada.
 */
void method_00()
{
   // nao faz nada
} // end method_00 ( )

/**
   Method_01.
 */
void method_01()
{
   Contato pessoa1;
   pessoa1.readName();
   pessoa1.print();
} // end method_01 ( )

/**
   Method_02.
 */
void method_02()
{
   Contato pessoa1;
   pessoa1.readName();
   pessoa1.readPhone();
   pessoa1.print();
} // end method_02 ( )

/**
   Method_03.
 */
void method_03()
{
   Contato pessoa1;
   pessoa1.readName();
   pessoa1.readPhone();
   pessoa1.print();
} // end method_03 ( )

/**
   Method_04.
 */
void method_04()
{
   Contato pessoa1;
   pessoa1.readFromFile("Pessoa1.txt");
   pessoa1.print();
} // end method_04 ( )

/**
   Method_05.
 */
void method_05()
{
   Contato pessoa1;
   pessoa1.readFromFile("Pessoa1.txt");
   pessoa1.writeToFile("Pessoa2.txt");
   pessoa1.print();
} // end method_05 ( )

/**
   Method_06.
 */
void method_06()
{
   Contato pessoa1;
   pessoa1.readName();
   pessoa1.readPhone();
   pessoa1.readPhone2();
   pessoa1.print();
} // end method_06 ( )

/**
   Method_07.
 */
void method_07()
{
   Contato pessoa1;
   pessoa1.readName();
   pessoa1.readPhone();
   pessoa1.readPhone2();
   cout << "Numero de telefones = " << pessoa1.getNfone() << std::endl;
   pessoa1.print();
} // end method_07 ( )

/**
   Method_08.
 */
void method_08()
{
   Contato pessoa1("gabriel", 1);

   pessoa1.read();

   pessoa1.newPrint();
} // end method_08 ( )

/**
   Method_09.
 */
void method_09()
{
   Contato pessoa1;

   pessoa1.read();

   pessoa1.newPrint();

   pessoa1.setPhone2("987654321");

   pessoa1.newPrint();
} // end method_09 ( )

/**
   Method_10.
 */
void method_10()
{
   Contato pessoa1;
   pessoa1.read();
   pessoa1.newPrint();
   pessoa1.removePhone2();
   pessoa1.newPrint();
} // end method_10 ( )

/**
   Method_11.
 */
void method_11()
{
   Contato pessoa1;
   pessoa1.read();
   pessoa1.newPrint();
} // end method_11 ( )

/**
   Method_12.
 */
void method_12()
{
   Contato pessoa1;
   pessoa1.read();
   pessoa1.newPrint();
} // end method_12 ( )

// ----------------------------------------------- acao principal

/*
  Funcao principal.
  @return codigo de encerramento
*/
int main(int argc, char **argv)
{
   // definir dado
   int x = 0; // definir variavel com valor inicial

   // repetir até desejar parar
   do
   {
      // identificar
      // cout << "EXEMPLO1101 - Programa - v0.0\n    " << endl;

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
      cout << "11 -        " << endl;
      cout << "12 -        " << endl;

      // ler do teclado
      cout << endl
           << "Entrar com uma opcao: ";
      cin >> x;

      // escolher acao
      switch (x)
      {
      case 0:
         method_00();
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
         method_11();
         break;
      case 12:
         method_12();
         break;
      default:
         cout << endl
              << "ERRO: Valor invalido." << endl;
      } // end switch
   } while (x != 0);

   // encerrar
   pause("Apertar ENTER para terminar");
   return (0);
} // end main ( )