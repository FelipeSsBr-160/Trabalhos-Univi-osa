#include <iostream>

using namespace std;
int main()
{
    cout<<"***************************************************"<<endl;
    cout<<"***********NUMERO DENTRO DE UM INTERVALO***********"<<endl;
    cout<<"***************************************************"<<endl;
    
    //Declaração de variaveis
    double numero;
    
    //Entrada de dados
    cout<<"Digite um numero: ";
    cin>>numero;
    
    //Procesamento
    if (numero >=10 && numero <= 50){
        cout<<"O numero está dentro do intervalo de 10 a 50!";
        
    } else{
        cout<<"Numero fora do intervalo!";
        
    }

    return 0;
}