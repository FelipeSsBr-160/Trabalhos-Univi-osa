#include <iostream>

using namespace std;

int main()
{
    cout<<"*****************************************************"<<endl;
    cout<<"*****************USUARIO BLOQUEADO*******************"<<endl;
    cout<<"*****************************************************"<<endl;

    //Declaração de variaveis
    bool bloqueado = true;
    
    //Processamento
    if(bloqueado != false){
        cout<<"Acesso Liberado!";
        
    }else{
        cout<<"Acesso Negado!";
    }
    
    
    return 0;
}