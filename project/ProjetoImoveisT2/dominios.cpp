#include "dominios.h"

const string Codigo::DEFAULT = "XXXXX";
const string Codigo::PROIBIDO = "00000";

Codigo::Codigo()
{
	valor = DEFAULT;
}

void Codigo::validar(string valor)
{
    // Checar que todo caractere é letra maiúscula ou dígito.
	for (int i = 0; i < valor.size(); i++) {
		if ((valor[i] >= (int)'A') && (valor[i] <= (int)'Z'))
			continue;
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			continue;

		throw invalid_argument("Argumento invalido.");
	}

	if (valor == PROIBIDO)
		throw invalid_argument("Argumento invalido.");
}

void Codigo::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

Classe::Classe()
{
	valor = DEFAULT;
}

void Classe::validar(int valor)
{
	if ((valor != APARTAMENTO) && (valor != CASA) && (valor != QUARTO))
		throw invalid_argument("Argumento invalido.");
}

void Classe::setValor(const int valor)
{
	validar(valor);
	this->valor = valor;
}

const string Descricao::DEFAULT = "Xxxxx.";

Descricao::Descricao()
{
	valor = DEFAULT;
}

void Descricao::validar(string valor)
{
	if ((valor.size() < MINIMO_CARACTERES) || (valor.size() > MAXIMO_CARACTERES))
		throw invalid_argument("Argumento invalido.");

    // Último caractere precisa ser ponto.
	if (valor.back() != '.')
		throw invalid_argument("Argumento invalido.");
}

void Descricao::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Endereco::DEFAULT = "Xxxxx xx.";

Endereco::Endereco()
{
	valor = DEFAULT;
}

void Endereco::validar(string valor)
{
	if ((valor.size() < MINIMO_CARACTERES) || (valor.size() > MAXIMO_CARACTERES))
		throw invalid_argument("Argumento invalido.");

    // Checar que cada caractere é letra, dígito, ponto ou espaço.
	for (int i = 0; i < valor.size(); i++) {
		if ((valor[i] >= (int)'a') && (valor[i] <= (int)'z'))
			continue;
		if ((valor[i] >= (int)'A') && (valor[i] <= (int)'Z'))
			continue;
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			continue;
		if (valor[i] == (int)'.')
			continue;
		if (valor[i] == (int)' ')
			continue;

		throw invalid_argument("Argumento invalido.");
	}
}

void Endereco::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Data::DEFAULT = "29-01-98";
const char Data::DELIM = '-';

Data::Data()
{
	valor = DEFAULT;
}

bool Data::checarBissexto(int ano)
{
    // Ano bissexto é divísel por 4, 100 e 400 ou é divísvel por 4 năo por 100.
	if (((ano % 4 == 0) && (ano % 100 == 0) && (ano % 400 == 0)) || ((ano % 4 == 0) && (ano % 100 != 0)))
		return true;

	return false;
}

int Data::tamanhoMes(int mes, int ano)
{
	if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12))
		return 31;

	if (mes == 2)
	{
		if (checarBissexto(ano))
			return 29;
		return 28;
	}

	return 30;
}

void Data::validar(string valor)
{
	string dia, mes, ano;
	int ultimoDiaMes;

	// Se năo tem o delimitador nas posiçőes certas, năo segue o formato DD-MM-AA.
	if ((valor[POSICAO_PRIMEIRO_DELIM] != DELIM) || (valor[POSICAO_SEGUNDO_DELIM] != DELIM))
		throw invalid_argument("Argumento invalido.");

    // Separaçăo de dia, mes e ano em variáveis específicas para checar se estăo nos intervalos dados.
	dia = valor.substr(0, 2);
	mes = valor.substr(POSICAO_PRIMEIRO_DELIM + 1, 2);
	ano = valor.substr(POSICAO_SEGUNDO_DELIM + 1, 2);

	if (((stoi(dia) < MINIMO_DIA) || (stoi(dia) > MAXIMO_DIA)) || ((stoi(mes) < MINIMO_MES) || (stoi(mes) > MAXIMO_MES)) || ((stoi(ano) < MINIMO_ANO) || (stoi(ano) > MAXIMO_ANO)))
		throw invalid_argument("Argumento invalido.");

	if (valor.size() != TAMANHO_DATA)
		throw invalid_argument("Argumento invalido.");

	for (int i = 0; i < dia.size(); i++)
	{
		if ((dia[i] < (int)'0') || (dia[i] > (int)'9'))
			throw invalid_argument("Argumento invalido.");
		if ((mes[i] < (int)'0') || (mes[i] > (int)'9'))
			throw invalid_argument("Argumento invalido.");
		if ((ano[i] < (int)'0') || (ano[i] > (int)'9'))
			throw invalid_argument("Argumento invalido.");
	}

	// A data precisa existir, logo tem que obedecer dia máximo de męs.
	ultimoDiaMes = tamanhoMes(stoi(mes), stoi(ano));

	if (stoi(dia) > ultimoDiaMes)
		throw invalid_argument("Argumento invalido.");
}

void Data::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

Numero::Numero()
{
	valor = DEFAULT;
}

void Numero::validar(int valor)
{
	if ((valor < MINIMO) || (valor > MAXIMO))
		throw invalid_argument("Argumento invalido.");
}

void Numero::setValor(const int valor)
{
	validar(valor);
	this->valor = valor;
}

const string Moeda::DEFAULT = "0,00";
const double Moeda::MINIMO = 0.00;
const double Moeda::MAXIMO = 1000000.00;

Moeda::Moeda()
{
	this->valor = DEFAULT;
}

double Moeda::stringMoedaParaDouble(string valor)
{
    // Conversăo de valor em formato brasileiro para americano, sem vírgulas e com ponto como separador decimal.
	while (valor.find(".") != string::npos)
		valor.replace(valor.find("."), 1, "");

	while (valor.find(",") != string::npos)
		valor.replace(valor.find(","), 1, ".");

    // Conversăo do valor em formato certo para double.
	return stod(valor);
}

void Moeda::validar(string valor)
{
	double valorDouble;

	// Checar que cada caractere é dígito, ponto ou vírgula.
	for (int i = 0; i < valor.size(); i++) {
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			continue;
		if (valor[i] == (int)'.')
			continue;
		if (valor[i] == (int)',')
			continue;

		throw invalid_argument("Argumento invalido.");
	}

	valorDouble = stringMoedaParaDouble(valor);

	if ((valorDouble < MINIMO) || (valorDouble > MAXIMO))
		throw invalid_argument("Argumento invalido.");
}

void Moeda::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Nome::DEFAULT = "Nome A. Colocar";

Nome::Nome()
{
	this->valor = DEFAULT;
}

void Nome::validar(string valor)
{
	if ((valor.size() < MINIMO_CARACTERES) || (valor.size() > MAXIMO_CARACTERES))
		throw invalid_argument("Argumento invalido.");

	if (valor.find("  ") != string::npos)
		throw invalid_argument("Argumento invalido.");

    // Checar que todo caractere é letra, dígito, ponto ou espaço.
	for (int i = 0; i < valor.size(); i++) {
		if ((valor[i] >= (int)'a') && (valor[i] <= (int)'z'))
			continue;
		if ((valor[i] >= (int)'A') && (valor[i] <= (int)'Z'))
			continue;
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			continue;
		if (valor[i] == (int)'.')
			continue;
		if (valor[i] == (int)' ')
			continue;

		throw invalid_argument("Argumento invalido.");
	}

	string sequencia_nome = valor;
	string parte_corte;
	char caractere_inicial_corte, caractere_inicial_sequencia;

	// Checagem de que cada primeira letra de termo é caracter maiúsculo.
	while (sequencia_nome.find(" ") != string::npos) {
        // Laço dividindo o nome em 2 a partir do primeiro espaço encontrado.
        // Checar que cada pedaço começa com caractere maiúsculo, até năo haver mais espaço no termo.
		parte_corte = sequencia_nome.substr(0, sequencia_nome.find(" "));
		sequencia_nome = sequencia_nome.substr((sequencia_nome.find(" ") + 1), -1);

		caractere_inicial_corte = parte_corte[0];
		caractere_inicial_sequencia = sequencia_nome[0];

		if (((caractere_inicial_corte < (int)'A') || (caractere_inicial_corte > (int)'Z')) || ((caractere_inicial_sequencia < (int)'A') || (caractere_inicial_sequencia > (int)'Z')))
			throw invalid_argument("Argumento invalido.");
	}

	// Checar que cada ponto é precedido por letra.
	for (int i = 0; i < valor.size(); i++)
	{
	    // Se o primeiro caracter é um ponto, logicamente năo é precedido por letra.
		if (valor[i] == '.')
		{
			if (i == 0)
				throw invalid_argument("Argumento invalido.");

			if ((valor[i - 1] >= 'a') && (valor[i - 1] <= 'z'))
				continue;
			if ((valor[i - 1] >= 'A') && (valor[i - 1] <= 'Z '))
				continue;

			throw invalid_argument("Argumento invalido.");
		}
	}
}

void Nome::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Email::DEFAULT = "nome@dominio";
const string Email::DELIM = "@";

Email::Email()
{
	valor = DEFAULT;
}

void Email::validar(string valor)
{
	if (valor.find("..") != string::npos)
		throw invalid_argument("Argumento invalido.");

	string nomeEmail = valor.substr(0, valor.find(DELIM));
	string dominioEmail = valor.substr(valor.find(DELIM) + 1, -1);
	// String apenas com nome e domínio, sem delimitador, para checar formataçăo de caracteres.
	string emailSemDelimitador = nomeEmail + dominioEmail;

	// Se năo contém o delimitador @, năo segue o formato nome@dominio.
	if (valor.find(DELIM) == string::npos)
		throw invalid_argument("Argumento invalido.");

	if (nomeEmail.size() > LIMITE_NOME)
		throw invalid_argument("Argumento invalido.");

	if (dominioEmail.size() > LIMITE_DOMINIO)
		throw invalid_argument("Argumento invalido.");

    // Checar que cada caractere de domínio e nome é letra, dígito ou ponto.
	for (int i = 0; i < emailSemDelimitador.size(); i++) {
		if ((emailSemDelimitador[i] >= (int)'a') && (emailSemDelimitador[i] <= (int)'z'))
			continue;
		if ((emailSemDelimitador[i] >= (int)'A') && (emailSemDelimitador[i] <= (int)'Z'))
			continue;
		if ((emailSemDelimitador[i] >= (int)'0') && (emailSemDelimitador[i] <= (int)'9'))
			continue;
		if (emailSemDelimitador[i] == (int)'.')
			continue;

		throw invalid_argument("Argumento invalido.");
	}
}

void Email::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Senha::DEFAULT = "Aa1234";

Senha::Senha()
{
	valor = DEFAULT;
}

void Senha::validar(string valor)
{
	string valorChecagem = valor;

	// Checar que todo caractere é letra ou dígito.
	for (int i = 0; i < valor.size(); i++) {
		if ((valor[i] >= (int)'a') && (valor[i] <= (int)'z'))
			continue;
		if ((valor[i] >= (int)'A') && (valor[i] <= (int)'Z'))
			continue;
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			continue;

		throw invalid_argument("Argumento invalido.");
	}

	// Checar que năo existe caractere repetido.
	for (int i = 0; i < valor.size(); i++)
	{
		valorChecagem = valor;

		// Se depois de remover o primeiro caractere ainda restar outro caractere igual, há repetiçăo de caracteres.
		valorChecagem.replace(valorChecagem.find(valor[i]), 1, "");

		if (valorChecagem.find(valor[i]) != string::npos)
			throw invalid_argument("Argumento invalido.");
	}

	// Checar que senha tem pelo menos uma letra minúscula.
	for (int i = 0; i < valor.size(); i++)
	{
		if ((valor[i] >= (int)'a') && (valor[i] <= (int)'z'))
			break;

		if (i == (valor.size() - 1))
			throw invalid_argument("Argumento invalido.");
	}

	// Checar que senha tem pelo menos uma letra maiúscula.
	for (int i = 0; i < valor.size(); i++)
	{
		if ((valor[i] >= (int)'A') && (valor[i] <= (int)'Z'))
			break;

		if (i == (valor.size() - 1))
			throw invalid_argument("Argumento invalido.");
	}

	// Checar que senha tem pelo menos um dígito.
	for (int i = 0; i < valor.size(); i++)
	{
		if ((valor[i] >= (int)'0') && (valor[i] <= (int)'9'))
			break;

		if (i == (valor.size() - 1))
			throw invalid_argument("Argumento invalido.");
	}
}

void Senha::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}

const string Telefone::DEFAULT = "(123)-123456789";
const string Telefone::DDDPROIBIDO = "000";
const string Telefone::NUMEROPROIBIDO = "000000000";

Telefone::Telefone()
{
	valor = DEFAULT;
}

void Telefone::validar(string valor)
{
	string dddTelefone, numeroTelefone;

	// Se o valor dado năo seguir o formato (XXX)-XXXXXXXXX, é inválido.
	if ((valor[POSICAOCHAVESINICIO] != '(') || (valor[POSICAOCHAVESFIM] != ')') || (valor[POSICAOHIFEN] != '-'))
		throw invalid_argument("Argumento invalido.");

    // Separaçăo de telefone em DDD e número para simplificar checagens de formato.
	dddTelefone = valor.substr(POSICAOCHAVESINICIO + 1, POSICAOCHAVESFIM - 1);
	numeroTelefone = valor.substr(POSICAOHIFEN + 1, valor.size());

	// Checar que DD e número săo compostos apenas de dígitos.
	for (int i = 0; i < dddTelefone.size(); i++) {
		if ((dddTelefone[i] < (int)'0') || (dddTelefone[i] > (int)'9'))
			throw invalid_argument("Argumento invalido.");
	}

	for (int i = 0; i < numeroTelefone.size(); i++) {
		if ((numeroTelefone[i] < (int)'0') || (numeroTelefone[i] > (int)'9'))
			throw invalid_argument("Argumento invalido.");
	}

	if ((dddTelefone == DDDPROIBIDO) && (numeroTelefone == NUMEROPROIBIDO))
		throw invalid_argument("Argumento invalido.");
}

void Telefone::setValor(const string valor)
{
	validar(valor);
	this->valor = valor;
}
