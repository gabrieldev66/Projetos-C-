#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------
// Função: Busca Binária Iterativa
// ----------------------------------------------------------
int buscaBinariaIterativa(const vector<int> &v, int alvo)
{
    int inicio = 0;
    int fim = v.size() - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == alvo)
            return meio;

        if (v[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

// ----------------------------------------------------------
// Função: Mostrar vetor
// ----------------------------------------------------------
void mostrarVetor(const vector<int> &v)
{
    if (v.empty())
    {
        cout << "Vetor vazio!" << endl;
        return;
    }

    cout << "Vetor: ";
    for (int n : v)
        cout << n << " ";
    cout << endl;
}

// ----------------------------------------------------------
// Função Principal com Menu Interativo
// ----------------------------------------------------------
int main()
{
    vector<int> dados;
    int opcao;

    do
    {
        cout << "\n==============================\n";
        cout << "       MENU PRINCIPAL\n";
        cout << "==============================\n";
        cout << "1 - Inserir número no vetor\n";
        cout << "2 - Ordenar vetor\n";
        cout << "3 - Mostrar vetor\n";
        cout << "4 - Buscar valor (Busca Binária)\n";
        cout << "5 - Limpar vetor\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int valor;
            cout << "Digite um número: ";
            cin >> valor;
            dados.push_back(valor);
            cout << "Número inserido!\n";
            break;
        }
        case 2:
        {
            if (dados.empty())
            {
                cout << "Vetor vazio!\n";
            }
            else
            {
                sort(dados.begin(), dados.end());
                cout << "Vetor ordenado!\n";
            }
            break;
        }
        case 3:
        {
            mostrarVetor(dados);
            break;
        }
        case 4:
        {
            if (dados.empty())
            {
                cout << "Insira números antes de buscar!\n";
                break;
            }

            int alvo;
            cout << "Valor para buscar: ";
            cin >> alvo;

            int pos = buscaBinariaIterativa(dados, alvo);

            if (pos != -1)
                cout << "Valor encontrado no índice: " << pos << endl;
            else
                cout << "Valor nao encontrado.\n";

            break;
        }
        case 5:
        {
            dados.clear();
            cout << "Vetor limpo!\n";
            break;
        }
        case 0:
            cout << "Saindo...\n";
            break;

        default:
            cout << "Opcao inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}
