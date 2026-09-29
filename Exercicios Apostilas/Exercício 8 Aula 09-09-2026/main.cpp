#include <iostream>

using namespace std;
int main()
{
    cout<<"*********************************************"<<endl;
    cout<<"********************DIA ÚTIL*****************"<<endl;
    cout<<"*********************************************"<<endl;
    
    //Declaração de variaveis
    int dia;
    
    //Entrada de dados
    cout<<"Digite o dia da semana(1 a 7): ";
    cin>>dia;
    
    //Processamento de dados
    
    if (dia ==1 || dia ==7){
        cout<<"É final de semana!";
        
    } else if(dia>=1 && dia<=7){
        cout<<"Não é final de semana!";
    } else {
        cout<<"Valor invalido!";
    }

    return 0;
}