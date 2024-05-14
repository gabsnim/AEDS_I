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
using std::ifstream ;   // para ler arquivo

class int_Array
{
    public:
    int length;
    int *data;

    int_Array (int n); //construtor
    ~int_Array(); //destrutor
    int_Array* init (int value); //init
    void print();
};
    typedef int_Array* ref_int_Array;

    int_Array::int_Array (int n)     //construtor;
    {
        if(n > 0)
        {
            this->data = (int*)malloc(n * sizeof(int));

            if(this->data)
            {
                this->length = n;
            }
        }
    }

    int_Array::~int_Array() //destrutor
    {
        free(data);
    }

    ref_int_Array int_Array::init (int value)
    {
        for(int x = 0; x < length; x++)
        {
            this->data[x] = value;
        }
        return this;
    }

    void int_Array::print()
    {
        cout << endl;
        for(int x = 0; x < length; x++)
        {
            cout << this->data[x] << " ";
        }
        cout << endl;
    }