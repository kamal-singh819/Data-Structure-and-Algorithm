#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void printLL(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int i = 10;
    node *firstNode = new node(i);

    node *head = firstNode; // to insert at start
    

    printLL(head);
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printLL(head);
}
