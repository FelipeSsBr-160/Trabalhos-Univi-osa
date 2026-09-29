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
    // declaracao de variaveis
    double preco, valor;
    string nome;
    
    //entrada de dados
    cout<< "Digite o valor do kWh: ";
    cin>> preco;
    cin.ignore();
    cout<< "Digite o seu nome: ";
    getline(cin, nome);
    
    //calculo
    valor = (2.5 * 30) * preco;
    
    //saida de dados
    cout << fixed << setprecision(2);
    cout<< "Valor a ser pago no mês: " << valor;
    

    return 0;
}