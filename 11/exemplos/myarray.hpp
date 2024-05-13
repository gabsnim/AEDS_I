#ifndef  _MYARRAY_HPP_ 
#define _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;  // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;   // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;   // para gravar arquivo 
using std::ifstream ;   // para ler       arquivo 
 
 
template < typename T > 
class Array 
{ 
  private:   // area reservada 
    T   optional; 
    int length; 
    T  *data; 
 
  public:   // area aberta 
    Array ( int n, T initial ) 
    { 
     // definir valores iniciais 
        optional = initial; 
        length    = 0; 
        data       = nullptr; 
 
     // reservar area 
        if ( n > 0 ) 
        { 
             length  = n; 
             data     = new T [ length ]; 
        } 
    } // end constructor 
 
    void free ( ) 
    { 
       if ( data != nullptr ) 
       { 
          delete ( data ); 
          data = nullptr; 
       } // end if 
    } // end free ( ) 
 
   void set ( int position, T value ) 
    { 
      if ( 0 <= position && position < length ) 
      { 
         data [ position ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int position ) 
    { 
      T value = optional; 
 
      if ( 0 <= position && position < length ) 
      { 
        value = data [ position ]; 
      } // end if 
 
      return ( value ); 
    } // end get ( ) 
 
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : " 
                    << setw( 9 ) << data[ x ] 
                    << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 
}; 
 
#endif 