#include <iostream>

using namespace std;
int main()
{
    cout<<"******************************************"<<endl;
    cout<<"****************MAIOR IDADE***************"<<endl;
    cout<<"******************************************"<<endl;
    
    //Declaração de variaveis
    int idade;
    
    //Entrada de dados
    cout<<"Digite a idade: ";
    cin>> idade;
    
    //Processamento de dados
    if (idade >= 18){
        cout<<"MAIOR DE 18 ANOS";
        
    } else {
        cout<<"MENOR DE 18 ANOS";
        
    }

    return 0;
}