#include<iostream>
using namespace std;
// 1: moedas pesadas falsas, -1: moedas leves falsas
char esquerda[3][7],direita[3][7],resultado[3][7];

int moeda[12]={0}; // 12 moedas
bool fun(){
    for(int i=0;i<3;i++){
        int soma_esquerda=0 , soma_direita=0;//pesos
        for(int j=0;j<6 && esquerda[i][j] != NULL; j++){
            soma_esquerda += moeda[esquerda[i][j] - 'A'];
            soma_direita += moeda[direita[i][j] - 'A'];
        }
        if(soma_esquerda > soma_direita && resultado[i][0] != 'u')
            return false;
        if(soma_esquerda == soma_direita && resultado[i][0] != 'e')
            return false;
        if(soma_esquerda < soma_direita && resultado[i][0] != 'd')
            return false;
    }
    return true;

}

int main()
{
    int conbinacao;
    cout<<"digite as combinação .... Ex ABC --ABD\n";
    cin >> conbinacao;
    while(conbinacao--){
        for(int i=0;i<3;i++)
            cin >> esquerda[i] >> direita[i] >> resultado[i];
        int j;
        for(j=0;j<12;j++){
            moeda[j]=1; //pesada(talvez)
            if(fun())
                break;
            moeda[j]=-1; //leve(talvez)
            if(fun())
                break;
            moeda[j]=0; //moeda real

        }
        if(moeda[j] > 0)
            cout<<char(j+'A')<<"  A moeda falsa e é pesada."<<endl;
        else
            cout<<char(j+'A')<<"  A moeda é falsa e é leve."<<endl;
    }
    return 0;
}
