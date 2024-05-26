/*
   mymatrix.hpp  - v0.0. - __ / __ / _____
   Author: _________________________

 */

// ----------------------------------------------- definicoes globais

#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

template <typename T>
class Matrix
{
private: // area reservada
   T optional;
   int rows;
   int columns;
   T **data;

public: // area aberta
   Matrix()
   {
      // definir valores iniciais
      this->rows = 0;
      this->columns = 0;
      // sem reservar area
      data = nullptr;
   } // end constructor

   Matrix(int rows, int columns, T initial)
   {
      // definir dado local
      bool OK = true;
      // definir valores iniciais
      this->optional = initial;
      this->rows = rows;
      this->columns = columns;
      // reservar area
      data = new T *[rows];
      if (data != nullptr)
      {
         for (int x = 0; x < rows; x = x + 1)
         {
            data[x] = new T[columns];
            OK = OK && (data[x] != nullptr);
         } // end for
         if (!OK)
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

   void set(int row, int column, T value)
   {
      if (row < 0 || row >= rows ||
          column < 0 || column >= columns)
      {
         cout << "\nERROR: Invalid position.\n";
      }
      else
      {
         data[row][column] = value;
      } // end if
   } // end set ( )

   T get(int row, int column)
   {
      T value = optional;
      if (row < 0 || row >= rows ||
          column < 0 || column >= columns)
      {
         cout << "\nERROR: Invalid position.\n";
      }
      else
      {
         value = data[row][column];
      } // end if
      return (value);
   } // end get ( )

   void print()
   {
      cout << endl;
      for (int x = 0; x < rows; x = x + 1)
      {
         for (int y = 0; y < columns; y = y + 1)
         {
            cout << data[x][y] << " ";
         } // end for
         cout << endl;
      } // end for
      cout << endl;
   } // end print ( )

   void fprint(string fileName)
   {
      ofstream file;
      file.open(fileName);

      file << rows << endl;
      file << columns << endl;
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            file << data[i][j] << " ";
         }
         file << endl;
      }
      file.close();
   }

   /**
      Funcao para ler matriz de um arquivo
      @param nome do arquivo
      @return matriz, linhas e colunas
   */
   void fread(string fileName)
   {
      ifstream file;
      file.open(fileName);

      int m, n = 0;
      file >> m;
      file >> n;

      if (n <= 0 || m <= 0)
      {
         cout << "ERROR: Invalid dimensions for matrix. " << endl;
      }
      else
      {
         rows = m;
         columns = n;

         data = new T *[rows];

         for (int i = 0; i < rows; i++)
         {
            data[i] = new T[columns];
         }

         for (int i = 0; i < rows; i++)
         {
            for (int j = 0; j < columns; j++)
            {
               file >> data[i][j];
            }
         }
      }
      file.close();
   }

   /**
      Funcao para preencher uma matriz com dados aleatorios
      @param limites do intervalo
      @return matriz
   */
   Matrix randomMatrixGenerator(int a, int b)
   {
      int x, i, j = 0;

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            x = rand() % (b - a + 1) + a;
            data[i][j] = x;
         }
      }
      return *this;
   }

   /**
      Metodo para multiplicar uma matriz por uma constante
      @param constante
      @return matriz
   */
   Matrix scalar(T k)
   {
      Matrix new_matrix(rows, columns, optional);

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            new_matrix.data[i][j] = data[i][j] * k;
         }
      }
      return new_matrix;
   }

   /**
       Funcao (operador) para verificar se dois objetos (matrizes) sao diferentes
       @param objeto
       @return verdadeiro ou falso
   */
   bool operator!=(Matrix<T> &comp)
   {
      bool result = false;

      if (rows != comp.rows || columns != comp.columns)
      {
         cout << "ERROR: Missing data";
      }
      else
      {
         for (int i = 0; i < rows; i++)
         {
            for (int j = 0; j < columns; j++)
            {
               if (data[i][j] != comp.data[i][j])
               {
                  return true;
               }
            }
         }
      }
      return result;
   }

   /**
       Funcao (operador) para verificar se dois objetos (matrizes) sao iguais
       @param objeto
       @return verdadeiro ou falso
   */
   bool operator==(Matrix<T> &comp)
   {
      bool result = false;

      if (rows != comp.rows || columns != comp.columns)
      {
         cout << "ERROR: Missing data";
      }
      else
      {
         for (int i = 0; i < rows; i++)
         {
            for (int j = 0; j < columns; j++)
            {
               if (data[i][j] == comp.data[i][j])
               {
                  result = true;
               }
            }
         }
      }
      return result;
   }

   /**
       Funcao para verificar se o objeto e uma matriz identidade
       @return verdadeiro ou falso
   */
   bool identidade()
   {
      bool result = true;

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            if (i == j)
            {
               if (data[i][j] != 1)
               {
                  result = false;
               }
            }
            else
            {
               if (data[i][j] != 0)
               {
                  result = false;
               }
            }
         }
      }

      return result;
   }

   /**
       Funcao para somar duas matrizes
       @param objeto
       @return Matriz
   */
   Matrix add(Matrix<T> &other)
   {
      Matrix new_matrix(rows, columns, 0);
      if (rows != other.rows || columns != other.columns)
      {
         cout << "ERROR: Missing data" << endl;
      }
      else
      {
         for (int i = 0; i < new_matrix.rows; i++)
         {
            for (int j = 0; j < new_matrix.columns; j++)
            {
               new_matrix.data[i][j] = data[i][j] + other.data[i][j];
            }
         }
         // new_matrix.print();
      }
      return new_matrix;
   }

   /**
       Funcao para operar duas linhas da matriz, guardando no lugar da primeira,
       as somas de cada elemento da primeira linha com o respectivo da segunda linha
       multiplicados por uma constante
       @param linha1, linha2, constante
       @return Matriz
   */
   Matrix addRows(int R1, int R2, T k)
   {
      Matrix new_matrix(rows, columns, 0);
      for (int i = 0; i < new_matrix.rows; i++)
      {
         for (int j = 0; j < new_matrix.columns; j++)
         {
            new_matrix.data[i][j] = data[i][j];
         }
      }

      // for(int i = 0; i < new_matrix.rows; i++)
      // {
      //    for(int j = 0; j < new_matrix.columns; j++)
      //    {
      //       if(R1 == i)
      //       {
      //          new_matrix.data[i][j] = new_matrix.data[R1][j] + (data[R2][j] * k);
      //       }
      //    }
      // }

      for (int j = 0; j < columns; j++)
      {
         new_matrix.data[R1][j] = data[R1][j] + (data[R2][j] * k);
      }

      return new_matrix;
   }

   /**
       Funcao para operar duas linhas da matriz, guardando no lugar da primeira,
       as diferencas de cada elemento da primeira linha com o respectivo da segunda linha
       multiplicados por uma constante
       @param linha1, linha2, constante
       @return Matriz
   */
   Matrix subtractRows(int R1, int R2, T k)
   {
      Matrix new_matrix(rows, columns, 0);

      for (int i = 0; i < new_matrix.rows; i++)
      {
         for (int j = 0; j < new_matrix.columns; j++)
         {
            new_matrix.data[i][j] = data[i][j];
         }
      }

      for (int j = 0; j < columns; j++)
      {
         new_matrix.data[R1][j] = data[R1][j] - (data[R2][j] * k);
      }
      return new_matrix;
   }

   /**
       Funcao para procurar em qual linha esta um elemento
       @param elemento
       @return posicao
   */
   int searchRows(T value)
   {
      int result = -1;

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            if (value == data[i][j])
            {
               result = i;
            }
         }
      }

      return result;
   }

   /**
       Funcao para procurar em qual coluna esta um elemento
       @param elemento
       @return posicao
   */
   int searchColumns(T value)
   {
      int result = -1;

      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < columns; j++)
         {
            if (value == data[i][j])
            {
               result = j;
            }
         }
      }
      return result;
   }

   /**
       Funcao para modificar uma matriz para uma matriz transposta
       @return matriz modificada
   */
   Matrix transpose()
   {
      Matrix new_matrix(columns, rows, 0);

      for (int i = 0; i < new_matrix.rows; i++)
      {
         for (int j = 0; j < new_matrix.columns; j++)
         {
            new_matrix.data[i][j] = data[j][i];
         }
      }

      return new_matrix;
   }

   /*
      Exercicio extra 01
   */
   bool extra01()
   {
      bool result = true;
      int x = 1;
      int i, j = 0;
      while (j < columns)
      {
         while (i < rows)
         {
            // cout << x << endl;
            // cout << data[i][0] << endl;
            if (data[i][j] != x)
            {
               result = false;
            }
            x++;
            i++;
         }
         j++;
         i = 0;
      }
      return result;
   }

   /*
      Exercicio extra 02
   */
   Matrix extra02(int rows, int columns)
   {
      Matrix<int> new_matrix(rows, columns, 0);
      int x = rows * columns;
      int j = 0;

      while (j < columns)
      {
         for (int i = 0; i < rows; i++)
         {
            new_matrix.data[i][j] = x;
            x--;
         }
         j++;
      }
      return new_matrix;
   }
}; // end class

#endif