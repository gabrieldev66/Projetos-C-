#include <iostream>
using namespace std;

// Classe base
class Pessoa
{
private:
    int idade; // acesso restrito

protected:
    string nome; // acessível por herança

public:
    // construtor
    Pessoa(string n, int i)
    {
        nome = n;
        idade = i;
    }

    // método público
    void mostrarDados()
    {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }

    // método público que acessa atributo private
    int getIdade()
    {
        return idade;
    }
};

// Classe derivada
class Aluno : public Pessoa
{
private:
    float nota;

public:
    Aluno(string n, int i, float nt) : Pessoa(n, i)
    {
        nota = nt;
    }

    void mostrarAluno()
    {
        cout << "Aluno: " << nome << endl; // nome é protected
        cout << "Nota: " << nota << endl;
        cout << "Idade: " << getIdade() << endl;
    }
};

int main()
{
    Pessoa p("Dafinni", 25);
    p.mostrarDados();

    cout << "------------------" << endl;

    Aluno a("Gabriel", 27, 8.5);
    a.mostrarAluno();

    return 0;
}
