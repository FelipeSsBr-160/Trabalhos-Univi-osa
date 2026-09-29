/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout<<"********************************************"<<endl;
    cout<<"***********EXERCICO PAR OU IMPAR************"<<endl;
    cout<<"********************************************"<<endl;
    
    //Declaração de Variaveis
    
    int numero, resto;
    
    
    //Entrada de Dados
    cout<<"Digite um numero:";
    cin>> numero;
    
    //Processamento
    resto = numero % 2;
    
    if(resto = 0){
        cout<<"É um numero PAR!";
    } else {
        cout<<"É um numero IMPAR!";
    }
    

    return 0;
}