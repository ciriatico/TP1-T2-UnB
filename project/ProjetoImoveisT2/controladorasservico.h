#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#include <list>

#include <iostream>

#include <string>
#include <stdio.h>

#include "sqlite3.h"

//--------------------------------------------------------------------------------------------
// Classe ErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
            nomeBancoDados = "tp1_t2_db.db";
        }
        void executar();
};

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Email);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarUsuario.

class ComandoDescadastrarUsuario:public ComandoSQL {
public:
        ComandoDescadastrarUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoEditarUsuario.

class ComandoEditarUsuario:public ComandoSQL {
public:
        ComandoEditarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarImovel.

class ComandoCadastrarImovel:public ComandoSQL {
public:
        ComandoCadastrarImovel(Imovel, Email);
};

//---------------------------------------------------------------------------
//Classe ComandoLerEmailImovel.

class ComandoLerEmailImovel:public ComandoSQL {
public:
        ComandoLerEmailImovel(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarImovel.

class ComandoDescadastrarImovel:public ComandoSQL {
    public:
        ComandoDescadastrarImovel(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoListarImoveis.

class ComandoListarImoveis:public ComandoSQL {
public:
        ComandoListarImoveis();
        list<Imovel> getResultado(list<Email>*);
};

//---------------------------------------------------------------------------
//Classe ComandoEditarImovel.

class ComandoEditarImovel:public ComandoSQL {
public:
        ComandoEditarImovel(Imovel);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarImoveisPorEmail.

class ComandoDescadastrarImoveisPorEmail:public ComandoSQL {
    public:
        ComandoDescadastrarImoveisPorEmail(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarImovel.

class ComandoPesquisarImovel:public ComandoSQL {
public:
        ComandoPesquisarImovel(Codigo);
        Imovel getResultado(Email*);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarProposta.

class ComandoCadastrarProposta:public ComandoSQL {
public:
        ComandoCadastrarProposta(Proposta, Email, Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoLerEmailProposta.

class ComandoLerEmailProposta:public ComandoSQL {
public:
        ComandoLerEmailProposta(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarProposta.

class ComandoDescadastrarProposta:public ComandoSQL {
    public:
        ComandoDescadastrarProposta(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarProposta.

class ComandoPesquisarProposta:public ComandoSQL {
public:
        ComandoPesquisarProposta(Codigo);
        Proposta getResultado(Email*, Codigo*);
};

//---------------------------------------------------------------------------
//Classe ComandoListarPropostas.

class ComandoListarPropostas:public ComandoSQL {
public:
        ComandoListarPropostas();
        list<Proposta> getResultado(list<Codigo>*, list<Email>*);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarPropostasPorEmail.

class ComandoDescadastrarPropostasPorEmail:public ComandoSQL {
    public:
        ComandoDescadastrarPropostasPorEmail(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarPropostasPorCodigoImovel.

class ComandoDescadastrarPropostasPorCodigoImovel:public ComandoSQL {
    public:
        ComandoDescadastrarPropostasPorCodigoImovel(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarPropostasDeImoveisDeUsuario.

class ComandoDescadastrarPropostasDeImoveisDeUsuario:public ComandoSQL {
    public:
        ComandoDescadastrarPropostasDeImoveisDeUsuario(Email);
};

//---------------------------------------------------------------------------
//Classe ComandoContarEntidade.

class ComandoContarEntidade:public ComandoSQL {
public:
        ComandoContarEntidade(string, string, string);
        int getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoContarEntidadeDuplo.

class ComandoContarEntidadeDuplo:public ComandoSQL {
public:
        ComandoContarEntidadeDuplo(string, string, string, string, string, string);
        int getResultado();
};

// Método que checa se usuário está cadastrado no programa.

bool checarUsuarioCadastrado(Email);

//--------------------------------------------------------------------------------------------
// Classes controladoras da camada de serviços.

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço autenticaçăo.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço pessoal.

class CntrServicoPessoal:public IServicoPessoal{
    public:
        bool cadastrarUsuario(Usuario);
        bool descadastrarUsuario(Email);
        bool editarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------
// Classe controladora de serviço imóveis.

class CntrServicoImoveis:public IServicoImoveis{
    private:
        static const string INVALIDO;

        Codigo gerarCodigo();
        bool codigoValido(string, Codigo);
        Codigo gerarCodigoValido(string);

        int compararUnidadesData(int, int);
        int compararDatas(Data, Data);
        bool checarIntervaloDatas(Data, Data, Data, Data);

        double moedaParaDouble(Moeda);

        bool validarPropostaCadastro(Proposta, Codigo);

    public:
        bool cadastrarImovel(Imovel, Email);
        bool consultarImovel(Imovel*, Email*);
        bool descadastrarImovel(Codigo, Email);
        bool listarImoveis(list<Imovel>*);
        bool editarImovel(Imovel, Email);
        bool cadastrarProposta(Proposta, Email, Codigo);
        bool consultarProposta(Email, Proposta*, Email*, Codigo*);
        bool descadastrarProposta(Codigo, Email);
        bool listarPropostas(Email, list<Proposta>*, list<Codigo>*);
        bool listarPropostasDeImovel(Email, Codigo, list<Proposta>*, list<Codigo>*);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
