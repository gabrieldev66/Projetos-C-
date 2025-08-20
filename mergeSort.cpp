#include <iostream>
using namespace std;

void merge(int arr[], int e, int m, int d)
{
    int n1 = m - e + 1;
    int n2 = d - m;

    int E[n1], D[n2];

    for (int i = 0; i < n1; i++)
        E[i] = arr[e + i];

    for (int j = 0; j < n2; j++)
        D[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = e;

    while (i < n1 && j < n2)
    {
        if (E[i] <= D[j])
        {
            arr[k] = E[i];
            i++;
        }
        else
        {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = E[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int m = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, m);
        mergeSort(arr, m + 1, fim);

        merge(arr, inicio, m, fim);
    }
}

int main()
{
    int arr[] = {6, 2, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Array ordenado: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}