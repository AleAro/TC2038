#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bubble sort
void bubbleSort(vector<int> &arr, const vector<int> &rank, int k, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int ra = (arr[j] + k < n) ? rank[arr[j] + k] : -1;
            int rb = (arr[j + 1] + k < n) ? rank[arr[j + 1] + k] : -1;
            
            if (rank[arr[j]] > rank[arr[j + 1]] || (rank[arr[j]] == rank[arr[j + 1]] && ra > rb)) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> suffixArray(n, 0);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    bubbleSort(suffixArray, rank, 0, n);

    for (int k = 1; k < n; k *= 2) {
        bubbleSort(suffixArray, rank, k, n);
        
        vector<int> tempRank(n, 0);
        for (int i = 1; i < n; i++) {
            tempRank[i] = tempRank[i - 1] + (rank[suffixArray[i - 1]] != rank[suffixArray[i]] || 
                        (suffixArray[i - 1] + k < n ? rank[suffixArray[i - 1] + k] : -1) !=
                        (suffixArray[i] + k < n ? rank[suffixArray[i] + k] : -1));
        }
        
        for (int i = 0; i < n; i++) {
            rank[suffixArray[i]] = tempRank[i];
        }
    }

    return suffixArray;
}

int main() {
    string s;
    cout << "Ingresa el string: ";
    cin >> s;

    vector<int> suffixArray = buildSuffixArray(s);
    
    cout << "Arreglo de sufijos:" << endl;
    for (int i = 0; i < suffixArray.size(); i++) {
        cout << suffixArray[i] << ": " << s.substr(suffixArray[i]) << endl;
    }

    return 0;
}
