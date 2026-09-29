#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"****************************************************"<<endl;
    cout<<"*******************DIAS DA SEMANA*******************"<<endl;
    cout<<"****************************************************"<<endl;

    //Declaração de variaveis
    int codProduto;
    
    //Entrada de dados
    cout<<"Digite o codigo do produto: ";
    cin>>codProduto;
    
    //Processamento
    switch (codProduto){
        
        case 1:
            cout<<"Alimento não perecivel";
            break;
        
        case 2:
        case 3:
        case 4:
            cout<<"Alimento perecivel";
            break;
        
        case 5:
        case 6:
            cout<<"Vestuario";
            break;
        
        case 7:
            cout<<"Higiene pessoal";
            break;
        
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            cout<<"Limpeza e utensilhos domesticos";
            break;
        
        default:
            cout<<"codigo invalido";
    
    }
    

    return 0;
}