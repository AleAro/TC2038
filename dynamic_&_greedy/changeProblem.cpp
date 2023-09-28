#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> denom;

vector<int> minNumMonGR(int n)
{
    vector<int> result(denom.size(), 0);
    for (int i = 0; i < denom.size(); i++)
    {
        while (n >= denom[i])
        {
            n -= denom[i];
            result[i]++;
        }
    }
    return result;
}

vector<int> minNumMonDP(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    vector<vector<int> /* */> coinCount(n + 1, vector<int>(denom.size(), 0));

    dp[0] = 0;
    for (int i = 0; i < denom.size(); i++)
    {
        for (int j = denom[i]; j <= n; j++)
        {
            if (dp[j - denom[i]] != INT_MAX && dp[j - denom[i]] + 1 < dp[j])
            {
                dp[j] = dp[j - denom[i]] + 1;
                coinCount[j] = coinCount[j - denom[i]];
                coinCount[j][i]++;
            }
        }
    }
    return coinCount[n];
}

void escribeRespuesta(int n)
{
    vector<int> grResult = minNumMonGR(n);
    vector<int> dpResult = minNumMonDP(n);

    cout << "Usando Greedy:" << endl;
    for (int i = 0; i < denom.size(); i++)
    {
        if (grResult[i] != 0)
        {
            cout << grResult[i] << " moneda(s) de " << denom[i] << endl;
        }
    }

    cout << "\nUsando Programación Dinámica:" << endl;
    for (int i = 0; i < denom.size(); i++)
    {
        if (dpResult[i] != 0)
        {
            cout << dpResult[i] << " moneda(s) de " << denom[i] << endl;
        }
    }
}

int main()
{
    int N, P, Q;
    cout << "Introduce el número de denominaciones: ";
    cin >> N;
    denom.resize(N);
    cout << "Introduce las denominaciones de mayor a menor:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> denom[i];
    }
    cout << "Introduce el precio P del producto: ";
    cin >> P;
    cout << "Introduce el monto con el que se paga Q: ";
    cin >> Q;

    int change = Q - P;
    escribeRespuesta(change);
    return 0;
}
