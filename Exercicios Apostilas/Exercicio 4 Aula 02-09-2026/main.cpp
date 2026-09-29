#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    cout<<"*****************************************"<<endl;
    cout<<"*************VENDA COM LUCRO*************"<<endl;
    cout<<"*****************************************"<<endl;
    
    //Declaração de variaveis
    double valor, resultado;
    
    //Entrada de dados
    cout<<"Digite o valor do produto: ";
    cin>> valor;
    
    //Processamento
    cout << fixed << setprecision(2);
    
    if(valor < 20){
        
        resultado = valor * 1.45;
        cout<<"O valor com lucro de 45% é: "<< resultado << endl;
        
    } else{
        
        resultado = valor * 1.30;
        cout<<"O valor com lucro de 30% é: "<< resultado << endl;
    }

    return 0;
}