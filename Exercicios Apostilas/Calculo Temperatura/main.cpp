/******************************************************************************

Discicplina: INF101 - Programação de Computadores
Nome: Felipe da Silva
Data: 26/08/2026
Descrição: Conversor de Temperatura.

*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //declaração das variaveis
    double tempC, tempF, tempK;
    string nome;
    
    //entrada de dados
    cout << "Digite a temperatura em C°(celsius): ";
    cin >> tempC;
    cin.ignore();
    cout << "Digite o seu nome: ";
    getline(cin, nome);
    
    //Calculos
    tempF = (tempC * 9/5) + 32;
    
    tempK = tempC + 273.15;
    
    //Resultados
    cout << fixed << setprecision(2);
    cout << nome <<endl;
    cout << "Temperatura em Fahrenheit = " << tempF << endl;
    cout << "Temperatura em Kelvin = " << tempK << endl;
    
    
    
    return 0;
}
