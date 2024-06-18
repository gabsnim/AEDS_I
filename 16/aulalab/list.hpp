#include <iostream>

#define null NULL

class intCell
{
public:
     int value;
     intCell *right;
     intCell *left;

     //construtor
     intCell()
     {
          value = 0;
          left = null;
          right = null;
     }
     //construtor alternativo
     intCell(int x, intCell *l, intCell *r)
     {
          value = x;
          left = l;
          right = r;
     }
     
     void print()
     {
          intCell *tmp = this;
          while (tmp)
          {
               printf("%d ", tmp->value);
               tmp = tmp->right;
          }
     }

     void printN (int x)
     {    
          int i = 0;
          intCell *tmp = this;
          while (i < x)
          {
               printf("%d ", tmp->value);
               tmp = tmp->right;
               i++;
          }
          
     }
};

