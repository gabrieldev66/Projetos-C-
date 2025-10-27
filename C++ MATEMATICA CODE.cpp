#include <iostream>
#include <string>

using namespace std;

void funcaoexemplo()
{
    string exemplo = "exemplo de funcao: ";
    cout << exemplo << endl;
}

void funcaomatematica()
{
    int a, b;
    cout << "Digite dois numeros inteiros: ";
    cin >> a >> b;
    cout << "Soma: " << a + b << endl;
}

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
            cout << "Erro: divisao por zero!" << endl;
            return 0;
        }
    }
}; // ? Fechamento correto do struct

int main()
{
    funcaomatematica();
    funcaoexemplo();

    int var1 = 10;
    int var2 = 20;

    cout << "Soma de var1 e var2: " << var1 + var2 << endl;
    cin.get();

    float nota1, nota2, media;

    cout << "Digite a primeira nota: ";
    cin >> nota1;

    cout << "Digite a segunda nota: ";
    cin >> nota2;

    media = (nota1 + nota2) / 2;

    cout << "\nMedia: " << media << endl;

    if (media >= 7.0)
    {
        cout << "Situacao: Aprovado ?" << endl;
    }
    else if (media >= 5.0)
    {
        cout << "Situacao: Recuperacao ??" << endl;
    }
    else
    {
        cout << "Situacao: Reprovado ?" << endl;
    }

    return 0;
}
