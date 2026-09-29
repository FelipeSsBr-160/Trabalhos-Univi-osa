// Trabalho: Sistema Bancário - entrega 30/09/2026

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
 
int main() {
    
    cout << "*********************************************"<<endl;
    cout << "*************** SITEMA BANCARIO *************"<<endl;
    cout << "*********************************************"<<endl;
    
    
    
    
    //Declaração de Variáveis
    
    int opcao, novoTipo, numeroConta = 0, tipoConta = 0;      
    string nomeCliente, cpf;
    double saldo = 0.0;    
    bool   contaAtiva  = false;
    bool contaCadastrada = false;
    
    //Fixando ponto flutiante
    cout<< fixed << setprecision(2);
 
    // Menu + Execução
    
    do {
        
        cout << "1 - Cadastrar conta"<<endl;
        cout << "2 - Consultar conta"<<endl;
        cout << "3 - Verificar saldo"<<endl;
        cout << "4 - Alterar tipo da conta"<<endl;
        cout << "5 - Ativar/Desativar conta"<<endl;
        cout << "6 - Sair"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout <<""<<endl;
 
        switch (opcao) {
 
        // 1 - CADASTRAR
        case 1:
            if (contaCadastrada == true) {
                cout << "Atencao: os dados da conta anterior serao substituidos."<<endl;
            }
 
            // Número da conta: deve ser maior que zero
            do {
                cout << "O numero da conta deve ser maior que 0 (zero): ";
                cin >> numeroConta;
                if (numeroConta <= 0) {
                    cout << "Erro: o numero deve ser maior que zero."<<endl;
                }
            } while (numeroConta <= 0); // repete caso o numero seja
 
            cin.ignore();
 
            // Nome do titular 
            do {
                cout << "Nome do titular: ";
                getline(cin, nomeCliente);
                
                // não pode ficar vazio
                if (nomeCliente == "") {
                    cout << "Erro: o nome nao pode ser vazio."<<endl;
                }
            } while (nomeCliente == "");
 
            // O CPF precisa ter 11 caracteres
            do {
                cout << "CPF (11 digitos, somente numeros): ";
                getline(cin, cpf);
                if (cpf.length() != 11) {
                    cout << "Erro: o CPF deve ter 11 digitos."<<endl;
                }
            } while (cpf.length() != 11);
 
            // Tipo da conta 1 ou 2
            do {
                cout << "Tipo da conta (1 = Corrente; 2 = Poupanca): ";
                cin >> tipoConta;
                if (tipoConta != 1 && tipoConta != 2) {
                    cout << "Erro: o tipo deve ser 1 ou 2."<<endl;
                }
            } while (tipoConta != 1 && tipoConta != 2);
 
            // Saldo inicial não pode ser negativo
            do {
                cout << "Saldo inicial (deve ser maior ou igual a 0 (zero)): ";
                cin >> saldo;
                if (saldo < 0) {
                    cout << "Erro: o saldo inicial nao pode ser negativo."<<endl;
                }
            } while (saldo < 0);
 
            contaAtiva = true;        // a conta nasce ativa
            contaCadastrada = true;
            cout << "Conta cadastrada com sucesso!"<<endl;
            break;
 
        // 2 - CONSULTAR
        case 2:
            if (contaCadastrada == false) {
                cout << "Nenhuma conta cadastrada."<<endl;
            } else {
                cout<< endl << "--- Dados da conta ---"<<endl;
                cout << "Numero : " << numeroConta <<endl;
                cout << "Titular: " << nomeCliente <<endl;
                cout << "CPF    : " << cpf <<endl;
 
                if (tipoConta == 1) {
                    cout << "Tipo   : Corrente"<<endl;
                } else {
                    cout << "Tipo   : Poupanca"<<endl;
                }
 
                cout << "Saldo  : R$ " << saldo <<endl;
 
                if (contaAtiva == true) {
                    cout << "Status : Ativa"<<endl;
                } else {
                    cout << "Status : Inativa"<<endl;
                }
            }
            break;
 
        // 3 - VERIFICAR SALDO
        case 3:
            if (contaCadastrada == false) {
                cout << "Nenhuma conta cadastrada."<<endl;
            } else if (contaAtiva == false) {
                cout << "Operacao negada: a conta esta inativa."<<endl;
            } else {
                cout << "Saldo atual: R$ " << saldo <<endl;
            }
            break;
 
        // 4 - ALTERAR TIPO
        case 4:
            if (contaCadastrada == false) {
                cout << "Nenhuma conta cadastrada."<<endl;
            } else if (contaAtiva == false) {
                cout << "Operacao negada: a conta esta inativa."<<endl;
            } else {
                do {
                    cout << "Novo tipo (1 = Corrente; 2 = Poupanca): ";
                    cin >> novoTipo;
                    if (novoTipo != 1 && novoTipo != 2) {
                        cout << "Erro: o tipo deve ser 1 ou 2."<<endl;
                    }
                } while (novoTipo != 1 && novoTipo != 2);
 
                tipoConta = novoTipo;
                cout << "Tipo alterado com sucesso!"<<endl;
            }
            break;
 
        // 5 - ATIVAR/DESATIVAR
        case 5:
            if (contaCadastrada == false) {
                cout << "Nenhuma conta cadastrada."<<endl;
            } else {
                if (contaAtiva == true) {
                    contaAtiva = false;
                    cout << "Conta DESATIVADA com sucesso."<<endl;
                } else {
                    contaAtiva = true;
                    cout << "Conta ATIVADA com sucesso."<<endl;
                }
            }
            break;
 
        // 6 - SAIR
        case 6:
            cout << "Encerrando o sistema. Ate logo!"<<endl;
            break;
 
        default:
            cout << "Opcao invalida. Tente novamente."<<endl;
        }
 
    } while (opcao != 6);
 
    return 0;
}