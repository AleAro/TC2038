#include <iostream>

using namespace std;


int bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swapped = true;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(!swapped){
            break;
        }
    }
}