#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declaraçőes das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoPessoal;
class IServicoImoveis;

//--------------------------------------------------------------------------------------------
// Declaraçőes das interfaces da camada de apresentaçăo.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        virtual void setCntrServicoImoveis(IServicoImoveis*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoImoveis{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoImoveis(IServicoImoveis*) = 0;
        virtual ~IApresentacaoImoveis(){}
};

//--------------------------------------------------------------------------------------------
// Declaraçőes das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual bool descadastrarUsuario(Email) = 0;
        virtual bool editarUsuario(Usuario) = 0;
        virtual ~IServicoPessoal(){}
};

class IServicoImoveis{
public:
        virtual bool cadastrarImovel(Imovel, Email) = 0;
        virtual bool consultarImovel(Imovel*, Email*) = 0;
        virtual bool descadastrarImovel(Codigo, Email) = 0;
        virtual bool listarImoveis(list<Imovel>*) = 0;
        virtual bool editarImovel(Imovel, Email) = 0;
        virtual bool cadastrarProposta(Proposta, Email, Codigo) = 0;
        virtual bool consultarProposta(Email, Proposta*, Email*, Codigo*) = 0;
        virtual bool descadastrarProposta(Codigo, Email) = 0;
        virtual bool listarPropostas(Email, list<Proposta>*, list<Codigo>*) = 0;
        virtual bool listarPropostasDeImovel(Email, Codigo, list<Proposta>*, list<Codigo>*) = 0;

        virtual ~IServicoImoveis(){}
};

#endif // INTERFACES_H_INCLUDED
