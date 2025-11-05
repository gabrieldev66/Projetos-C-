#include <iostream>
using namespace std;

int buscaBinaria(int v[], int inicio, int fim, int x)
{
    if (inicio > fim)
        return -1; // Não encontrado

    int meio = (inicio + fim) / 2;

    if (v[meio] == x)
        return meio;
    else if (v[meio] > x)
        return buscaBinaria(v, inicio, meio - 1, x);
    else
        return buscaBinaria(v, meio + 1, fim, x);
}

int main()
{
    int v[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = 7;
    int valor;

    cout << "Digite o valor a buscar: ";
    cin >> valor;

    int pos = buscaBinaria(v, 0, tamanho - 1, valor);

    if (pos != -1)
        cout << "Valor encontrado na posicao " << pos << endl;
    else
        cout << "Valor nao encontrado." << endl;

    return 0;
}
