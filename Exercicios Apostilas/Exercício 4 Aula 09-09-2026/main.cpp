#include <iostream>

using namespace std;
int main()
{
    cout<<"*******************************************************"<<endl;
    cout<<"************************APROVAÇÃO**********************"<<endl;
    cout<<"*******************************************************"<<endl;
    
    //Declaração de variaveis
    double nota1, nota2, media, frequencia;
    
    //Entrada de dados
    cout<<"Digite a primeira nota: ";
    cin>>nota1;
    
    cout<<"Digite a segunda nota: ";
    cin>>nota2;
    
    cout<<"Digite a frequencia do aluno (%): ";
    cin>>frequencia;
    
    //Processamento de dados + saida
    media = (nota1+nota2)/2;
    
    cout<<"A media do aluno é: "<< media<< endl;
    
    if (media >= 60 && frequencia >= 75){
        cout<<"APROVADO";
        
    } else if(media >=60 && frequencia < 75) {
        cout<<"REPROVADO POR FALTA";
        
    } else {
        cout<<"REPROVADO POR NOTA";
        
    }

    return 0;
}