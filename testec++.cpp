#include <iostream>
#include <string>

using namespace std;

// Funções para exibir perguntas
void nomeDoObj1()
{
    cout << "Nome do objeto 1? " << endl;
}

void nomeDoObj2()
{
    cout << "Nome do objeto 2? " << endl;
}

// Função para somar IDs (frequência)
int frequency(int id1, int id2)
{
    return id1 + id2;
}

int main()
{
    nomeDoObj1();
    nomeDoObj2();

    // Definindo a struct
    struct Objeto
    {
        int id;
        string nome;
    };

    // Criando objetos
    Objeto obj1, obj2;

    obj1.id = 1;
    obj1.nome = "objeto1";

    obj2.id = 2;
    obj2.nome = "objeto2";

    // Exibindo objetos
    cout << "ID: " << obj1.id << " Nome: " << obj1.nome << endl;
    cout << "ID: " << obj2.id << " Nome: " << obj2.nome << endl;

    // Exibindo letras dos nomes
    cout << "\nLetras do nome do obj1:" << endl;
    for (char c : obj1.nome)
    {
        cout << c << endl;
    }

    cout << "\nLetras do nome do obj2:" << endl;
    for (char c : obj2.nome)
    {
        cout << c << endl;
    }

    // Exibindo os nomes enquanto ambos não estão vazios
    if (!obj1.nome.empty() && !obj2.nome.empty())
    {
        cout << "\nAmbos os nomes juntos: " << obj1.nome << " " << obj2.nome << endl;
    }

    // Chamando a função frequency
    int freq = frequency(obj1.id, obj2.id);
    cout << "\nA frequência exata é de: " << freq << endl;

    return 0;
}