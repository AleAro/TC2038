#include <iostream>

using namespace std;

int selectionSort(int arr[], int n){
    int min, temp;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}