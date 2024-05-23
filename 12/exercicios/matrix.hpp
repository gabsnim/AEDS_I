/* 
   mymatrix.hpp  - v0.0. - __ / __ / _____ 
   Author: _________________________ 
 
 */ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYMATRIX_H_ 
#define _MYMATRIX_H_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;   // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;  // para definir espacamento 
 
#include <string> 
using std::string;  // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;  // para gravar arquivo 
using std::ifstream;   // para ler    arquivo 
 
 
template < typename T > 
class Matrix 
{ 
  private:    // area reservada 
    T   optional; 
    int rows      ; 
    int columns; 
    T** data       ; 

  public:   // area aberta 
    Matrix ( ) 
    { 
     // definir valores iniciais 
        this->rows = 0; 
        this->columns = 0; 
     // sem reservar area 
        data = nullptr; 
    } // end constructor 
 
    Matrix ( int rows, int columns, T initial ) 
    { 
     // definir dado local 
        bool OK            = true; 
     // definir valores iniciais 
        this->optional = initial      ; 
        this->rows       = rows       ; 
        this->columns = columns; 
     // reservar area 
        data         = new T* [ rows ]; 
        if ( data != nullptr ) 
        { 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
              data [x] = new T  [ columns ]; 
              OK = OK && ( data [x] != nullptr ); 
           } // end for 
           if ( ! OK ) 
           { 
              data = nullptr; 
           } // end if 
        } // end if 
    } // end constructor 
 
//    ~Matrix ( ) 
//    { 
//        if ( data != nullptr ) 
//        { 
//           for ( int x = 0; x < rows; x=x+1 ) 
//           { 
//               delete ( data [ x ] ); 
//           } // end for 
//           delete ( data ); 
//           data = nullptr; 
//        } // end if 
//    } // end destructor ( ) 
 
    void set ( int row, int column, T value ) 
    { 
      if ( row       < 0 || row        >= rows      || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         data [ row ][ column ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int row, int column ) 
    { 
      T value = optional; 
      if ( row       < 0 || row       >= rows       || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         value = data [ row ][ column ]; 
      } // end if 
      return ( value ); 
    } // end get ( ) 
     
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               cout << data[ x ][ y ] << " "; 
           } // end for 
           cout << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 

    void fprint (string fileName)
    {
      ofstream file;
      file.open(fileName);
      
         file << rows << endl;
         file << columns << endl;
         for(int i = 0; i < rows; i++)
         {
            for(int j = 0; j < columns; j++)
            {
               file << data[i][j] << " ";
            }
            file << endl;
         }
      file.close();
    }

    void fread (string fileName)
    {
      ifstream file;
      file.open(fileName);

      int m, n = 0;
      file >> m;
      file >> n;

      if(n <= 0 || m <= 0)
      {
         cout << "ERROR: Invalid dimensions for matrix. " << endl;
      }
      else
      {
         rows = m;
         columns = n;

         data = new T * [rows];

         for(int i = 0; i < rows; i++)
         {
            data[i] = new T [columns];
         }

         for(int i = 0; i < rows; i++)
         {
            for(int j = 0; j < columns; j++)
            {
               file >> data [i][j];
            }
         }
      }
      file.close();
    }

    Matrix randomMatrixGenerator (int a, int b)
    {
        int x, i, j = 0;

        // while (i < rows)
        // {
        //     while (j < columns)
        //     {
        //         x = rand () % 100;
        //         // cout << x << endl;
        //         if(x >= a && x <= b)
        //         {
        //             data[i][j] = x;
        //             i++;
        //             j++;
        //         }
        //     }
        // }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                x = rand() % (b - a + 1) + a;
                data[i][j] = x;
            }
        }
        return *this;
    }

    Matrix scalar (T k)
    {
      Matrix new_matrix(rows, columns, optional);

      for(int i = 0; i < rows; i++)
      {
         for(int j = 0; j < columns; j++)
         {
            new_matrix.data[i][j] = data[i][j] * k;     
         }
      }
      return new_matrix;
    }

    bool operator!= (Matrix<T> &comp)
    {
      bool result = false;

      if(rows != comp.rows || columns != comp.columns)
      {
         cout << "ERROR: Missing data";
      }
      else
      {
         for(int i = 0; i < rows; i++)
         {
            for(int j = 0; j < columns; j++)
            {
               if(data[i][j] != comp.data[i][j])
               {
                  return true;
               }
            }
         }
      }
      return result; 
    }

    bool operator == (Matrix<T> &comp)
    {
      bool result = false;

      if(rows != comp.rows || columns != comp.columns)
      {
         cout << "ERROR: Missing data";
      }
      else
      {
         for(int i = 0; i < rows; i++)
         {
            for(int j = 0; j < columns; j++)
            {
               if(data[i][j] == comp.data[i][j])
               {
                  result = true;
               }
            }
         }
      }
      return result; 
    }

    bool identidade ()
    {
      bool result = true;

      for(int i = 0; i < rows; i++)
      {
         for(int j = 0; j < columns; j++)
         {
            if(i == j)
            {
               if(data[i][j] != 1)
               {
                  result = false;
               }
            }
            else
            {
               if(data[i][j] != 0)
               {
                  result = false;
               }
            }
         }
      }

      return result;
    }

    Matrix add (Matrix<int> &other)
    { 
      
    }
}; // end class 
 
#endif