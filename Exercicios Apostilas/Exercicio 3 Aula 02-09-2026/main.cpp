/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"********************************************"<<endl;
    cout<<"************CREDITO FUNCIONARIOS************"<<endl;
    cout<<"********************************************"<<endl;
    
    //Declaração das Variaveis
    
    double salario, prestacao, porcentagem;
    
    //Entrada de Dados
    
    cout<<"Digite o salario bruto: ";
    cin>>salario;
    
    cout<<"digite o valor da parcela: ";
    cin>>prestacao;
    
    // Processamento
    cout<<fixed<<setprecision(2);
    
    porcentagem = (salario / 100) * 30;
    if ( prestacao > porcentagem){
        cout<< "Empestimo negado, parcela superior ao permitido!";
        
    } else{
        cout<< "Emprestimo concedido!";
    }

    return 0;
}