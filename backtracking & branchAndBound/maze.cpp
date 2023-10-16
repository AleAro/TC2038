#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

// Variables Globales
int M, N;
vector<vector<int> /**/> laberinto;
vector<vector<int> /**/> solucionBacktracking;
vector<vector<int> /**/> solucionBranchAndBound;

struct Node
{
    int x, y, distancia;
};


bool operator>(const Node &a, const Node &b)
{
    return a.distancia > b.distancia;
}


int distManhattan(int x, int y)
{
    return (M - 1 - x) + (N - 1 - y);
}

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

        // derecha
        if (resolverLaberintoBacktracking(x, y + 1))
        {
            return true;
        }

        // abajo
        if (resolverLaberintoBacktracking(x + 1, y))
        {
            return true;
        }

        // izquierda
        if (resolverLaberintoBacktracking(x, y - 1))
        {
            return true;
        }

        // arriba
        if (resolverLaberintoBacktracking(x - 1, y))
        {
            return true;
        }

        // backtracking
        solucionBacktracking[x][y] = 0;
    }
    return false;
}

struct CompareNode {
    bool operator()(const Node &a, const Node &b) const {
        return a.distancia > b.distancia;
    }
};


void branchAndBound()
{
    solucionBranchAndBound.resize(M, vector<int>(N, 0));

    priority_queue<Node, vector<Node>, CompareNode> pq;

    Node inicio = {0, 0, distManhattan(0, 0)};
    pq.push(inicio);

    while (!pq.empty())
    {
        Node actual = pq.top();
        pq.pop();
        int x = actual.x, y = actual.y;

        if (solucionBranchAndBound[x][y] == 1) continue;

        solucionBranchAndBound[x][y] = 1;

        if (x == M - 1 && y == N - 1)
        {
            return;
        }

        
        if (esValido(x + 1, y, solucionBranchAndBound))
        {
            Node siguiente = {x + 1, y, distManhattan(x + 1, y)};
            pq.push(siguiente);
        }

        if (esValido(x, y + 1, solucionBranchAndBound))
        {
            Node siguiente = {x, y + 1, distManhattan(x, y + 1)};
            pq.push(siguiente);
        }

        if (esValido(x - 1, y, solucionBranchAndBound))
        {
            Node siguiente = {x - 1, y, distManhattan(x - 1, y)};
            pq.push(siguiente);
        }

        if (esValido(x, y - 1, solucionBranchAndBound))
        {
            Node siguiente = {x, y - 1, distManhattan(x, y - 1)};
            pq.push(siguiente);
        }
    }
}


