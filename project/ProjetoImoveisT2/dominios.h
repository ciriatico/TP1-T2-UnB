#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

///
/// Padrão para representação de código.
///
/// Regras de formato:
///
/// - Formato XXXXX;
///
/// - Código não é 00000;
///
/// - Código é composto por letra maiúscula (A-Z) ou dígito (0 - 9).
///

class Codigo
{
private:
	static const string DEFAULT;
	static const string PROIBIDO;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com o código "XXXXX".
///

	Codigo();

///
/// Retorna o código.
///
/// @return Código.
///

	string getValor() const;

///
/// Armazena o código informado caso o mesmo seja válido.
///
/// Lança exceção caso o código informado seja inválido.
///
/// @param valor Código.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Codigo::getValor() const
{
	return valor;
}

///
/// Padrão para representação de classe: 1 para apartamento, 2 para casa e 3 para quarto.
///
/// Regras de formato:
///
/// - Código é valor igual a 1, 2 ou 3.
///

class Classe
{
private:
	static const int DEFAULT = 1;
	static const int APARTAMENTO = 1;
	static const int CASA = 2;
	static const int QUARTO = 3;
	int valor;
	void validar(int);

public:

///
/// Inicializa o objeto com a classe 1.
///

	Classe();

///
/// Retorna a classe.
///
/// @return Classe.
///

	int getValor() const;

///
/// Armazena a classe informado caso a mesma seja válido.
///
/// Lança exceção caso a classe informada seja inválido.
///
/// @param valor Classe.
///
/// @throw invalid_argumento
///

	void setValor(const int);
};

inline int Classe::getValor() const
{
	return valor;
}

///
/// Padrão para representação de descrição.
///
/// Regras de formato:
///
/// - Descrição contém de 5 a 30 caracteres;
///
/// - Terminado por ponto.
///

class Descricao
{
private:
	static const string DEFAULT;
	static const int MINIMO_CARACTERES = 5;
	static const int MAXIMO_CARACTERES = 30;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com a descrição "Xxxxx.'.
///

	Descricao();

///
/// Retorna a descrição.
///
/// @return Descrição
///

	string getValor() const;

///
/// Armazena a descrição informada caso a mesma seja válida.
///
/// Lança exceção caso a descrição informada seja inválida.
///
/// @param valor Descrição.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Descricao::getValor() const
{
	return valor;
}

///
/// Padrão para representação de endereço.
///
/// Regras de formato:
///
/// - Endereço contém de 5 a 20 caracteres;
///
/// - Cada caractere é letra (A-Z ou a-z), dígito (0 - 9), ponto ou espaço.
///


class Endereco
{
private:
	static const string DEFAULT;
	static const int MINIMO_CARACTERES = 5;
	static const int MAXIMO_CARACTERES = 20;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com o endereço "Xxxxx xx.".
///

	Endereco();

///
/// Retorna o endereço.
///
/// @return Endereço.
///

	string getValor() const;

///
/// Armazena o endereço informado caso o mesmo seja válido.
///
/// Lança exceção caso o endereço informado seja inválido.
///
/// @param valor Endereço.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Endereco::getValor() const
{
	return valor;
}

///
/// Padrão para representação de data, considerando inclusive a ocorrência de anos bissextos.
///
/// Regras de formato:
///
/// - Formato DD-MM-AA;
///
/// - 01 a 31 em DD;
///
/// - 01 a 12 em MM;
///
/// - 21 a 99 em AA.
///

class Data
{
private:
	static const string DEFAULT;
	static const char DELIM;
	static const int POSICAO_PRIMEIRO_DELIM = 2;
	static const int POSICAO_SEGUNDO_DELIM = 5;
	static const int MINIMO_DIA = 1;
	static const int MAXIMO_DIA = 31;
	static const int MINIMO_MES = 1;
	static const int MAXIMO_MES = 12;
	static const int MINIMO_ANO = 21;
	static const int MAXIMO_ANO = 99;
	static const int TAMANHO_DATA = 8;
	string valor;
	bool checarBissexto(int);
	int tamanhoMes(int, int);
	void validar(string);

public:

///
/// Inicializa o objeto com a data "29-01-98".
///

	Data();

///
/// Retorna a data.
///
/// @return Data.
///

	string getValor() const;

///
/// Armazena a data informada caso a mesma seja válida.
///
/// Lança exceção caso a data informada seja inválida.
///
/// @param valor Data.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Data::getValor() const
{
	return valor;
}

///
/// Padrão para representação de número.
///
/// Regras de formato:
///
/// - Número está entre 0 e 20.
///


class Numero
{
private:
	static const int DEFAULT = 0;
	static const int MINIMO = 0;
	static const int MAXIMO = 20;
	int valor;
	void validar(int);

public:

///
/// Inicializa o objeto com o número 0.
///

	Numero();

///
/// Retorna o número.
///
/// @return Número.
///

	int getValor() const;

///
/// Armazena o número informado caso o mesmo seja válido.
///
/// Lança exceção caso o número informado seja inválido.
///
/// @param valor Número.
///
/// @throw invalid_argumento
///

	void setValor(const int);
};

inline int Numero::getValor() const
{
	return valor;
}

///
/// Padrão para representação de moeda.
///
/// Regras de formato:
///
/// - Valor da moeda entre 0,00 a 1.000.000,00.
///

class Moeda
{
private:
	static const string DEFAULT;
	static const double MINIMO;
	static const double MAXIMO;
	string valor;
	double stringMoedaParaDouble(string);
	void validar(string);

public:

///
/// Inicializa o objeto com a moeda 0,00.
///

	Moeda();

///
/// Retorna a moeda.
///
/// @return Moeda.
///

	string getValor() const;

///
/// Armazena o valor da moeda informado caso o mesmo seja válido.
///
/// Lança exceção caso o valor da moeda informado seja inválido.
///
/// @param valor Moeda.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Moeda::getValor() const
{
	return valor;
}

///
/// Padrão para representação de nome.
///
/// Regras de formato:
///
/// - Nome tem entre 5 e 25 caracteres;
///
/// - Cada caractere é letra (A-Z ou a-z), ponto ou espaço;
///
/// - Ponto é precedido por letra;
///
/// - Não há espaços em sequências;
///
/// - Primeira letra de cada termo é letra maiúsculo.
///

class Nome
{
private:
	static const string DEFAULT;
	static const int MINIMO_CARACTERES = 5;
	static const int MAXIMO_CARACTERES = 25;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com o nome "Nome A. Colocar".
///

	Nome();

///
/// Retorna o nome.
///
/// @return Nome.
///

	string getValor() const;

///
/// Armazena o nome informado caso o mesmo seja válido.
///
/// Lança exceção caso o nome informado seja inválido.
///
/// @param valor Nome.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Nome::getValor() const
{
	return valor;
}

///
/// Padrão para representação de e-mail.
///
/// Regras de formato:
///
/// - Formato nome@dominio;
///
/// - Valor de nome é composto por até 10 caracteres;
///
/// - Domínio é composto por até 20 caracteres;
///
/// - Cada caractere é letra (A-Z ou a-z), dígito (0 - 9) ou ponto;
///
/// - Não existem pontos em sequência.
///


class Email
{
private:
	static const string DEFAULT;
	static const string DELIM;
	static const int LIMITE_NOME = 10;
	static const int LIMITE_DOMINIO = 20;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com o e-mail "nome@dominio".
///

	Email();

///
/// Retorna o e-mail.
///
/// @return E-mail.
///

	string getValor() const;

///
/// Armazena o e-mail informado caso o mesmo seja válido.
///
/// Lança exceção caso o e-mail informado seja inválido.
///
/// @param valor E-mail.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Email::getValor() const
{
	return valor;
}

///
/// Padrão para representação de senha.
///
/// Regras de formato:
///
/// - Formato XXXXXX;
///
/// - Cada caractere é (A-Z ou a-z) ou dígito (0 - 9);
///
/// - Não existe caracter repetido;
///
/// - Existe pelo menos uma letra maiúscula, uma letra minúscula e um código.
///

class Senha
{
private:
	static const string DEFAULT;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com a senha "Aa1234".
///

	Senha();

///
/// Retorna a senha.
///
/// @return Senha.
///

	string getValor() const;

///
/// Armazena a senha informada caso a mesma seja válida.
///
/// Lança exceção caso a senha informada seja inválida.
///
/// @param valor Senha.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Senha::getValor() const
{
	return valor;
}

///
/// Padrão para representação de telefone.
///
/// Regras de formato:
///
/// - Formato (XXX)-XXXXXXXXX;
///
/// - Cada X é dígito (0 - 9);
///
/// - Telefone não é (000)-000000000.
///

class Telefone
{
private:
	static const int POSICAOCHAVESINICIO = 0;
	static const int POSICAOCHAVESFIM = 4;
	static const int POSICAOHIFEN = 5;
	static const string DEFAULT;
	static const string DDDPROIBIDO;
	static const string NUMEROPROIBIDO;
	string valor;
	void validar(string);

public:

///
/// Inicializa o objeto com o telefone (123)-123456789.
///

	Telefone();

///
/// Retorna o telefone.
///
/// @return Telefone.
///

	string getValor() const;

///
/// Armazena o telefone informado caso o mesmo seja válido.
///
/// Lança exceção caso o telefone informado seja inválido.
///
/// @param valor Telefone.
///
/// @throw invalid_argumento
///

	void setValor(const string);
};

inline string Telefone::getValor() const
{
	return valor;
}

#endif // DOMINIOS_H_INCLUDED
