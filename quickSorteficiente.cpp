#include <iostream>
using namespace std;

const int LIMITE = 16; // tamanho pequeno para troca de algoritmo

void insertionSort(int v[], int inicio, int fim)
{
    for (int i = inicio + 1; i <= fim; i++)
    {
        int chave = v[i];
        int j = i - 1;
        while (j >= inicio && v[j] > chave)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int particiona(int v[], int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[fim]);
    return i + 1;
}

void quickSort(int v[], int inicio, int fim)
{
    while (inicio < fim)
    {

        // 🔹 CONDIÇÃO DE OTIMIZAÇÃO
        if (fim - inicio < LIMITE)
        {
            insertionSort(v, inicio, fim);
            break;
        }

        int p = particiona(v, inicio, fim);

        // 🔹 Evita recursão profunda
        if (p - inicio < fim - p)
        {
            quickSort(v, inicio, p - 1);
            inicio = p + 1;
        }
        else
        {
            quickSort(v, p + 1, fim);
            fim = p - 1;
        }
    }
}

int main()
{
    int v[] = {9, 3, 7, 1, 6, 2, 8, 5, 4};
    int n = sizeof(v) / sizeof(v[0]);

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}
