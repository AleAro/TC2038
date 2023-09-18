#include <iostream>
#include <map>



using namespace std;

// int fib(int n){

//     if(n == 0 || n == 1){
//         return n;
//     }
//     return fib(n-1) + fib(n-2);
// }



// int fibSuma(int n){
//     int FF[n];
//     FF[0] = 0;
//     FF[1] = 1;
//     for(int i = 2; i <= n; i++){
//         FF[i] = FF[i-1] + FF[i-2];
//     }
//     return FF[n];
// }



map<int, int> init_map() {
    map<int, int> temp;
    temp[0] = 0;
    temp[1] = 1;
    return temp;
}

map<int, int> my_map = init_map();

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (my_map.find(n) != my_map.end()) {
        return my_map[n];
    }
    my_map[n] = fib(n-1) + fib(n-2);
    return my_map[n];
}

int main() {
    int n;
    cout << "Número: ";
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}
