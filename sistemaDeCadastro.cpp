#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
// sistema de cadastro simplificado.
struct Cliente
{
    std::string nome;
    std::string email;
    int idade;
};

void salvar(const std::vector<Cliente> &clientes)
{
    std::ofstream arquivo("clientes.txt");
    for (const auto &c : clientes)
    {
        arquivo << c.nome << ";" << c.email << ";" << c.idade << "\n";
    }
}

void carregar(std::vector<Cliente> &clientes)
{
    std::ifstream arquivo("clientes.txt");
    if (!arquivo.is_open())
        return;

    clientes.clear();
    Cliente c;
    std::string linha;
    while (std::getline(arquivo, linha))
    {
        size_t pos1 = linha.find(';');
        size_t pos2 = linha.find(';', pos1 + 1);
        c.nome = linha.substr(0, pos1);
        c.email = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        c.idade = std::stoi(linha.substr(pos2 + 1));
        clientes.push_back(c);
    }
}

void listar(const std::vector<Cliente> &clientes)
{
    if (clientes.empty())
    {
        std::cout << "Nenhum cliente cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < clientes.size(); i++)
    {
        std::cout << i + 1 << ". " << clientes[i].nome << " - "
                  << clientes[i].email << " - "
                  << clientes[i].idade << " anos\n";
    }
}

int main()
{
    std::vector<Cliente> clientes;
    carregar(clientes);

    int opcao;
    do
    {
        std::cout << "\n=== SISTEMA DE CADASTRO ===\n";
        std::cout << "1. Adicionar cliente\n";
        std::cout << "2. Listar clientes\n";
        std::cout << "3. Editar cliente\n";
        std::cout << "4. Remover cliente\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == 1)
        {
            Cliente c;
            std::cout << "Nome: ";
            std::getline(std::cin, c.nome);
            std::cout << "Email: ";
            std::getline(std::cin, c.email);
            std::cout << "Idade: ";
            std::cin >> c.idade;
            std::cin.ignore();
            clientes.push_back(c);
            salvar(clientes);
        }
        else if (opcao == 2)
        {
            listar(clientes);
        }
        else if (opcao == 3)
        {
            listar(clientes);
            int id;
            std::cout << "Qual ID editar? ";
            std::cin >> id;
            std::cin.ignore();
            if (id >= 1 && id <= (int)clientes.size())
            {
                std::cout << "Novo nome: ";
                std::getline(std::cin, clientes[id - 1].nome);
                std::cout << "Novo email: ";
                std::getline(std::cin, clientes[id - 1].email);
                std::cout << "Nova idade: ";
                std::cin >> clientes[id - 1].idade;
                std::cin.ignore();
                salvar(clientes);
            }
        }
        else if (opcao == 4)
        {
            listar(clientes);
            int id;
            std::cout << "Qual ID remover? ";
            std::cin >> id;
            std::cin.ignore();
            if (id >= 1 && id <= (int)clientes.size())
            {
                clientes.erase(clientes.begin() + id - 1);
                salvar(clientes);
            }
        }
    } while (opcao != 0);

    return 0;
}