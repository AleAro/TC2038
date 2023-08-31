#include <iostream>

using namespace std;


 void quickSort (int a[], int lo, int hi)
 {
    if (hi <= lo) return;
    int j = partition(a, lo, hi);
    quickSort(a, lo, j-1);
    quickSort(a, j+1, hi);
 }

 int partition (int a[], int lo, int hi)
 {
    int i = lo, j = hi+1;
    int v = a[lo];
    while (true){
        if (i >= j) break;
    }
    v = a[j];
    return j;
 }

