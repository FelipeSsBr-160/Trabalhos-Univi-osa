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
    if (codProduto == 1){
            cout<<"Alimento não perecivel";
            
    }else if(codProduto == 2 || codProduto == 3 || codProduto == 4){
            cout<<"Alimento perecivel";
            
    }else if(codProduto == 5 || codProduto == 6){
            cout<<"Vestuario";
            
    }else if(codProduto == 7){
            cout<<"Higiene pessoal";
            
    }else if(codProduto == 8 || codProduto == 9 || codProduto ==10 || codProduto == 11 || codProduto == 12 || codProduto == 13 || codProduto == 14 || codProduto == 15){
            cout<<"Limpeza e utensilhos domesticos";
            
    }else{
            cout<<"codigo invalido";
    }
    

    return 0;
}