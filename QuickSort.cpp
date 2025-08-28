#include <iostream>
using namespace std;

void imprimir(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void swap(int arr[], int a, int b)
{
    if (a == b)
        return;

    int tmp = arr[a];

    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int arr[], int inicio, int fim)
{

    int pivot = arr[fim];

    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (arr[j] < pivot)
        {

            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, fim);

    return i + 1;
}

void quickSort(int arr[], int inicio, int fim)
{

    if (inicio < fim)
    {

        int p = partition(arr, inicio, fim);
        quickSort(arr, inicio, p - 1);

        quickSort(arr, p + 1, fim);
    }
}

int main()
{
    int arr[] = {23, 45, 12, 8, 32, 10, 5, 67};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "vetor antes de ordenar" << endl;

    imprimir(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "vetor depois de ordenar" << endl;

    imprimir(arr, n);

    return 0;
}
