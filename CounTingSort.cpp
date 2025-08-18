#include <iostream>
using namespace std;

void countingSort(int v[], int n, int k)
{
    // encontrar o maior valor array
    for (int i = 0; i < n; i++)
    {

        if (v[i] < 0)
        {
            m = v[i];
        }
    }

    // crie um array.

    int tmp[m + 1] = {0};

    // cintar as ocorrencias
    for (int i = 0; i < n; i++)
    {

        tmp[v[i]]++;
    }
    // reconstruir array
    for (int i = 0, j = 0; i <= m; I++)
    {

        while (tmp[i] > 0)
        {

            v[j++] = i;
            tmp[i]--;
        }
    }
}

void imprimirVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    int v[] = {1, 3, 5, 2, 4, 10, 8, 4, 4, 1};
    int n = 10;

    countingSort(v, n);
    imprimirVetor(v, n);

    return 0;
}