#include <iostream>
#include <vector>
using namespace std;

class Grafo
{
    int V;
    vector<vector<int>> matriz;

public:
    Grafo(int vertices) : V(vertices), matriz(vertices, vector<int>(vertices, 0)) {}

    void adicionarAresta(int u, int v)
    {
        matriz[u][v] = 1;
        matriz[v][u] = 1; // se for não-direcionado
    }

    void mostrar()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << matriz[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Grafo g(4);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 3);
    g.mostrar();
}
