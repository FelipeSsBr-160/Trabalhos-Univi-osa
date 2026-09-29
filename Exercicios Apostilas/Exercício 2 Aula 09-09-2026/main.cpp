#include <iostream>

using  namespace std;
int main()
{
    cout<<"*****************************************"<<endl;
    cout<<"********NUMEROS NEGATIVO POSITIVO********"<<endl;
    cout<<"*****************************************"<<endl;
    
    //Declaração de variaveis
    int numero;
    
    //entrada de dados
    cout<<"Digite um numero inteiro: ";
    cin>>numero;
    
    //Processamento
    
    if (numero == 0){
        cout<<"Numero igual a zero!";

    } else if(numero > 0){
        cout<<"Numero positivo!";
        
    } else {
        cout<<"Numero negativo!";
    }
    
    return 0;
}