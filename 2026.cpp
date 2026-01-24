#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Classe base abstrata
class Objeto
{
public:
    virtual void som() const = 0;
    virtual void radio() const = 0;
    virtual ~Objeto() = default;
};

// Classe derivada
class Tecnologia : public Objeto
{
public:
    void som() const override
    {
        cout << "Som de objeto tecnologico" << endl;
    }

    void radio() const override
    {
        cout << "Radio digital tecnologico ligado" << endl;
    }
};

int main()
{
    vector<unique_ptr<Objeto>> objetos;

    while (true)
    {
        cout << "\n MENU" << endl;
        cout << "1 - Adicionar radio tecnologico" << endl;
        cout << "2 - Listar objetos" << endl;
        cout << "3 - Sair" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 1)
        {
            objetos.push_back(make_unique<Tecnologia>());
            cout << "Radio tecnologico adicionado!" << endl;
        }
        else if (opcao == 2)
        {
            if (objetos.empty())
            {
                cout << "Nenhum objeto cadastrado." << endl;
            }
            else
            {
                for (const auto &o : objetos)
                {
                    o->som();
                    o->radio();
                    cout << "-------------------" << endl;
                }
            }
        }
        else if (opcao == 3)
        {
            cout << "Saindo do programa..." << endl;
            break;
        }
        else
        {
            cout << "Opcao invalida!" << endl;
        }
    }

    return 0;
}
