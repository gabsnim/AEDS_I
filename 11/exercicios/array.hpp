#ifndef  _MYARRAY_HPP_ 
#define _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
#include <cstring>
#include <cstdlib>

using std::cin  ;  // para entrada 
using std::cout;  // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;   // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;    // para gravar arquivo 
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
        optional  = initial; 
        length    = 0; 
        data      = nullptr; 
 
     // reservar area 
        if ( n > 0 ) 
        { 
             length  = n; 
             data     = new T [ length ];   // data = malloc(n * sizeof(int));
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
 
   void set ( int position, T value ) //
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
       for ( int i = 0; i < length; i=i+1 ) 
       { 
            cout << i << " = " << data[i] << endl;
       } // end for 
       cout << endl; 
    } // end print ( ) 

   void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : "; 
           cin   >> data[ x ]; 
       } // end for 
       cout << endl; 
    } // end read ( )

     void fprint ( string fileName ) 
    { 
       ofstream file;  // output file 
 
       file.open ( fileName ); 
       file << length << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           file << data[ x ] << endl; 
       } // end for 
       cout << "Dados gravados com sucesso em " << fileName << "." <<  endl;
       file.close ( ); 
    } // end fprint ( )

       void fread ( string fileName ) 
    { 
       ifstream file; // input file 
       int n = 0; 
       file.open ( fileName ); 
       file >> n; 
       if ( n <= 0 ) 
       { 
          cout << "\nERROR: Invalid length.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           length  = n; 
        // reservar area 
           data    = new T [ n ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
              file >> data[ x ]; 
           } // end for 
       } // end if 
       file.close ( ); 
    } // end fread ( )

      Array ( )    // construtor padrao 
    { 
     // definir valores iniciais 
        length  = 0; 
     // reservar area 
        data     = nullptr; 
    } // end constructor 
 
     // contrutor baseado em copia 
    Array ( int length, int other [ ] ) 
    { 
       if ( length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           this->length = length; 
        // reservar area 
           data   = new T [ this->length ]; 
        // ler dados 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( )

       Array ( const Array& other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           length = other.length; 
        // reservar area 
           data    = new T [ other.length ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( )

        Array& operator= ( const Array <T> other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->length = other.length; 
           this->data    = new T [ other.length ]; 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( )

      bool operator== ( const Array <T> other ) 
    { 
       bool result = false; 
       int  x           = 0; 
 
       if ( other.length == 0 || length != other.length ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          x = 0;  
          result = true; 
          while ( x < this->length && result ) 
          { 
              result = result &&  (data [ x ] == other.data [ x ] ); 
              x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end operator== ( ) 

        Array& operator+ ( const Array <T> other ) 
    { 
       static Array <T> result ( other ); 
 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          for ( int x = 0; x < this->length; x=x+1 ) 
          { 
              result.data [ x ] = result.data [ x ] + this->data [ x ]; 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator+ ( )

      const int getLength ( ) 
    { 
       return ( length ); 
    } // end getLength ( ) 
 
    T& operator[]( const int position ) 
    { 
       static T value = optional; 
 
       if ( position < 0 || length <= position ) 
       { 
          cout << endl << "\nERROR: Invalid position.\n" << endl; 
       } 
       else 
       { 
         value = data [ position ]; 
       } // end if 
       return ( value ); 
    } // end operator [ ]

    /*
        Funcao para gerar um array com inteiros aleatorios
    */
    Array randomIntGenerate (int inferior, int superior)
    {
        int i = 0;
        while (i < length)
        {
            int x = rand() % 100;
            if(x >= inferior && x <= superior)
            {
                data[i] = x;
                i++;
            }
        }
        return *this;
    }

    /*
        Funcao para retornar o maior par;
    */
    int searchFirstOdd()
    {
        T maior = 0;
        for(int i = 0; i < length; i++)
        {
            if(data[i] % 2 == 0)
            {
                if(data[i] > maior)
                {
                    maior = data[i];
                }
            }
        }
        return maior;
    }
    /*
        Funcao para procurar o menor valor impar multiplo de 3
    */
    int searchFirstOdd3x()
    {
        bool teste = false;
        int i = 0;
        int menor = 0;
        while(i < length && teste == false)
        {
            if(data[i] % 2 != 0 && data[i] % 3 == 0)
            {
                teste = true;
                menor = data[i];
            }
            i++;
        }
        // cout << i << endl;
        // cout << menor << endl;
        for(int x = i+1; x < length; x++)
        {
            if(data[x] % 2 != 0 && data[x] % 3 == 0)
            {
                if(data[x] < menor)
                {
                    menor = data[x];
                }
            }
        }
        return menor;
    }

    /*
        Funcao para somar valores de um arranjo num determinado intervalo
    */
    T addInterval (int inicio, int fim)
    {
        T soma = optional;
        for(int i = 0; i < length; i++)
        {
            if(i >= inicio && i <= fim)
            {
                soma+= data[i];
            }
        }
        return soma;
    }

    /*
        Funcao para calcular a media entre valores de um arranjo
    */
    double averageInterval (int inicio, int fim)
    {
        double media = 0.0;
        int quantidade = 0;
        int soma = 0;

        if ( inicio >= 0 && fim <= length && inicio <= fim )
        {
            quantidade = fim - inicio + 1;
            soma  = addInterval( inicio, fim );
            media =  static_cast<double>(soma) / quantidade; 
        }

        return ( media );
    }

    /*
        Funcao para verificar se um arranjo e composto apenas de valores negativos
    */
    bool allNegatives ()
    {
        bool result = true;
        int i = 0;
        while (i < length)
        {
            if(data[i] > 0)
            {
                result = false;
            }
            i++;
        }
        return result;
    }

    /*
        Funcao para verificar se um arranjo e crescente
    */
    bool isCrescent ()
    {
        bool result = true;
        for(int i = 1; i < length; i++)
        {
            if(data[i-1] > data[i])
            {
                result = false;
            }
        }
        return result;
    }

    /*
        Funcao para procurar um valor no arranjo
    */
    bool searchInterval (T procurado, int inicio, int fim)
    {
        bool result = false;
        int i = 0;
        while (i < length && !result)
        {
            if(data[i] == procurado && i >= i && i <= fim)
            {
                result = true;
            }
            i++;
        }
        return result;
    }

    /*
        Funcao para multiplicar valores em um arranjo por uma constante
    */
    Array scalar (T constante, int inicio, int fim)
    {
        Array new_array(*this);

        for(int i = inicio; i <= fim; i++)
        {
            new_array.data[i] = new_array.data[i] * constante;
        }
        return new_array;
    } 

    /*
        Funcao para ordenar um arranjo em ordem decrescente
    */
    Array sortDown ()
    {
        int test = 0;
        for(int i = 0; i < length; i++)
        {
            for(int j = i + 1; j < length; j++)
            {
                if(data[j] > data[i])
                {
                    test = data[j];
                    data[j] = data[i];
                    data[i] = test;
                }
            }
        }
        return *this;
    }

    /*
        Funcao para ordenar um arranjo em ordem crescente
    */
    Array sortUp ()
    {
        int test = 0;
        for(int i = 0; i < length; i++)
        {
            for(int j = i + 1; j < length; j++)
            {
                if(data[j] < data[i])
                {
                    test = data[j];
                    data[j] = data[i];
                    data[i] = test;
                }
            }
        }
        return *this;
    }

    /*
        operador para comparar dois arrays
    */
    bool operator!= (Array<T> &comp)
    {
        bool result = false;

        if(comp.length != length)
        {
            cout << "ERRO: Arrays de tamanhos diferentes. " << endl;
        }
        else
        {
            for(int i = 0; i < length; i++)
            {
                if(data[i] != comp.data[i])
                {
                    return true;
                }
            }
        }
        return result;
    }

    /*
        operador para calcular a diferenca entre dois arrays
    */
    Array& operator- (Array <T> diff)
    {
        static Array <T> result (diff);
        if(diff.length != length)
        {
            cout << "ERRO: arrays de tamanhos diferentes. " << endl;
        }
        else
        {
            for(int i = 0; i < length; i++)
            {
                result.data[i] = this->data[i] - result.data[i];
            }
        }
        return result;
    }
}; 
 

#endif 