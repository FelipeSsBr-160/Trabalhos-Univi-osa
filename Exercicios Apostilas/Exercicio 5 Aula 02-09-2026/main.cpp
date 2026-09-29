#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"*********************************************************"<<endl;
    cout<<"********************CONCEITO ESCOLAR*********************"<<endl;
    cout<<"*********************************************************"<<endl;
    
    //Declaração de variaveis
    double nota;
    
    //Entrada de dados
    cout<<"Digite a nota do aluno: ";
    cin>> nota;
    
    // Processamento
    if (nota>90){
        cout<<"Nota = A";
        
    } else if (nota>=70){
        cout<<"Nota = B";
        
    } else if (nota>=50){
        cout<<"Nota = C";
        
    } else{
        cout<<"Nota = D";
    }

    return 0;
}