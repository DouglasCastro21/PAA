//Implementar o algoritmo BruteForceStringMatch
#include <bits/stdc++.h>
using namespace std;

void search(char* particao, char* text)
{
    int P = strlen(particao);
    int T = strlen(text);

    //deslizar indic [] um por um
    for (int i = 0; i <= T - P; i++) {
        int j;

        //verifique se há correspondência de padrão
        for (j = 0; j < P; j++)
            if (text[i + j] != particao[j])
                break;

        if (j == P)
            cout << "Padrão Indice "
                 << i << endl;
    }
}


int main()
{
    char text[] = "kkkkRSRSRSRSKAKAHAHA";
    char particao[] = "HAHA";
    search(particao, text);
    return 0;
}

