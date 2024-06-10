#include <string>

class Erro
{
private:
    int erro;


protected:

    void setErro(int erro)
    {
        this->erro = erro;
    } 

public:

    Erro ()
    {
        this->erro = 0;
    }


    static const std::string NO_ERROR;

    /**
     *   Funcao para obter o codigo de erro.
     *   @return codigo de erro guardado
     */
    int getErro()
    {
        return ( erro ); // valor provisorio, precisara' ser definido futuramente
    } // end getErro ( )

    /**
     * indicar a existencia de erro.
     */
    bool hasErro()
    {
        return (getErro() != 0);
    } // end hasErro ( )

    /**
     *   Funcao para obter mensagem relativa ao código de erro.
     *   @return mensagem sobre o erro
     */
    virtual std::string getErroMsg()
    {
        return ("");
    } // end getErroMsg ( )

}; // end class Erro

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro."; // definir o valor da constante

