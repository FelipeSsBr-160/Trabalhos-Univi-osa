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
    cout<<"***************EXERCICO MEDIA***************"<<endl;
    cout<<"********************************************"<<endl;
    //Declaração das Variaveis
    double nota1, nota2, nota3, media, notaEx;
    
    
    //Entrada de Dados
    cout<<"Digite as notas:"<< endl;
    cout<<"Nota 1: ";
    cin>> nota1;
    
    cout<<"Nota 2: ";
    cin >> nota2;
    
    cout<<"Nota 3: ";
    cin >> nota3;
    
    //Processamento
    media = (nota1+nota2+nota3)/ 3;
    
    if (media >=0 && media <3){
        cout<<"Reprovado";
        
    } else if (media >=3 && media <7 ){
        cout<<"Exame"<< endl;
        notaEx = 12 - media;
        
        cout<<"Nota necessaria para aprovação: " << notaEx;
        
    } else {
        cout<<"Aprovado";
        
    }
    
    
    
    

    return 0;
}