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
    int_Array* read (); //read
    int_Array* fread (string Filename); //file read
    int_Array* randomArray(int inferior, int superior); //randomArray 
    int searchFirstOdd();
    void print(); //print
    void fprint(string Filename); //fprint
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
        for(int i = 0; i < length; i++)
        {
            this->data[i] = value;
        }
        return this;
    }

    void int_Array::print()
    {
        cout << endl;
        for(int i = 0; i < length; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }

    ref_int_Array int_Array::read ()
    {
        int x = 0;
        for(int i = 0; i < length; i++)
        {
            cout << i << " = ";
            cin >> x;
            this->data[i] = x;
        }
        return this;
    }

    ref_int_Array int_Array::fread (string Filename)
    {
        int n = 0;
        ifstream file (Filename);
        if(file.is_open())
        {
            file >> n;
            if(n <= 0 )
            {
                cout << "\nERROR: Invalid length.\n" << endl; 
            }
            else
            {
                ref_int_Array array = new int_Array(n);
                if(!array->data)
                {
                    cout << "\nERROR: Memory allocation failed.\n" << endl;
                    delete array;
                    return nullptr;
                }
                else
                {
                    for(int i = 0; i < length; i++)
                    {
                        file >> array->data[i];
                    }
                }
                return array;
            }
            file.close();
        }
    }

    void int_Array::fprint ( string Filename ) 
    { 
       ofstream file;  
 
       file.open ( Filename ); 
       file << length << endl; 
       for ( int x = 0; x < length; x++ ) 
       { 
           file << data[ x ] << endl; 
       } 
       cout << endl << "dados gravados com sucesso em: "<< Filename << endl;
       file.close ( );
    }

    ref_int_Array int_Array::randomArray (int inferior, int superior)
    {   
        int n, x = 0;
        while (n < this->length)
        {
            x = rand() % 100;
            if(x >= inferior && x <= superior)
            {
                this->data[n] = x;
                n++;
            }
        }
        
        return this;
    }   

    int int_Array::searchFirstOdd ()
    {

    }