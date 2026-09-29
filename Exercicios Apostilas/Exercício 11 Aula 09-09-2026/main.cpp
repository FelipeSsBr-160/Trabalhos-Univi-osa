#include <iostream>

using namespace std;
int main()
{
    cout<<"****************************************************"<<endl;
    cout<<"****************SISTEMA INDISPONIVEL****************"<<endl;
    cout<<"****************************************************"<<endl;

    //Declaração de variaveis
    bool manutenção = true;
    
    //Processamento
    
    if (manutenção != false){
        cout<<"Sistema indisponivel!";
        
    } else {
        cout<<"Sistema disponivel!";
        
    }

    return 0;
}