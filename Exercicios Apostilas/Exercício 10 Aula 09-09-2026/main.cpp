#include <iostream>

using namespace std;


int main()
{
    cout<<"**************************************************"<<endl;
    cout<<"*****************ACESSO PRIORITARIO***************"<<endl;
    cout<<"**************************************************"<<endl;
    
    //Declaração de variaveis
    double idade;
    int condicao;
    
    //Entrada de dados
    cout<<"Informe  a idade: ";
    cin>>idade;
    cout<<"O cliente possui alguma codição que de direito a prioridade?(1 = Sim / 2 = Nao): ";
    cin>>condicao;
    
    //Processamento
    if (idade>=60 || condicao == 1){
        cout<<"O cliente tem direito a atendimento prioritario";
    } else {
        cout<<"Não possui direito a atendimento prioritario";
    }
    

    return 0;
}