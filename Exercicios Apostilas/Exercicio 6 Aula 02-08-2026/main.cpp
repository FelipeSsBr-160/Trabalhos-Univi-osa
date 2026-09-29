#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    
    cout<<"****************************************************"<<endl;
    cout<<"*******************DIAS DA SEMANA*******************"<<endl;
    cout<<"****************************************************"<<endl;
    
    //Declaração de variaveis
    int dia;
    
    //Entrada de dados
    cout<<"Digite o valor do dia da semna (1 a 7): ";
    cin>>dia;
    
    //Processamento
    switch (dia){
        case 1:
            cout<<"Domingo";
            break;
            
        case 2:
            cout<<"Segunda-Feira";
            break;
        
        case 3:
            cout<<"Terça-Feira";
            break;
            
        case 4:
            cout<<"Quarta-Feira";
            break;
            
        case 5:
            cout<<"Quinta-Feira";
            break;
            
        case 6:
            cout<<"Sexta-Feira";
            break;
            
        case 7:
            cout<<"Sabado";
            break;
    }

    return 0;
}