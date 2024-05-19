/* 
Aluno: Gabriel Xavier Borges
Matricula: 805347
*/ 

// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
#include "array.hpp"
 
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
    int n, a, b = 0;
    cout << "Digite o tamanho do array: " << endl;
    cin >> n;
    cout << "Digite o valor inferior do intervalo: " << endl;
    cin >> a;
    cout << "Digite o valor superior do intervalo: " << endl;
    cin >> b;
    /*
        Array = construtor;
        <int> tipo;
        obj_array = objeto;
    */
    Array <int> obj_array (n, 0);
    obj_array.randomIntGenerate(a, b);
    obj_array.print();
    obj_array.fprint("DADOS.TXT");
    obj_array.free();

} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    int x = obj_array.searchFirstOdd();
    cout << x << endl;
    obj_array.free();
 
} // end method_02 ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    int x = obj_array.searchFirstOdd3x();
    if(x == 0)
    {
        cout << "Nao existe valor impar multiplo de 3 no arquivo." << endl;
    }
    else
    {
        cout << x << endl;
    }
    obj_array.free();
} // end method_03 ( ) 
 
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    int inicio, fim = 0;
    cout << "Digite o valor inferior do intervalo para efetuar a soma: " << endl;
    cin >> inicio;
    cout << "Digite o valor superior do intervalo para efetuar a soma: " << endl;
    cin >> fim;
    int soma = obj_array.addInterval(inicio, fim);
    cout << endl << "soma = " << soma << endl;
    obj_array.free();
} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    int inicio, fim = 0;
    cout << "Digite o valor inferior do intervalo para efetuar a soma: " << endl;
    cin >> inicio;
    cout << "Digite o valor superior do intervalo para efetuar a soma: " << endl;
    cin >> fim;
    double media = obj_array.averageInterval(inicio, fim);
    cout << endl << "media = " << media << endl;
    obj_array.free();
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    bool result = obj_array.allNegatives();
    if(!result)
    {
        cout << "Nem todos valores sao negativos. " << endl;
    }
    else
    {
        cout << "Todos os valores sao negativos. " << endl;
    }
    obj_array.free();
} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    if(obj_array.isCrescent())
    {
        cout << "O arranjo esta ordenado em ordem crescente. " << endl;
    }
    else
    {
        cout << "O arranjo NAO esta em ordem crescente. " << endl;
    }
    obj_array.free();
} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    int valor, inicio, fim = 0;
    cout << "Digite o valor para ser procurado no array: " << endl;
    cin >> valor;
    cout << "Digite o valor inferior para fazer a busca: " << endl;
    cin >> inicio;
    cout << "Digite o valor superior para fazer a busca: " << endl;
    cin >> fim;
    obj_array.print();
    if(obj_array.searchInterval(valor, inicio, fim))
    {
        cout << "o valor " << valor << " foi encontrado dentro do intervalo. " << endl;
    }
    else
    {
        cout << "o valor " << valor << " NAO foi encontrado dentro do intervalo. " << endl;
    }
    obj_array.free();
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    Array <int> new_array (5, 0);
    new_array = obj_array.scalar(5, 0, 3);
    new_array.print();
    obj_array.free();
    new_array.free();
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
    Array <int> obj_array (5, 0);
    obj_array.fread("DADOS.TXT");
    obj_array.print();
    obj_array.sortDown();
    obj_array.print();
    obj_array.free();
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
        cout << endl << "Estudo dirigido 11 \n" << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes                 " << endl; 
        cout << " 0 - parar             " << endl; 
        cout << " 1 - exercicio01       " << endl; 
        cout << " 2 - exercicio02       " << endl; 
        cout << " 3 - exercicio03       " << endl; 
        cout << " 4 - exercicio04       " << endl; 
        cout << " 5 - exercicio05       " << endl; 
        cout << " 6 - exercicio06       " << endl; 
        cout << " 7 - exercicio07       " << endl; 
        cout << " 8 - exercicio08       " << endl; 
        cout << " 9 - exercicio09       " << endl; 
        cout << "10 - exercicio10       " << endl; 
 
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