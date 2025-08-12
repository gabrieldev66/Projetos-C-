#include <iostream>
#include <cstdlib> // para rand() e srand()
#include <ctime>   // para time()
using namespace std;

int main()
{
    srand(time(0));                        // inicializa a semente aleatória
    int numero_secreto = rand() % 100 + 1; // número entre 1 e 100
    int chute;
    int tentativas = 0;

    cout << "=== Jogo de Adivinhação ===" << endl;
    cout << "Tente adivinhar o número entre 1 e 100!" << endl;

    do
    {
        cout << "Digite seu chute: ";
        cin >> chute;
        tentativas++;

        if (chute > numero_secreto)
        {
            cout << "Muito alto! Tente um número menor." << endl;
        }
        else if (chute < numero_secreto)
        {
            cout << "Muito baixo! Tente um número maior." << endl;
        }
        else
        {
            cout << "Parabéns! Você acertou o número em " << tentativas << " tentativas." << endl;
        }
    } while (chute != numero_secreto);

    return 0;
}