#include <iostream>
using namespace std;

int main()
{
    float num1, num2;
    char op;

    cout << "Digite dois números: ";
    cin >> num1 >> num2;
    cout << "Escolha a operação (+, -, *, /): ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << num1 + num2;
        break;
    case '-':
        cout << num1 - num2;
        break;
    case '*':
        cout << num1 * num2;
        break;
    case '/':
        if (num2 != 0)
            cout << num1 / num2;
        else
            cout << "Erro: divisão por zero!";
        break;
    default:
        cout << "Operador inválido.";
    }
    return 0;
}