#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#include <list>

//--------------------------------------------------------------------------------------------
// Classes controladoras da camada de apresentaçăo.

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo controle.

class CntrApresentacaoControle{
    private:
        Email email;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IApresentacaoImoveis *cntrApresentacaoImoveis;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
        void setCntrApresentacaoImoveis(IApresentacaoImoveis*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr){
            cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoImoveis(IApresentacaoImoveis *cntr){
    cntrApresentacaoImoveis = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo autenticaçăo.

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo pessoal.

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        IServicoImoveis *cntrServicoImoveis;
        void editar(Email);
        void descadastrar(Email);
    public:
        void executar(Email);
        void cadastrar();
        void setCntrServicoPessoal(IServicoPessoal*);
        void setCntrServicoImoveis(IServicoImoveis*);
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

inline void CntrApresentacaoPessoal::setCntrServicoImoveis(IServicoImoveis *cntr){
    cntrServicoImoveis = cntr;
}

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentaçăo imóveis.

class CntrApresentacaoImoveis:public IApresentacaoImoveis{
    private:
        IServicoImoveis *cntr;
        void cadastrarImovel(Email);
        void consultarImovel();
        void descadastrarImovel(Email);
        void listarImoveis();
        void editarImovel(Email);
        void cadastrarProposta(Email);
        void consultarProposta(Email);
        void descadastrarProposta(Email);
        void listarPropostas(Email);
        void listarPropostasDeImovel(Email);
    public:
        void executar();
        void executar(Email);
        void setCntrServicoImoveis(IServicoImoveis*);
};

inline void CntrApresentacaoImoveis::setCntrServicoImoveis(IServicoImoveis *cntr){
    this->cntr = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
