#include <iostream>

using namespace std;
int main()
{
    cout<<"****************************************"<<endl;
    cout<<"*****************DESCONTO***************"<<endl;
    cout<<"****************************************"<<endl;

    //Declaraçao de variaveis
    int fidelidade, cLoja;
    
    //Entrada de dados
    cout<<"Possui cartão da loja? (1 = Sim / 2 = Nao): ";
    cin>>cLoja;
    cout<<"Participa do programa de fidelidade? (1 = Sim / 2 = Nao): ";
    cin>>fidelidade;
    
    //Processamento
    if (cLoja == 1 || fidelidade == 1){
        cout<<"Tem direito a desconto!";
    } else {
        cout<<"Não tem direito a desconto";
    }
    
    
    
    return 0;
}