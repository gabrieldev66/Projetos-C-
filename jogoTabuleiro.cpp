#include <iostream>
using namespace std;

char tabuleiro[3][3];

void inicializar()
{
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = c++;
}

void mostrar()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }
}

bool ganhou(char simbolo)
{
    for (int i = 0; i < 3; i++)
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo)
            return true;
    for (int j = 0; j < 3; j++)
        if (tabuleiro[0][j] == simbolo && tabuleiro[1][j] == simbolo && tabuleiro[2][j] == simbolo)
            return true;
    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo)
        return true;
    if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo)
        return true;
    return false;
}

int main()
{
    inicializar();
    char jogador = 'X';
    int jogadas = 0;

    while (true)
    {
        mostrar();
        cout << "Jogador " << jogador << ", escolha uma posição: ";
        int pos;
        cin >> pos;

        bool valido = false;
        for (int i = 0; i < 3 && !valido; i++)
        {
            for (int j = 0; j < 3 && !valido; j++)
            {
                if (tabuleiro[i][j] == ('0' + pos))
                {
                    tabuleiro[i][j] = jogador;
                    valido = true;
                }
            }
        }

        if (!valido)
        {
            cout << "Posição inválida!\n";
            continue;
        }

        jogadas++;
        if (ganhou(jogador))
        {
            mostrar();
            cout << "Jogador " << jogador << " venceu!\n";
            break;
        }
        if (jogadas == 9)
        {
            mostrar();
            cout << "Empate!\n";
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}