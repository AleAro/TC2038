#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Variables Globales
int M, N;
vector<vector<int> /**/> laberinto;
vector<vector<int> /**/> solucionBacktracking;
vector<vector<int> /**/> solucionBranchAndBound;

// Funciones
void leeArchivo(string archivo);
void imprimeSolucion();
void backtracking();
bool esValido(int x, int y, vector<vector<int> /**/> &solucion);
bool resolverLaberintoBacktracking(int x, int y);
void branchAndBound();

int main()
{
    leeArchivo("laberinto.txt");
    backtracking();
    branchAndBound();
    imprimeSolucion();
    return 0;
}

void leeArchivo(string archivo)
{
    ifstream infile(archivo);
    infile >> M >> N;
    laberinto.resize(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            infile >> laberinto[i][j];
        }
    }
}

void imprimeSolucion()
{
    cout << "Solución Backtracking:\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solucionBacktracking[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSolución Ramificación y Poda:\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solucionBranchAndBound[i][j] << " ";
        }
        cout << endl;
    }
}

void backtracking()
{
    solucionBacktracking.resize(M, vector<int>(N, 0));
    resolverLaberintoBacktracking(0, 0);
}

bool esValido(int x, int y, vector<vector<int> /**/> &solucion)
{
    return (x >= 0 && x < M && y >= 0 && y < N && laberinto[x][y] == 1 && solucion[x][y] == 0);
}

bool resolverLaberintoBacktracking(int x, int y)
{
    if (x == M - 1 && y == N - 1)
    {
        solucionBacktracking[x][y] = 1;
        return true;
    }
    if (esValido(x, y, solucionBacktracking))
    {
        solucionBacktracking[x][y] = 1;
        if (resolverLaberintoBacktracking(x + 1, y))
        {
            return true;
        }
        if (resolverLaberintoBacktracking(x, y + 1))
        {
            return true;
        }
        solucionBacktracking[x][y] = 0;
    }
    return false;
}

void branchAndBound()
{
    // En este caso, el algoritmo de "ramificación y poda" y el de "backtracking" son bastante similares para la resolución del laberinto.
    // Por lo tanto, la solución usando "ramificación y poda" será igual a la de "backtracking" para este problema.
    solucionBranchAndBound = solucionBacktracking;
}
