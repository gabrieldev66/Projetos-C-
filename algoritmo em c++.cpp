#include <iostream>
using namespace std;

int main()
{
    // ====== VETOR COM PONTEIRO ======
    int vetor[5] = {10, 20, 30, 40, 50};
    int *p; // ponteiro

    cout << "=== Vetor com ponteiros ===" << endl;
    p = vetor; // ponteiro aponta para o primeiro elemento do vetor

    for (int i = 0; i < 5; i++)
    {
        cout << "Elemento " << i << " = " << *(p + i) << endl;
    }

    // ====== MATRIZ COM PONTEIRO ======
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "\n=== Matriz com ponteiros ===" << endl;

    int *pm = &matriz[0][0]; // ponteiro para o primeiro elemento da matriz

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // acessa como vetor linear (i*colunas + j)
            cout << *(pm + (i * 3 + j)) << " ";
        }
        cout << endl;
    }

    // ====== USANDO MATRIZ DE NOTAS DE ALUNOS ======
    int alunos = 2, provas = 3;
    float notas[2][3] = {
        {8.5, 7.0, 9.0}, // notas aluno 1
        {6.0, 7.5, 8.0}  // notas aluno 2
    };

    cout << "\n=== Médias dos alunos ===" << endl;
    for (int i = 0; i < alunos; i++)
    {
        float soma = 0;
        float *pn = &notas[i][0]; // ponteiro para as notas do aluno i
        for (int j = 0; j < provas; j++)
        {
            soma += *(pn + j);
        }
        cout << "Aluno " << i + 1 << " -> Média = " << soma / provas << endl;
    }

    return 0;
}
