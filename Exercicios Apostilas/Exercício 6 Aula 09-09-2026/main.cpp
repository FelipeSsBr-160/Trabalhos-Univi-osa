#include <iostream>
#include <string>

using  namespace std;
int main()
{
    cout<<"*****************************************"<<endl;
    cout<<"*******************LOGIN*****************"<<endl;
    cout<<"*****************************************"<<endl;

    //Declaração de variaveis
    string usuario, senha;
    
    //Entrada de dados
    cout<<"USUARIO: ";
    cin>>usuario;
    
    cout<<"SENHA: ";
    cin>>senha;
    
    //Processamento de dados
    if(usuario == "admin" && senha == "1234"){
        cout<<"Acesso liberado!";
        
    } else {
        cout<<"Acesso negado! usuario ou senha incorretos";
    }
    

    return 0;
}