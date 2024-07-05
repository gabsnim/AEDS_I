/* 
Aluno: Gabriel Xavier Borges
Matricula: 805347
atividade finalizada
*/ 

// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
#include "matrix.hpp"
 
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
    int rows, columns = 0;
    cout << "Digite o numero de linhas da matriz: " << endl;
    cin >> rows;
    cout << "Digite o numero de colunas da matriz: " << endl;
    cin >> columns;
    Matrix <int> obj_matrix (rows, columns, 0);

    obj_matrix.randomMatrixGenerator(10,90);
    obj_matrix.print();
    obj_matrix.fprint("DADOS.TXT");

} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
   Matrix <int> obj_matrix (2, 2, 0);
   obj_matrix.fread("DADOS.TXT");
   Matrix <int> new_matrix (2, 2, 0);
   new_matrix = obj_matrix.scalar(5);
   new_matrix.print();
   obj_matrix.print();
} // end method_02 ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
   Matrix <int> obj_matrix (2,2, 0);
   obj_matrix.fread("DADOS.TXT");
   if(obj_matrix.identidade())
   {
      cout << "A matriz e uma matriz identidade" << endl;
      obj_matrix.print();
   }
   else
   {
      cout << "A matriz NAO e uma matriz identidade" << endl;
      obj_matrix.print();
   }
} // end method_03 ( ) 
 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   Matrix <int> matriz2 (2,2, 0);
   matriz2.fread("DADOS2.TXT");

   if(matriz1 == matriz2)
   {
      cout << "As matrizes sao iguais. " << endl;
   }
   else
   {
      cout << "As matrizes NAO sao iguais. " << endl;
   }
} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   Matrix <int> matriz2 (2,2, 0);
   matriz2.fread("DADOS2.TXT");
   matriz1.print();
   cout << "+" << endl;
   matriz2.print();
   matriz1 = matriz1.add(matriz2);
   cout << "Soma: " << endl;
   matriz1.print();
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   matriz1 = matriz1.addRows(0,1,(-1));
   matriz1.print();
} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   matriz1 = matriz1.subtractRows(0,1,(2));
   matriz1.print();
} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   int value, result = 0;
   cout << "Digite um numero para saber em qual linha ele esta: " << endl;
   cin >> value;
   result = matriz1.searchRows(value);

   if(result == (-1))
   {
      cout << "O numero nao esta na matriz." << endl; 
   }
   else
   {
      cout << "O numero esta na linha " << result << " da matriz." << endl;
   }
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
   Matrix <int> matriz1 (2,2, 0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   int value, result = 0;
   cout << "Digite um numero para saber em qual coluna ele esta: " << endl;
   cin >> value;
   result = matriz1.searchColumns(value);

   if(result == (-1))
   {
      cout << "O numero nao esta na matriz." << endl; 
   }
   else
   {
      cout << "O numero esta na coluna " << result << " da matriz." << endl;
   }
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
   Matrix <int> matriz1  (2,2,0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   matriz1 = matriz1.transpose();
   matriz1.print();

} // end method_10 ( ) 

/** 
   Method_11. 
 */ 
void method_11 ( ) 
{ 
   Matrix <int> matriz1  (2,2,0);
   matriz1.fread("DADOS.TXT");
   matriz1.print();
   // matriz1 = matriz1.extra02(4,4);s
   // matriz1.print();
   if(matriz1.extra01() == true)
   {
      cout << "A matriz apresenta a caracteristica que o exercicio pede. " << endl;
   }
   else
   {
      cout << "A matriz NAO apresenta a caracteristica que o exercicio pede. " << endl;
   }
} // end method_11 ( ) 

/** 
   Method_12. 
 */ 
void method_12 ( ) 
{ 
   Matrix <int> matriz1  (2,2,0);
   matriz1 = matriz1.extra02(4,4);
   matriz1.print();
} // end method_12 ( ) 

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
        cout << endl << "Estudo dirigido 12\n    " << endl; 
        cout << "Gabriel Xavier Borges\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes      " << endl; 
        cout << " 0 - parar  " << endl; 
        cout << " 1 - exercicio 01       " << endl; 
        cout << " 2 - exercicio 02       " << endl; 
        cout << " 3 - exercicio 03       " << endl; 
        cout << " 4 - exercicio 04       " << endl; 
        cout << " 5 - exercicio 05       " << endl; 
        cout << " 6 - exercicio 06       " << endl; 
        cout << " 7 - exercicio 07       " << endl; 
        cout << " 8 - exercicio 08       " << endl; 
        cout << " 9 - exercicio 09       " << endl; 
        cout << "10 - exercicio 10       " << endl; 
        cout << "11 - extra 01       " << endl; 
        cout << "12 - extra 02       " << endl; 
 
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
          case 11: method_11 ( );   break;
          case 12: method_12 ( );   break;
          
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( )