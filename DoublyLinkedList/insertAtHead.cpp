#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        len++;
    }
    return len;
}

int main()
{
    node *firstNode = new node(10);
    node *head = firstNode;

    print(head);
    insertAtHead(head, 15);
    insertAtHead(head, 25);
    insertAtHead(head, 35);
    insertAtHead(head, 45);
    print(head);
    cout << getLength(head);
}