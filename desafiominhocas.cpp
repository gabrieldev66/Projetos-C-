#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> campo(N, vector<int>(M));

    // Leitura da matriz
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> campo[i][j];
        }
    }

    int maxMinhocas = 0;

    // Soma por linhas
    for (int i = 0; i < N; i++)
    {
        int somaLinha = 0;
        for (int j = 0; j < M; j++)
        {
            somaLinha += campo[i][j];
        }
        if (somaLinha > maxMinhocas)
            maxMinhocas = somaLinha;
    }

    // Soma por colunas
    for (int j = 0; j < M; j++)
    {
        int somaColuna = 0;
        for (int i = 0; i < N; i++)
        {
            somaColuna += campo[i][j];
        }
        if (somaColuna > maxMinhocas)
            maxMinhocas = somaColuna;
    }

    cout << maxMinhocas << endl;

    return 0;
}
