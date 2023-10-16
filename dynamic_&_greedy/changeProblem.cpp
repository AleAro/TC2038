#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> denom; // Vector global que almacenará las denominaciones de las monedas.

// Esta función encuentra la cantidad mínima de monedas usando un algoritmo Greedy.
vector<int> minNumMonGR(int n)
{
    vector<int> result(denom.size(), 0); // Inicializar el resultado con ceros.
    for (int i = 0; i < denom.size(); i++)
    {
        while (n >= denom[i])
        {
            n -= denom[i]; // Restamos la denominación actual al total.
            result[i]++;   // Aumentamos el conteo de esa moneda en el resultado.
        }
    }
    return result;
}

// Esta función encuentra la cantidad mínima de monedas usando Programación Dinámica.
vector<int> minNumMonDP(int n)
{
    vector<int> dp(n + 1, INT_MAX);                                          // Vector que almacena el mínimo número de monedas para cada valor.
    vector<vector<int> /**/> coinCount(n + 1, vector<int>(denom.size(), 0)); // Almacena el desglose de monedas para cada valor.

    dp[0] = 0;
    for (int i = 0; i < denom.size(); i++)
    {
        for (int j = denom[i]; j <= n; j++)
        {
            // Actualizamos el valor mínimo y su desglose de monedas.
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

// Esta función imprime la cantidad mínima de monedas usando ambos algoritmos.
void escribeRespuesta(int n)
{
    vector<int> grResult = minNumMonGR(n); // Resultado usando Greedy.
    vector<int> dpResult = minNumMonDP(n); // Resultado usando Programación Dinámica.

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
    for (int i = 0; i < N; i++)
    {
        cout << "Introduce la moneda " << (i + 1) << ": ";
        cin >> denom[i];
    }
    cout << "Introduce el precio P del producto: ";
    cin >> P;
    cout << "Introduce el monto con el que se paga Q: ";
    cin >> Q;

    int change = Q - P;       // Calcular el cambio.
    escribeRespuesta(change); // Mostrar el cambio en monedas.
    return 0;
}
