#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos das classes controladoras da camada de apresentaçăo.


//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo controle.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Acessar sistema.";
    char texto3[]="b - Cadastrar usuario.";
    char texto4[]="c - Acessar dados sobre imoveis.";
    char texto5[]="d - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleçăo de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="a - Selecionar servicos de pessoal.";
    char texto8[]="b - Selecionar servicos relacionados a imoveis.";
    char texto9[]="c - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.

        noecho();
        campo = getch();                                                                   // Leitura do campo de entrada e conversăo de ASCII.
        echo();

        switch(campo){
            case 'a': if(cntrApresentacaoAutenticacao->autenticar(&email)){                         // Solicita autenticaçăo.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleçăo de serviço.

                            clear();                                                            // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleçăo de serviço.
                            noecho();
                            campo = getch();                                               // Leitura do campo de entrada e conversăo de ASCII.
                            echo();

                            switch(campo){
                                case 'a': cntrApresentacaoPessoal->executar(email);                 // Solicita serviço de pessoal.
                                        break;
                                case 'b': cntrApresentacaoImoveis->executar(email);     // Solicita serviço de produto financeiro.
                                        break;
                                case 'c': apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 'b': cntrApresentacaoPessoal->cadastrar();
                    break;
            case 'c': cntrApresentacaoImoveis->executar();
                    break;
            case 'd': apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo autenticaçăo.

bool CntrApresentacaoAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticaçăo.

    char texto1[]="Digite o e-mail: ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Senha senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autenticaçăo.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lę valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // Lę valor do campo.

        try{
            email->setValor(string(campo1));                                                      // Atribui valor ao Email.
            senha.setValor(string(campo2));                                                     // Atribui Valor ŕ senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceçăo devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lę caracter digitado.
            echo();
        }
    }
    return (cntr->autenticar(*email, senha));                                                     // Solicita serviço de autenticaçăo.
}

//--------------------------------------------------------------------------------------------
// Implementaçőes dos métodos da classe controladora apresentaçăo pessoal.

void CntrApresentacaoPessoal::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleçăo de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Editar dados da conta.";
    char texto3[]="b - Descadastrar conta.";
    char texto4[]="c - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selaçăo de serviço.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
        noecho();
        campo = getch();                                                                   // Leitura do campo de entrada e conversăo de ASCII.
        echo();

        switch(campo){
            case 'a': editar(email);
                    break;
            case 'b': descadastrar(email);
                    break;
            case 'c': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            : ";
    char texto3[] ="E-mail          : ";
    char texto4[] ="Senha           : ";
    char texto5[] ="Telefone        : ";
    char texto6[]="Dados em formato incorreto. Digite algo.";
    char texto7[]="Sucesso no cadastramento. Digite algo.";
    char texto8[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nome;
    Email email;
    Senha senha;
    Telefone telefone;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                         // Lę valor do campo.

    try{
        nome.setValor(string(campo1));
        email.setValor(string(campo2));
        senha.setValor(string(campo3));
        telefone.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setTelefone(telefone);

    // Cadastra usuário e conta.

    if(cntrServicoPessoal->cadastrarUsuario(usuario))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto7);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto8);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::editar(Email email){

    // Mensagens a serem apresentadas na tela de edição de dados de conta.

    char texto1[] ="Preencha os seguintes campos com as novas informacoes: ";
    char texto2[] ="Nome            : ";
    char texto3[] ="Senha           : ";
    char texto4[] ="Telefone        : ";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso na mudanca dos dados. Digite algo.";
    char texto7[]="Falha na mudanca dos dados. Digite algo.";

    char campo1[80], campo2[80], campo3[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Nome nomeNovo;
    Senha senhaNova;
    Telefone telefoneNovo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de edição.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lę valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                        // Lę valor do campo.

    try{
        nomeNovo.setValor(string(campo1));
        senhaNova.setValor(string(campo2));
        telefoneNovo.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 8,coluna/4,"%s",exp.what());
        mvprintw(linha/4 + 10,coluna/4,"%s",texto5);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Usuario usuarioAlterado;

    usuarioAlterado.setEmail(email);
    usuarioAlterado.setNome(nomeNovo);
    usuarioAlterado.setSenha(senhaNova);
    usuarioAlterado.setTelefone(telefoneNovo);

    // Edita usuário.

    if(cntrServicoPessoal->editarUsuario(usuarioAlterado))
    {
        mvprintw(linha/4 + 16,coluna/4,"%s",texto6);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 16,coluna/4,"%s",texto7);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoPessoal::descadastrar(Email email){

    // Mensagens a serem apresentadas na tela de edição de descadastramento de conta.

    char texto1[]="Sucesso no descadastramento de usuario. Digite algo.";
    char texto2[]="Falha no descadastramento de usuario. Digite algo.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);

    // Descadastra usuário.

    if(cntrServicoPessoal->descadastrarUsuario(email))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto1);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto2);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoImoveis::executar(){

    // Mensagens a serem apresentadas na tela simplificada de serviços relacionados a imóveis, para usuários não autenticados.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="a - Listar imoveis.";
    char texto3[]="b - Consultar imovel.";
    char texto4[]="c - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela simplificada de imóveis.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.

        noecho();
        campo = getch();                                                                        // Leitura do campo de entrada.
        echo();

        switch(campo){
            case 'a': listarImoveis();
                    break;
            case 'b': consultarImovel();
                    break;
            case 'c': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoImoveis::executar(Email email){

    // Mensagens a serem apresentadas tela completa de serviços relacionados a imóveis.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="a - Listar imoveis.";
    char texto3[] ="b - Consultar imovel.";
    char texto4[] ="c - Cadastrar imovel.";
    char texto5[] ="d - Editar imovel.";
    char texto6[] ="e - Descadastrar imovel.";
    char texto7[] ="f - Listar propostas de imovel.";
    char texto8[] ="g - Cadastrar proposta.";
    char texto9[] ="h - Listar propostas feitas.";
    char texto10[] ="i - Consultar proposta feita.";
    char texto11[] = "j - Descadastrar proposta feita.";
    char texto12[] ="k - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de imóveis.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/6,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/6 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/6 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 16,coluna/4,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/6 + 18,coluna/4,"%s",texto10);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 20,coluna/4,"%s",texto11);                                           // Imprime nome do campo.
        mvprintw(linha/6 + 22,coluna/4,"%s",texto12);                                           // Imprime nome do campo.

        noecho();
        campo = getch();                                                                         // Leitura do campo de entrada.
        echo();

        switch(campo){
            case 'a': listarImoveis();
                    break;
            case 'b': consultarImovel();
                    break;
            case 'c': cadastrarImovel(email);
                    break;
            case 'd': editarImovel(email);
                    break;
            case 'e': descadastrarImovel(email);
                    break;
            case 'f': listarPropostasDeImovel(email);
                    break;
            case 'g': cadastrarProposta(email);
                    break;
            case 'h': listarPropostas(email);
                    break;
            case 'i': consultarProposta(email);
                    break;
            case 'j': descadastrarProposta(email);
                    break;
            case 'k': apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoImoveis::cadastrarImovel(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de imóvel.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Classe                                       : ";
    char texto3[] ="Descricao                                    : ";
    char texto4[] ="Endereco                                     : ";
    char texto5[] ="Numero maximo de hospedes                    : ";
    char texto6[] ="Data inicial do periodo de disponibilidade   : ";
    char texto7[] ="Data final do periodo de disponibilidade     : ";
    char texto8[] ="Valor de diaria                              : ";
    char texto9[]="Dados em formato incorreto. Digite algo.";
    char texto10[]="Sucesso no cadastramento. Digite algo.";
    char texto11[]="Falha no cadastramento. Digite algo.";

    // Cria campos para entrada dos dados.
    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80], campo7[80];

    // Instancia os domínios.
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Numero hospedes;
    Data dataInicial;
    Data dataFinal;
    Moeda valorDiaria;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.

    try{
        classe.setValor(atoi(campo1));
        descricao.setValor(string(campo2));
        endereco.setValor(string(campo3));
        hospedes.setValor(atoi(campo4));
        dataInicial.setValor(string(campo5));
        dataFinal.setValor(string(campo6));
        valorDiaria.setValor(string(campo7));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 16,coluna/4,"%s",texto9);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade.

    Imovel imovel;

    imovel.setClasse(classe);
    imovel.setDescricao(descricao);
    imovel.setEndereco(endereco);
    imovel.setHospedes(hospedes);
    imovel.setDataInicial(dataInicial);
    imovel.setDataFinal(dataFinal);
    imovel.setValor(valorDiaria);

    // Cadastra imóvel.

    if(cntr->cadastrarImovel(imovel, email))
    {
        mvprintw(linha/4 + 16,coluna/4,"%s",texto10);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 16,coluna/4,"%s",texto11);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::consultarImovel(){

    // Mensagens a serem apresentadas na tela de consulta a imóvel.

    char texto1[] ="Digite o codigo do imovel que quer consultar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da consulta ao imovel.";
    char texto4[]="Falha na consulta do imovel. Digite algo.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    clear();

    char campo1[80];

    mvprintw(linha/4, coluna/4, "%s", texto1);                                                 // Imprime nome do campo.
    getstr(campo1);


    // Instancia os domínios.

    Codigo codigoImovel;

    try{
        codigoImovel.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4, "%s", texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia os domínios e entidades;

    Imovel imovelConsultado;
    Email emailUsuario;

    // Mensagens das linhas da consulta.

    string textoCodigo, textoClasse, textoDescricao, textoEndereco;
    string textoDataInicial, textoDataFinal, textoHospedes, textoValor, textoEmail;

    imovelConsultado.setCodigo(codigoImovel);

    //  Faz a consulta e imprime o resultado.

    if(cntr->consultarImovel(&imovelConsultado, &emailUsuario))
    {
        textoCodigo = "Codigo: " + imovelConsultado.getCodigo().getValor();
        textoClasse = "Classe: " + to_string(imovelConsultado.getClasse().getValor());
        textoDescricao = "Descricao: " + imovelConsultado.getDescricao().getValor();
        textoEndereco = "Endereco: " + imovelConsultado.getEndereco().getValor();
        textoDataInicial = "Data inicial: " + imovelConsultado.getDataInicial().getValor();
        textoDataFinal = "Data final: " + imovelConsultado.getDataFinal().getValor();
        textoHospedes = "Hospedes: " + to_string(imovelConsultado.getHospedes().getValor());
        textoValor = "Valor: " + imovelConsultado.getValor().getValor();
        textoEmail = "Email do anunciante: " + emailUsuario.getValor();

        clear();

        mvprintw(linha/4,coluna/4,"%s",textoCodigo.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",textoClasse.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",textoDescricao.c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s",textoEndereco.c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s",textoDataInicial.c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s",textoDataFinal.c_str());
        mvprintw(linha/4 + 12,coluna/4,"%s",textoHospedes.c_str());
        mvprintw(linha/4 + 14,coluna/4,"%s",textoValor.c_str());
        mvprintw(linha/4 + 16,coluna/4,"%s",textoEmail.c_str());

        mvprintw(linha/4 + 20,coluna/4,"%s", texto3);

        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::descadastrarImovel(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de imóvel.

    char texto1[] ="Digite o codigo do imovel que quer descadastrar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Sucesso no descadastramento de imovel. Digite algo.";
    char texto4[]="Falha no descadastramento de imovel. Digite algo.";

    char campo1[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    if(cntr->descadastrarImovel(codigo, email))
    {
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::listarImoveis(){

    // Mensagens a serem apresentadas na tela de listagem de imóveis.

    char texto1[] ="Falha na listagem de imoveis. Digite algo.";
    char texto2[] ="Digite algo para sair da listagem.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);

    clear();

    int linhaAcumulada = 0;
    int contagemImovel = 1;

    // Instancia o texto das linhas e a lista de imóveis a ser exibida.

    string textoImovel;
    list<Imovel> listaImoveis;

    string cabecalho = "N.     Codigo     Classe     Data inicial     Data final     Valor";                   // Cabeçalho da lista.

    // Lista os imóveis cadastrados no programa.

    if(cntr->listarImoveis(&listaImoveis))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        for(list<Imovel>::iterator imovel = listaImoveis.begin(); imovel != listaImoveis.end(); imovel++){

            textoImovel = to_string(contagemImovel) + ":     " + imovel->getCodigo().getValor();
            textoImovel += "      " + to_string(imovel->getClasse().getValor());
            textoImovel += "          " + imovel->getDataInicial().getValor();
            textoImovel += "         " + imovel->getDataFinal().getValor();
            textoImovel += "       " + imovel->getValor().getValor();

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoImovel.c_str());
            linhaAcumulada++;
            contagemImovel++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto2);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}

void CntrApresentacaoImoveis::editarImovel(Email email){

    // Mensagens a serem apresentadas na tela de edição de dados de imóvel.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Codigo                                       : ";
    char texto3[] ="Classe                                       : ";
    char texto4[] ="Descricao                                    : ";
    char texto5[] ="Endereco                                     : ";
    char texto6[] ="Numero maximo de hospedes                    : ";
    char texto7[] ="Data inicial do periodo de disponibilidade   : ";
    char texto8[] ="Data final do periodo de disponibilidade     : ";
    char texto9[] ="Valor de diaria minimo                       : ";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso na edicao dos dados do imovel. Digite algo.";
    char texto12[]="Falha na edicao dos dados do imovel. Digite algo.";

    // Campos a serem preenchidos pelo usuário.

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80], campo7[80], campo8[80];
                               // Cria campos para entrada dos dados.
    // Instancia os domínios.

    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Numero hospedes;
    Data dataInicial;
    Data dataFinal;
    Moeda valorDiaria;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de edição de imóvel.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                                // Imprime nome do campo.
    getstr(campo7);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 16,coluna/4,"%s",texto9);                                                // Imprime nome do campo.
    getstr(campo8);                                                                             // Lê valor do campo.

    try{
        codigo.setValor(string(campo1));
        classe.setValor(atoi(campo2));
        descricao.setValor(string(campo3));
        endereco.setValor(string(campo4));
        hospedes.setValor(atoi(campo5));
        dataInicial.setValor(string(campo6));
        dataFinal.setValor(string(campo7));
        valorDiaria.setValor(string(campo8));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 18,coluna/4,"%s",texto10);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Imovel imovel;

    imovel.setCodigo(codigo);
    imovel.setClasse(classe);
    imovel.setDescricao(descricao);
    imovel.setEndereco(endereco);
    imovel.setHospedes(hospedes);
    imovel.setDataInicial(dataInicial);
    imovel.setDataFinal(dataFinal);
    imovel.setValor(valorDiaria);

    // Edita imóvel.

    if(cntr->editarImovel(imovel, email))
    {
        mvprintw(linha/4 + 18,coluna/4,"%s",texto11);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 18,coluna/4,"%s",texto12);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::cadastrarProposta(Email email){

    // Mensagens a serem apresentadas na tela de cadastramento de proposta.

    char texto1[] ="Preencha os seguintes campos:  ";
    char texto2[] ="Codigo do imovel                     : ";
    char texto3[] ="Data inicial do periodo de aluguel   : ";
    char texto4[] ="Data final do periodo de aluguel     : ";
    char texto5[] ="Numero de hospedes                   : ";
    char texto6[] ="Valor de diaria                      : ";
    char texto7[]="Dados em formato incorreto. Digite algo.";
    char texto8[]="Sucesso no cadastramento. Digite algo.";
    char texto9[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;
    Data dataInicial;
    Data dataFinal;
    Numero hospedes;
    Moeda valorDiaria;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento de proposta.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.

    try{
        codigo.setValor(string(campo1));
        dataInicial.setValor(string(campo2));
        dataFinal.setValor(string(campo3));
        hospedes.setValor(atoi(campo4));
        valorDiaria.setValor(string(campo5));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidades.

    Proposta proposta;

    proposta.setDataInicial(dataInicial);
    proposta.setDataFinal(dataFinal);
    proposta.setHospedes(hospedes);
    proposta.setValor(valorDiaria);

    // Cadastra proposta.

    if(cntr->cadastrarProposta(proposta, email, codigo))
    {
        mvprintw(linha/4 + 12,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 12,coluna/4,"%s",texto9);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::consultarProposta(Email email){

    // Mensagens a serem apresentadas na tela de consulta a proposta.

    char texto1[] ="Digite o codigo da proposta que quer consultar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da consulta da proposta.";
    char texto4[]="Falha na consulta da proposta. Digite algo.";


    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    clear();

    char campo1[80];

    mvprintw(linha/4, coluna/4, "%s", texto1);                                                 // Imprime nome do campo.
    getstr(campo1);

    Codigo codigoProposta;

    try{
        codigoProposta.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4, "%s", texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia domínios e entidades.

    Proposta propostaConsultada;
    Email emailProposta;
    Codigo codigoImovel;

    // Mensagens a serem exibidas na consulta a proposta.

    string textoCodigo, textoDataInicial, textoDataFinal, textoHospedes;
    string textoValor, textoEmail, textoCodigoImovel;

    propostaConsultada.setCodigo(codigoProposta);

    // Apresenta tela de consulta da proposta pedida.

    if(cntr->consultarProposta(email, &propostaConsultada, &emailProposta, &codigoImovel))
    {
        textoCodigo = "Codigo: " + propostaConsultada.getCodigo().getValor();
        textoDataInicial = "Data inicial: " + propostaConsultada.getDataInicial().getValor();
        textoDataFinal = "Data final: " + propostaConsultada.getDataFinal().getValor();
        textoHospedes = "Hospedes: " + to_string(propostaConsultada.getHospedes().getValor());
        textoValor = "Valor: " + propostaConsultada.getValor().getValor();
        textoEmail = "Email do anunciante: " + emailProposta.getValor();
        textoCodigoImovel = "Codigo do imovel: " + codigoImovel.getValor();

        clear();

        mvprintw(linha/4,coluna/4,"%s",textoCodigo.c_str());
        mvprintw(linha/4 + 2,coluna/4,"%s",textoDataInicial.c_str());
        mvprintw(linha/4 + 4,coluna/4,"%s",textoDataFinal.c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s",textoHospedes.c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s",textoValor.c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s",textoEmail.c_str());
        mvprintw(linha/4 + 12,coluna/4,"%s",textoCodigoImovel.c_str());

        mvprintw(linha/4 + 14,coluna/4,"%s", texto3);

        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 2,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::descadastrarProposta(Email email){

    // Mensagens a serem apresentadas na tela de descadastramento de proposta.

    char texto1[] ="Digite o codigo da proposta que quer descadastrar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Sucesso no descadastramento da proposta. Digite algo.";
    char texto4[]="Falha no descadastramento da proposta. Digite algo.";

    // Cria campos para entrada dos dados.

    char campo1[80];

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de descadastramento de proposta.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);                                                                             // Lę valor do campo.

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    if(cntr->descadastrarProposta(codigo, email))
    {
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4 + 4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrApresentacaoImoveis::listarPropostas(Email email){

    // Mensagens a serem apresentadas na tela de listagem de propostas.

    char texto1[] ="Falha na listagem de propostas. Digite algo.";
    char texto2[] ="Digite algo para sair da listagem.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);

    clear();

    int linhaAcumulada = 0;
    int contagemProposta = 1;

    // Instancia as listas de propostas a serem exibidas.

    string textoProposta;
    list<Proposta> listaPropostas;
    list<Codigo> listaCodigosImoveis;

    string cabecalho = "N.     Codigo     Imovel     Data inicial     Data final     Valor";                        // Cabeçalho da lista de propostas.

    // Apresenta tela de listagem de propostas.

    if(cntr->listarPropostas(email, &listaPropostas, &listaCodigosImoveis))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        list<Codigo>::iterator codigoImovel = listaCodigosImoveis.begin();

        for(list<Proposta>::iterator proposta = listaPropostas.begin(); proposta != listaPropostas.end(); proposta++){

            textoProposta = to_string(contagemProposta) + ":     " + proposta->getCodigo().getValor();
            textoProposta += "      " + codigoImovel->getValor();
            textoProposta += "      " + proposta->getDataInicial().getValor();
            textoProposta += "         " + proposta->getDataFinal().getValor();
            textoProposta += "       " + proposta->getValor().getValor();

            codigoImovel++;

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoProposta.c_str());
            linhaAcumulada++;
            contagemProposta++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto2);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}

void CntrApresentacaoImoveis::listarPropostasDeImovel(Email email){

    // Mensagens a serem apresentadas na tela de listagem de propostas de determinado imóvel.

    char texto1[] ="Digite o codigo do imovel cujas propostas quer listar:  ";
    char texto2[]="Dados em formato incorreto. Digite algo.";
    char texto3[]="Digite algo para sair da listagem.";
    char texto4[]="Falha na listagem. Digite algo.";

    char campo1[80];                           // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Codigo codigo;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de requisição de código do imóvel cujas propostas vão ser listadas.

    clear();                                                                                    // Limpa janela.

    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    getstr(campo1);

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    clear();

    int linhaAcumulada = 0;
    int contagemProposta = 1;

    // Instancia a lista de propostas.

    string textoProposta;
    list<Proposta> listaPropostas;
    list<Codigo> listaCodigosImoveis;

    string cabecalho = "N.     Codigo     Imovel     Data inicial     Data final     Valor";                // Cabeçalho da lista de propostas.

    // Apresenta tela com as propostas listadas do imóvel dado.

    if(cntr->listarPropostasDeImovel(email, codigo, &listaPropostas, &listaCodigosImoveis))
    {
        mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", cabecalho.c_str());
        linhaAcumulada += 2;

        list<Codigo>::iterator codigoImovel = listaCodigosImoveis.begin();

        for(list<Proposta>::iterator proposta = listaPropostas.begin(); proposta != listaPropostas.end(); proposta++){

            textoProposta = to_string(contagemProposta) + ":     " + proposta->getCodigo().getValor();
            textoProposta += "      " + codigoImovel->getValor();
            textoProposta += "      " + proposta->getDataInicial().getValor();
            textoProposta += "         " + proposta->getDataFinal().getValor();
            textoProposta += "       " + proposta->getValor().getValor();

            codigoImovel++;

            mvprintw(linha/4 + linhaAcumulada,coluna/4, "%s", textoProposta.c_str());
            linhaAcumulada++;
            contagemProposta++;
        }

        linhaAcumulada++;
        mvprintw(linha/4 + linhaAcumulada,coluna/4,"%s",texto3);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }

    mvprintw(linha/4,coluna/4,"%s",texto4);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;

}
