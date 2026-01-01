#include <iostream>
#include <vector>
using namespace std;

// Classe base abstrata
class Forma
{
public:
    virtual double area() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Forma() {}
};

// Classe derivada Retângulo
class Retangulo : public Forma
{
private:
    double largura, altura;

public:
    Retangulo(double l, double a) : largura(l), altura(a) {}

    double area() const override
    {
        return largura * altura;
    }

    void mostrar() const override
    {
        cout << "Retangulo | Area: " << area() << endl;
    }
};

// Classe derivada Círculo
class Circulo : public Forma
{
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double area() const override
    {
        return 3.14159 * raio * raio;
    }

    void mostrar() const override
    {
        cout << "Circulo | Area: " << area() << endl;
    }
};

// Algoritmo polimórfico
void listarFormas(const vector<Forma *> &formas)
{
    cout << "\n--- LISTA DE FORMAS ---\n";
    for (const Forma *f : formas)
    {
        f->mostrar(); // polimorfismo
    }
}

int main()
{
    vector<Forma *> formas;
    int opcao;

    do
    {
        cout << "\n1 - Criar Retangulo";
        cout << "\n2 - Criar Circulo";
        cout << "\n3 - Listar Areas";
        cout << "\n0 - Sair\nOpcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            double l, a;
            cout << "Largura: ";
            cin >> l;
            cout << "Altura: ";
            cin >> a;
            formas.push_back(new Retangulo(l, a));
        }
        else if (opcao == 2)
        {
            double r;
            cout << "Raio: ";
            cin >> r;
            formas.push_back(new Circulo(r));
        }
        else if (opcao == 3)
        {
            listarFormas(formas);
        }

    } while (opcao != 0);

    // Liberação de memória
    for (Forma *f : formas)
        delete f;

    return 0;
}
