
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string palavra = {"testesss" };
    bool valor = next_permutation(palavra.begin(),palavra.end());
    if (valor == false)
        cout << "Nenhuma palavra possível"<< endl;
    else
        cout << palavra << endl;
    return 0;
}
