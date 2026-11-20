#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// CONSTANTES E ARRAYS - DADOS DAS CONTAS
// (declarados fora do main para que as funcoes de arquivo tambem possam usa-los)
const int MAX_CONTAS = 100;
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];
int quantidadeContas = 0;

// CONSTANTES E ARRAYS - MOVIMENTACOES
const int MAX_MOVIMENTACOES = 500;
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];
int quantidadeMovimentacoes = 0;

// FUNCAO - SALVAR CONTAS
// Grava todas as contas dos arrays no arquivo contas.txt (um registro por linha)
void salvarContas() {
    // Sem ios::app: o arquivo e reescrito por completo com os dados atuais dos arrays
    ofstream arquivo("contas.txt");

    if (arquivo.is_open()) {
        // Garante o saldo com 2 casas decimais no arquivo (ex: 700.00)
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeContas; i++) {
            arquivo << numeroConta[i] << ";"
                    << nomeCliente[i] << ";"
                    << cpf[i] << ";"
                    << tipoConta[i] << ";"
                    << saldo[i] << ";"
                    << contaAtiva[i] << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro: nao foi possivel abrir o arquivo contas.txt para gravacao." << endl;
    }
}

// FUNCAO - SALVAR MOVIMENTACOES
// Grava todo o historico de movimentacoes no arquivo movimentacoes.txt
void salvarMovimentacoes() {
    ofstream arquivo("movimentacoes.txt");

    if (arquivo.is_open()) {
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeMovimentacoes; i++) {
            arquivo << contaMovimentacao[i] << ";"
                    << tipoMovimentacao[i] << ";"
                    << valorMovimentacao[i] << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro: nao foi possivel abrir o arquivo movimentacoes.txt para gravacao." << endl;
    }
}

// FUNCAO - CARREGAR CONTAS
// Le o arquivo contas.txt e preenche os arrays de contas e a variavel quantidadeContas
void carregarContas() {
    ifstream arquivo("contas.txt");

    // Se o arquivo nao existe (primeira execucao), o sistema inicia sem contas
    if (!arquivo.is_open()) {
        return;
    }

    string linha;
    string campos[6];   // numero, nome, cpf, tipo, saldo, situacao
    int posicao;

    // Cada repeticao le uma linha do arquivo (uma conta)
    while (quantidadeContas < MAX_CONTAS && getline(arquivo, linha)) {
        if (linha == "") {
            continue;   // ignora linhas em branco
        }

        // Separa os 6 campos usando o ponto e virgula como delimitador
        for (int c = 0; c < 5; c++) {
            posicao = linha.find(';');
            campos[c] = linha.substr(0, posicao);   // texto antes do ';'
            linha = linha.substr(posicao + 1);      // descarta o campo ja lido
        }
        campos[5] = linha;   // o que sobrou e o ultimo campo

        // Converte os textos lidos e guarda nos arrays
        numeroConta[quantidadeContas] = stoi(campos[0]);
        nomeCliente[quantidadeContas] = campos[1];
        cpf[quantidadeContas] = campos[2];
        tipoConta[quantidadeContas] = stoi(campos[3]);
        saldo[quantidadeContas] = stod(campos[4]);
        contaAtiva[quantidadeContas] = (campos[5][0] == '1');

        quantidadeContas++;
    }
    arquivo.close();
}

// FUNCAO - CARREGAR MOVIMENTACOES
// Le o arquivo movimentacoes.txt e preenche os arrays do historico
void carregarMovimentacoes() {
    ifstream arquivo("movimentacoes.txt");

    // Se o arquivo nao existe (primeira execucao), o historico comeca vazio
    if (!arquivo.is_open()) {
        return;
    }

    string linha;
    string campoConta, campoTipo, campoValor;
    int posicao;

    while (quantidadeMovimentacoes < MAX_MOVIMENTACOES && getline(arquivo, linha)) {
        if (linha == "") {
            continue;
        }

        // Formato da linha: conta;tipo;valor
        posicao = linha.find(';');
        campoConta = linha.substr(0, posicao);
        linha = linha.substr(posicao + 1);

        posicao = linha.find(';');
        campoTipo = linha.substr(0, posicao);
        campoValor = linha.substr(posicao + 1);

        contaMovimentacao[quantidadeMovimentacoes] = stoi(campoConta);
        tipoMovimentacao[quantidadeMovimentacoes] = campoTipo[0];
        valorMovimentacao[quantidadeMovimentacoes] = stod(campoValor);

        quantidadeMovimentacoes++;
    }
    arquivo.close();
}

int main() {
    // Configuracao de ponto flutuante para exibicao de valores monetarios
    cout << fixed << setprecision(2);

    // Variaveis 
    int opcao;
    int numBusca, numDestino;
    int indiceEncontrado, indiceOrigem, indiceDestino;
    double valorOperacao;

    // CARREGAMENTO DOS DADOS SALVOS (contas.txt e movimentacoes.txt)
    carregarContas();
    carregarMovimentacoes();

    cout << "**********************************************" << endl;
    cout << "*************** SISTEMA BANCARIO *************" << endl;
    cout << "**********************************************" << endl;
    cout << "Dados carregados: " << quantidadeContas << " conta(s) e "
         << quantidadeMovimentacoes << " movimentacao(oes)." << endl;

    // Menu principal + Execucao 
    do {
        cout << "\n1 - Cadastrar conta" << endl;
        cout << "2 - Listar as contas cadastradas" << endl;
        cout << "3 - Consultar uma conta pelo numero" << endl;
        cout << "4 - Realizar deposito" << endl;
        cout << "5 - Realizar saque" << endl;
        cout << "6 - Realizar transferencia" << endl;
        cout << "7 - Exibir o extrato de uma conta" << endl;
        cout << "8 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << "" << endl;

        switch (opcao) {

            // 1 - CADASTRAR CONTA
            case 1:
                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Erro: Limite maximo de contas atingido (" << MAX_CONTAS << ")." << endl;
                    break;
                }

                int novoNumero;
                bool numeroDuplicado;

                // Validacao do numero da conta (maior que 0 e unico)
                do {
                    numeroDuplicado = false;
                    cout << "O numero da conta deve ser maior que 0 (zero): ";
                    cin >> novoNumero;

                    if (novoNumero <= 0) {
                        cout << "Erro: o numero deve ser maior que zero." << endl;
                        numeroDuplicado = true;
                        continue;
                    }

                    // Verifica se o numero informado ja foi cadastrado em outra conta
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == novoNumero) {
                            cout << "Erro: Este numero de conta ja esta cadastrado." << endl;
                            numeroDuplicado = true;
                            break;
                        }
                    }
                } while (numeroDuplicado);

                numeroConta[quantidadeContas] = novoNumero;
                cin.ignore();

                // Nome do titular 
                do {
                    cout << "Nome do titular: ";
                    getline(cin, nomeCliente[quantidadeContas]);
                    if (nomeCliente[quantidadeContas] == "") {
                        cout << "Erro: o nome nao pode ser vazio." << endl;
                    } else if (nomeCliente[quantidadeContas].find(';') != string::npos) {
                        // O ';' separa os campos no arquivo, entao nao pode fazer parte do nome
                        cout << "Erro: o nome nao pode conter ponto e virgula (;)." << endl;
                    }
                } while (nomeCliente[quantidadeContas] == "" || nomeCliente[quantidadeContas].find(';') != string::npos);

                // CPF 
                do {
                    cout << "CPF (11 digitos, somente numeros): ";
                    getline(cin, cpf[quantidadeContas]);
                    if (cpf[quantidadeContas].length() != 11) {
                        cout << "Erro: o CPF deve ter 11 digitos." << endl;
                    } else if (cpf[quantidadeContas].find(';') != string::npos) {
                        cout << "Erro: o CPF nao pode conter ponto e virgula (;)." << endl;
                    }
                } while (cpf[quantidadeContas].length() != 11 || cpf[quantidadeContas].find(';') != string::npos);

                // Tipo de conta 1 ou 2
                do {
                    cout << "Tipo da conta (1 = Corrente; 2 = Poupanca): ";
                    cin >> tipoConta[quantidadeContas];
                    if (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                        cout << "Erro: o tipo deve ser 1 ou 2." << endl;
                    }
                } while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2);

                // Saldo inicial (nao-negativo)
                do {
                    cout << "Saldo inicial (deve ser maior ou igual a 0 (zero)): ";
                    cin >> saldo[quantidadeContas];
                    if (saldo[quantidadeContas] < 0) {
                        cout << "Erro: o saldo inicial nao pode ser negativo." << endl;
                    }
                } while (saldo[quantidadeContas] < 0);

                contaAtiva[quantidadeContas] = true; 
                quantidadeContas++;

                // Grava a nova conta no arquivo
                salvarContas();

                cout << "Conta cadastrada com sucesso!" << endl;
                break;

            // 2 - LISTAR AS CONTAS CADASTRADAS
            case 2:
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                } else {
                    cout << "--- LISTAGEM DE CONTAS ---" << endl;
                    for (int i = 0; i < quantidadeContas; i++) {
                        cout << "Conta: " << numeroConta[i] 
                             << " | Titular: " << nomeCliente[i] 
                             << " | Saldo: R$ " << saldo[i] 
                             << " | Status: " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
                    }
                }
                break;

            // 3 - CONSULTAR UMA CONTA PELO NUMERO
            case 3:
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                cout << "Digite o numero da conta para consulta: ";
                cin >> numBusca;

                indiceEncontrado = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numBusca) {
                        indiceEncontrado = i;
                        break;
                    }
                }

                if (indiceEncontrado == -1) {
                    cout << "Erro: Conta nao encontrada." << endl;
                } else {
                    cout << endl << "--- Dados da conta ---" << endl;
                    cout << "Numero : " << numeroConta[indiceEncontrado] << endl;
                    cout << "Titular: " << nomeCliente[indiceEncontrado] << endl;
                    cout << "CPF    : " << cpf[indiceEncontrado] << endl;
                    cout << "Tipo   : " << (tipoConta[indiceEncontrado] == 1 ? "Corrente" : "Poupanca") << endl;
                    cout << "Saldo  : R$ " << saldo[indiceEncontrado] << endl;
                    cout << "Status : " << (contaAtiva[indiceEncontrado] ? "Ativa" : "Inativa") << endl;
                }
                break;

            // 4 - REALIZAR DEPOSITO
            case 4:
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Erro: Historico de movimentacoes cheio." << endl;
                    break;
                }

                cout << "Digite o numero da conta para deposito: ";
                cin >> numBusca;

                indiceEncontrado = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numBusca) {
                        indiceEncontrado = i;
                        break;
                    }
                }

                if (indiceEncontrado == -1) {
                    cout << "Erro: Conta nao encontrada." << endl;
                } else if (!contaAtiva[indiceEncontrado]) {
                    cout << "Operacao negada: a conta esta inativa." << endl;
                } else {
                    do {
                        cout << "Digite o valor do deposito (deve ser positivo): ";
                        cin >> valorOperacao;
                        if (valorOperacao <= 0) {
                            cout << "Erro: O valor deve ser maior que zero." << endl;
                        }
                    } while (valorOperacao <= 0);

                    // Atualiza o saldo e registra no historico
                    saldo[indiceEncontrado] += valorOperacao;
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceEncontrado];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valorOperacao;
                    quantidadeMovimentacoes++;

                    // Grava o novo saldo e a movimentacao nos arquivos
                    salvarContas();
                    salvarMovimentacoes();

                    cout << "Deposito realizado com sucesso!" << endl;
                }
                break;

            // 5 - REALIZAR SAQUE
            case 5:
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Erro: Historico de movimentacoes cheio." << endl;
                    break;
                }

                cout << "Digite o numero da conta para saque: ";
                cin >> numBusca;

                indiceEncontrado = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numBusca) {
                        indiceEncontrado = i;
                        break;
                    }
                }

                if (indiceEncontrado == -1) {
                    cout << "Erro: Conta nao encontrada." << endl;
                } else if (!contaAtiva[indiceEncontrado]) {
                    cout << "Operacao negada: a conta esta inativa." << endl;
                } else {
                    do {
                        cout << "Digite o valor do saque (deve ser positivo): ";
                        cin >> valorOperacao;
                        if (valorOperacao <= 0) {
                            cout << "Erro: O valor deve ser maior que zero." << endl;
                        }
                    } while (valorOperacao <= 0);

                    // Validacao de saldo suficiente
                    if (saldo[indiceEncontrado] < valorOperacao) {
                        cout << "Operacao negada: Saldo insuficiente. Saldo atual: R$ " << saldo[indiceEncontrado] << endl;
                    } else {
                        // Atualiza o saldo e registra no historico
                        saldo[indiceEncontrado] -= valorOperacao;
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceEncontrado];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valorOperacao;
                        quantidadeMovimentacoes++;

                        // Grava o novo saldo e a movimentacao nos arquivos
                        salvarContas();
                        salvarMovimentacoes();

                        cout << "Saque realizado com sucesso!" << endl;
                    }
                }
                break;

            // 6 - REALIZAR TRANSFERENCIA
            case 6:
                // A transferencia precisa de espaco para 2 registros no historico simultaneamente
                if (quantidadeMovimentacoes + 1 >= MAX_MOVIMENTACOES) {
                    cout << "Erro: Espaco insuficiente no historico de movimentacoes para esta operacao." << endl;
                    break;
                }

                cout << "Digite o numero da conta de ORIGEM: ";
                cin >> numBusca;
                cout << "Digite o numero da conta de DESTINO: ";
                cin >> numDestino;

                indiceOrigem = -1;
                indiceDestino = -1;

                // Localiza ambas as contas nos arrays
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numBusca) indiceOrigem = i;
                    if (numeroConta[i] == numDestino) indiceDestino = i;
                }

                if (indiceOrigem == -1) {
                    cout << "Erro: Conta de origem nao encontrada." << endl;
                } else if (indiceDestino == -1) {
                    cout << "Erro: Conta de destino nao encontrada." << endl;
                } else if (!contaAtiva[indiceOrigem]) {
                    cout << "Operacao negada: A conta de origem esta inativa." << endl;
                } else if (!contaAtiva[indiceDestino]) {
                    cout << "Operacao negada: A conta de destino esta inativa." << endl;
                } else if (indiceOrigem == indiceDestino) {
                    cout << "Erro: Nao e possivel transferir para a propria conta." << endl;
                } else {
                    do {
                        cout << "Digite o valor da transferencia (deve ser positivo): ";
                        cin >> valorOperacao;
                        if (valorOperacao <= 0) {
                            cout << "Erro: O valor deve ser maior que zero." << endl;
                        }
                    } while (valorOperacao <= 0);

                    // Validacao do saldo da conta origem
                    if (saldo[indiceOrigem] < valorOperacao) {
                        cout << "Operacao negada: Saldo de origem insuficiente. Saldo atual: R$ " << saldo[indiceOrigem] << endl;
                    } else {
                        // Deduz do saldo de origem e adiciona no destino
                        saldo[indiceOrigem] -= valorOperacao;
                        saldo[indiceDestino] += valorOperacao;

                        // Grava registro de Saida 'S' (Origem)
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valorOperacao;
                        quantidadeMovimentacoes++;

                        // Grava registro de Entrada 'D' (Destino)
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valorOperacao;
                        quantidadeMovimentacoes++;

                        // Grava os dois novos saldos e as duas movimentacoes nos arquivos
                        salvarContas();
                        salvarMovimentacoes();

                        cout << "Transferencia de R$ " << valorOperacao << " realizada com sucesso de " 
                             << nomeCliente[indiceOrigem] << " para " << nomeCliente[indiceDestino] << "!" << endl;
                    }
                }
                break;

            // 7 - EXIBIR O EXTRATO DE UMA CONTA
            case 7:
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                    break;
                }

                cout << "Digite o numero da conta para ver o extrato: ";
                cin >> numBusca;

                indiceEncontrado = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numBusca) {
                        indiceEncontrado = i;
                        break;
                    }
                }

                if (indiceEncontrado == -1) {
                    cout << "Erro: Conta nao encontrada." << endl;
                } else {
                    cout << endl << "--- EXTRATO DA CONTA: " << numeroConta[indiceEncontrado] << " ---" << endl;
                    cout << "Titular: " << nomeCliente[indiceEncontrado] << endl;
                    cout << "---------------------------------------" << endl;

                    int contadorMov = 0;
                    // Percorre o historico filtrando pelas movimentacoes pertencentes a conta consultada
                    for (int i = 0; i < quantidadeMovimentacoes; i++) {
                        if (contaMovimentacao[i] == numeroConta[indiceEncontrado]) {
                            if (tipoMovimentacao[i] == 'D') {
                                cout << " (+) Deposito     : R$ " << valorMovimentacao[i] << endl;
                            } else if (tipoMovimentacao[i] == 'S') {
                                cout << " (-) Saque/Transf : R$ " << valorMovimentacao[i] << endl;
                            }
                            contadorMov++;
                        }
                    }

                    if (contadorMov == 0) {
                        cout << "Nenhuma movimentacao registrada para esta conta." << endl;
                    }
                    cout << "---------------------------------------" << endl;
                    cout << "Saldo Atual       : R$ " << saldo[indiceEncontrado] << endl;
                }
                break;

            // 8 - SAIR
            case 8:
                cout << "Encerrando o sistema. Ate logo!" << endl;
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 8);

    return 0;
}