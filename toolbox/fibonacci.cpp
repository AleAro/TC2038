#include <iostream>


using namespace std;

// int fib(int n){

//     if(n == 0 || n == 1){
//         return n;
//     }
//     return fib(n-1) + fib(n-2);
// }

int fibSuma(int n){
    int FF[n];
    FF[0] = 0;
    FF[1] = 1;
    for(int i = 2; i <= n; i++){
        FF[i] = FF[i-1] + FF[i-2];
    }
    return FF[n];
}

int main(){
    int n;
    cout << "Número: ";
    cin >> n;
    cout << fibSuma(n) << endl;

    return 0;
}