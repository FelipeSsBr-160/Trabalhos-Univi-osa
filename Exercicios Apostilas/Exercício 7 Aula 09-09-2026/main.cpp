#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout<<"****************************************************"<<endl;
    cout<<"***************ENTRADA EM UM EVENTO*****************"<<endl;
    cout<<"****************************************************"<<endl;
    
    //Declaração de variaveis
    int idade, resposta;
    bool ingresso;
    
    //Entrada de dados
    cout<<"Digite a idade: ";
    cin>>idade;
    
    cout<<"Possui ingresso(SIM = 1 ou NAO = 2): ";
    cin>>resposta;
    
    //Processamento
    if(resposta == 1 || resposta == 2){
        
        if(resposta == 1){
            ingresso = true;
            
        } else {
            ingresso = false;
            
        }
        
        if(idade<18 || ingresso == false){
            cout<<"Entrada não permitida!";
            
        } else {
            cout<<"Entrada permitida!";
        }
        
    } else{
        cout<<"Resposta invalida";
        
    }

    return 0;
}