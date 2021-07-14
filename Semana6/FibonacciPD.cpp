#include <iostream>
#include <vector>
#include <iomanip>  // setw


// Não é programação dinamica
int fibonacci_botton(int num){

if(num<=1){

 return 1;
}

std::vector<int> cache(num+1 ,-1);
cache[0]=1;
cache[1]=1;

    for (int i = 2; i <= num ; i++) {

       cache[i]=cache[i-1]+cache[i-2];

    }

    return cache[num];

}

void imprimir(){

    for (int i = 0; i <= 20; i++) {
        std::cout << "Fibonacci(" << std::setw(2) << i << ") = ", std::cout << fibonacci_botton(i) << std::endl;
    }
}

int main() {
    imprimir();
}
