#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

///
///  Padrão para representação de imóvel, composto de código, classe, descrição, endereço, data inicial, data final, hóspedes e valor.
///

class Imovel
{
private:
	Codigo codigo;
	Classe classe;
	Descricao descricao;
	Endereco endereco;
	Data dataInicial;
	Data dataFinal;
	Numero hospedes;
	Moeda valor;
	Email email;

public:

///
/// Armazena o código dado.
///
/// @param referência Código.
///

	void setCodigo(const Codigo&);

///
/// Retorna o código armazenado.
///
/// @return Código.
///

	Codigo getCodigo() const;

///
/// Armazena a classe dada.
///
/// @param referência Classe.
///

	void setClasse(const Classe&);

///
/// Retorna a classe armazenada.
///
/// @return Classe.
///

	Classe getClasse() const;

///
/// Armazena a descrição dada.
///
/// @param referência Descrição.
///

	void setDescricao(const Descricao&);

///
/// Retorna a descrição armazenada.
///
/// @return Descrição.
///

	Descricao getDescricao() const;

///
/// Armazena o endereço dado.
///
/// @param referência Endereço.
///

	void setEndereco(const Endereco&);

///
/// Retorna o endereço armazenado.
///
/// @return Endereço.
///

	Endereco getEndereco() const;

///
/// Armazena a data inicial dada.
///
/// @param referência Data.
///

	void setDataInicial(const Data&);

///
/// Retorna a data inicial armazenada.
///
/// @return Data.
///

	Data getDataInicial() const;

///
/// Armazena a data final dada.
///
/// @param referência Data.
///

	void setDataFinal(const Data&);

///
/// Retorna a data final armazenada.
///
/// @return Data.
///

	Data getDataFinal() const;

///
/// Armazena o número de hóspedes dado.
///
/// @param referência Número.
///

	void setHospedes(const Numero&);

///
/// Retorna o número de hóspedes armazenado.
///
/// @return Número.
///

	Numero getHospedes() const;

///
/// Armazena a moeda dada.
///
/// @param referência Moeda.
///

	void setValor(const Moeda&);

///
/// Retorna a moeda armazenada.
///
/// @return Moeda.
///

	Moeda getValor() const;
};

inline void Imovel::setCodigo(const Codigo& codigo)
{
	this->codigo = codigo;
}

inline Codigo Imovel::getCodigo() const
{
	return codigo;
}

inline void Imovel::setClasse(const Classe& classe)
{
	this->classe = classe;
}

inline Classe Imovel::getClasse() const
{
	return classe;
}

inline void Imovel::setDescricao(const Descricao& descricao)
{
	this->descricao = descricao;
}

inline Descricao Imovel::getDescricao() const
{
	return descricao;
}

inline void Imovel::setEndereco(const Endereco& endereco)
{
	this->endereco = endereco;
}

inline Endereco Imovel::getEndereco() const
{
	return endereco;
}

inline void Imovel::setDataInicial(const Data& dataInicial)
{
	this->dataInicial = dataInicial;
}

inline Data Imovel::getDataInicial() const
{
	return dataInicial;
}

inline void Imovel::setDataFinal(const Data& dataFinal)
{
	this->dataFinal = dataFinal;
}

inline Data Imovel::getDataFinal() const
{
	return dataFinal;
}

inline void Imovel::setHospedes(const Numero& hospedes)
{
	this->hospedes = hospedes;
}

inline Numero Imovel::getHospedes() const
{
	return hospedes;
}

inline void Imovel::setValor(const Moeda& valor)
{
	this->valor = valor;
}

inline Moeda Imovel::getValor() const
{
	return valor;
}

///
///  Padrão para representação de proposta, composto de código, data inicial, data final, hóspedes e valor.
///

class Proposta
{
private:
	Codigo codigo;
	Data dataInicial;
	Data dataFinal;
	Numero hospedes;
	Moeda valor;

public:

///
/// Armazena o código dado.
///
/// @param referência Código.
///

	void setCodigo(const Codigo&);

///
/// Retorna o código armazenado.
///
/// @return Código.
///

	Codigo getCodigo() const;

///
/// Armazena a data inicial dada.
///
/// @param referência Data.
///

	void setDataInicial(const Data&);

///
/// Retorna a data inicial armazenada.
///
/// @return Data.
///

	Data getDataInicial() const;

///
/// Armazena a data final dada.
///
/// @param referência Data.
///

	void setDataFinal(const Data&);

///
/// Retorna a data final armazenada.
///
/// @return Data.
///

	Data getDataFinal() const;

///
/// Armazena o número de hóspedes dado.
///
/// @param referência Número.
///

	void setHospedes(const Numero&);

///
/// Retorna o número de hóspedes armazenado.
///
/// @return Número.
///

	Numero getHospedes() const;

///
/// Armazena a moeda dada.
///
/// @param referência Moeda.
///

	void setValor(const Moeda&);

///
/// Retorna a moeda armazenada.
///
/// @return Moeda.
///

	Moeda getValor() const;
};

inline void Proposta::setCodigo(const Codigo& codigo)
{
	this->codigo = codigo;
}

inline Codigo Proposta::getCodigo() const
{
	return codigo;
}

inline void Proposta::setDataInicial(const Data& dataInicial)
{
	this->dataInicial = dataInicial;
}

inline Data Proposta::getDataInicial() const
{
	return dataInicial;
}

inline void Proposta::setDataFinal(const Data& dataFinal)
{
	this->dataFinal = dataFinal;
}

inline Data Proposta::getDataFinal() const
{
	return dataFinal;
}

inline void Proposta::setHospedes(const Numero& hospedes)
{
	this->hospedes = hospedes;
}

inline Numero Proposta::getHospedes() const
{
	return hospedes;
}

inline void Proposta::setValor(const Moeda& valor)
{
	this->valor = valor;
}

inline Moeda Proposta::getValor() const
{
	return valor;
}

///
///  Padrão para representação de usuário, composto de nome, e-mail, senha e telefone.
///

class Usuario
{
private:
	Nome nome;
	Email email;
	Senha senha;
	Telefone telefone;

public:

///
/// Armazena o nome dado.
///
/// @param referência Nome.
///

	void setNome(const Nome&);

///
/// Retorna o nome armazenado.
///
/// @return Nome.
///

	Nome getNome() const;

///
/// Armazena o e-mail dado.
///
/// @param referência E-mail.
///

	void setEmail(const Email&);

///
/// Retorna o e-mail armazenado.
///
/// @return E-mail.
///

	Email getEmail() const;

///
/// Armazena a senha dada.
///
/// @param referência Senha.
///

	void setSenha(const Senha&);

///
/// Retorna a senha armazenada.
///
/// @return Senha.
///

	Senha getSenha() const;

///
/// Armazena o telefone dado.
///
/// @param referência Telefone.
///

	void setTelefone(const Telefone&);

///
/// Retorna o telefone armazenado.
///
/// @return Telefone.
///

	Telefone getTelefone() const;
};

inline void Usuario::setNome(const Nome& nome)
{
	this->nome = nome;
}

inline Nome Usuario::getNome() const
{
	return nome;
}

inline void Usuario::setEmail(const Email& email)
{
	this->email = email;
}

inline Email Usuario::getEmail() const
{
	return email;
}

inline void Usuario::setSenha(const Senha& senha)
{
	this->senha = senha;
}

inline Senha Usuario::getSenha() const
{
	return senha;
}

inline void Usuario::setTelefone(const Telefone& telefone)
{
	this->telefone = telefone;
}

inline Telefone Usuario::getTelefone() const
{
	return telefone;
}


#endif // ENTIDADES_H_INCLUDED
