#include <iostream>
using namespace std;

// crescente

void bubbleSort(int numeros[], int n)
{
}

// crescente
void selectionSort(int numeros[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        int indiceDoMenor = i;

        for (int j = 0; j < n; j++)
        {
            if (numeros[j] < numeros[indiceDoMenor])
            {

                indiceDoMenor = j;
            }
        }
        if (i != indiceDoMenor)
        {

            // int aux = numeros[i];
            // numeros[i]= numeros[indiceDoMenor];
            // numeros[indiceDoMenor] = aux;

            swap(numeros[i], numeros[indiceDoMenor]); // troca os valores com swap
        }
    }
}

int main()
{

    int vetor[] = {1, 2, 5, 3, 7, 4, 6};

    // bubbleSort( vetor, 7);
    selectionSort(vetor, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}
