// manejo strings (Z-function)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> ZNaive(string S)
{
    int n = S.length();
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        while (i + k < n && S[k] == S[i + k])
        {
            k++;
        }
        A[i] = k;
    }
    return A;
}

int main()
{
    string S = "aaabaaab";
    vector<int> A = ZNaive(S);
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}