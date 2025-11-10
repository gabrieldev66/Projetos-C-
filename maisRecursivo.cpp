#include <iostream>
#include <cmath> // para usar pow()
using namespace std;

// Função recursiva para calcular o fatorial
int fatorial(int g)
{
    if (g == 0)
        return 1;
    else
        return g * fatorial(g - 1);
}

// Função recursiva para somar os elementos de um vetor
float somaRecursiva(float g[], int tamanho)
{
    if (tamanho == 0)
        return 0;
    else
        return g[tamanho - 1] + somaRecursiva(g, tamanho - 1);
}

// Função recursiva para repetir soma (exemplo)
float repeticao(float valor, int vezes)
{
    if (vezes == 0)
        return 0;
    else
        return valor + repeticao(valor, vezes - 1);
}

int main()
{
    int numeroFatorial;
    cout << "Digite um numero para calcular o fatorial (ou 0 para sair): ";
    cin >> numeroFatorial;

    while (numeroFatorial != 0)
    {
        cout << "Fatorial de " << numeroFatorial << " eh " << fatorial(numeroFatorial) << endl;
        cout << "Digite outro numero (ou 0 para sair): ";
        cin >> numeroFatorial;
    }

    // Potenciação
    int base, expoente;
    cout << "\nDigite a base e o expoente: ";
    cin >> base >> expoente;
    cout << "Resultado de " << base << " elevado a " << expoente << " eh " << pow(base, expoente) << endl;

    // Soma recursiva de um vetor
    float numeros[] = {1, 4, 5, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    cout << "\nSoma dos elementos do vetor: " << somaRecursiva(numeros, tamanho) << endl;

    // Exemplo de repetição recursiva
    cout << "\nRepeticao (somar 2 cinco vezes): " << repeticao(2, 5) << endl;

    return 0;
}
