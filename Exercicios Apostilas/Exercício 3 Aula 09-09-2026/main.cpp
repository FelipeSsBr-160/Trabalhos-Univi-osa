#include <iostream>

using namespace std;
int main()
{
    cout<<"*******************************************************"<<endl;
    cout<<"************************APROVAÇÃO**********************"<<endl;
    cout<<"*******************************************************"<<endl;
    
    //Declaração de variaveis
    double nota1, nota2, media;
    
    //Entrada de dados
    cout<<"Digite a primeira nota: ";
    cin>>nota1;
    
    cout<<"Digite a segunda nota: ";
    cin>>nota2;
    
    //Processamento de dados + saida
    media = (nota1+nota2)/2;
    
    cout<<"A media do aluno é: "<< media<< endl;
    
    if(media >= 60){
        cout<<"APROVADO";
        
    } else {
        cout<<"REPROVADO";
    }

    return 0;
}