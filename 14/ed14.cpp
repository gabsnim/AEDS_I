/*
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
#include "Mstring.hpp"

// ----------------------------------------------- definicoes globais

void pause(std::string text)
{
   std::string dummy;
   std::cin.clear();
   std::cout << std::endl
             << text;
   std::cin.ignore();
   std::getline(std::cin, dummy);
   std::cout << std::endl
             << std::endl;
} // end pause ( )

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

   MyString string("1234");
   cout << string.getInt() << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_01 ( )

/**
   Method_02.
 */
void method_02()
{
   MyString string("123.13");
   cout << string.getDouble() << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_02 ( )

/**
   Method_03.
 */
void method_03()
{
   MyString string1("T");
   MyString string2("F");
   MyString string3("FALSE");
   MyString string4("TRUE");
   cout << string1.getBoolean() << endl;
   cout << string2.getBoolean() << endl;
   cout << string3.getBoolean() << endl;
   cout << string4.getBoolean() << endl;

   if (string1.hasErro() || string2.hasErro() || string3.hasErro() || string4.hasErro())
      cout << endl
           << string1.getErroMsg() << endl;
} // end method_03 ( )

/**
   Method_04.
 */
void method_04()
{
   MyString string("gabriel");
   cout << string.contains("borges") << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_04 ( )

/**
   Method_05.
 */
void method_05()
{
   MyString string("abc0sdDAS123");
   cout << string.toUpperCase() << endl;

   if (string.hasErro())
   {
      cout << endl
           << string.getErroMsg() << endl;
   }
} // end method_05 ( )

/**
   Method_06.
 */
void method_06()
{
   MyString string("ABC#@123LmO31masc");
   cout << string.toLowerCase() << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_06 ( )

/**
   Method_07.
 */
void method_07()
{
   MyString string("1010110101010100");
   cout << string.replace('1', '4') << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_07 ( )

/**
   Method_08.
 */
void method_08()
{
   MyString string("HELLO XYZ WORLD");
   cout << string.encrypt() << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_08 ( )

/**
   Method_09.
 */
void method_09()
{
   MyString string("KHOOR ABC ZRUOG");
   cout << string.decrypt() << endl;

   if (string.hasErro())
      cout << endl
           << string.getErroMsg() << endl;
} // end method_09 ( )

/**
   Method_10.
 */
void method_10()
{

} // end method_10 ( )

/**
   Method_11.
 */
void method_11()
{
   MyString string("teste.delimitador.com.ponto");
   cout << string.extra01('.') << endl;
} // end method_11 ( )

/**
   Method_12.
 */
void method_12()
{
   MyString string("theldo");
   cout << string.extra02() << endl;
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
      cout << "\nEstudo dirigido 14\n    " << endl;

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