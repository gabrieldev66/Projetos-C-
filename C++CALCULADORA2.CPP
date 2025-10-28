#include <iostream>
using namespace std;

struct Matematica
{
    int soma(int x, int y)
    {
        return x + y;
    }

    int subtracao(int x, int y)
    {
        return x - y;
    }

    int multiplicacao(int x, int y)
    {
        return x * y;
    }

    float divisao(float x, float y)
    {
        if (y != 0)
        {
            return x / y;
        }
        else
        {
            cout << "Erro! Divisao por zero." << endl;
            return 0;
        }
    }
};

int main()
{
    Matematica calc;
    int opcao;

    while (true)
    {
        cout << "\n===== CALCULADORA =====" << endl;
        cout << "1 - Soma" << endl;
        cout << "2 - Subtracao" << endl;
        cout << "3 - Multiplicacao" << endl;
        cout << "4 - Divisao" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 0)
        {
            cout << "Encerrando o programa..." << endl;
            break;
        }

        int a, b;
        cout << "Digite dois numeros: ";
        cin >> a >> b;

        switch (opcao)
        {
        case 1:
            cout << "Resultado: " << calc.soma(a, b) << endl;
            break;
        case 2:
            cout << "Resultado: " << calc.subtracao(a, b) << endl;
            break;
        case 3:
            cout << "Resultado: " << calc.multiplicacao(a, b) << endl;
            break;
        case 4:
            cout << "Resultado: " << calc.divisao(a, b) << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
    }

    return 0;
}
