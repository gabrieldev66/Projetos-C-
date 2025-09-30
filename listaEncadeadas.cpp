#include <iostream>
using namespace std;

// Nó da lista
struct Node
{
    int data;   // valor armazenado
    Node *next; // ponteiro para o próximo nó
};

// Classe Lista Encadeada
class LinkedList
{
private:
    Node *head; // ponteiro para o primeiro nó

public:
    // Construtor
    LinkedList()
    {
        head = nullptr;
    }

    // Inserir no início
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Inserir no final
    void insertAtEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Remover um elemento
    void remove(int value)
    {
        if (head == nullptr)
        {
            cout << "Lista vazia!" << endl;
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Valor nao encontrado!" << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Exibir lista
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destrutor para liberar memória
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

// Programa principal
int main()
{
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "Lista: ";
    list.display();

    list.remove(20);
    cout << "Depois de remover 20: ";
    list.display();

    return 0;
}
