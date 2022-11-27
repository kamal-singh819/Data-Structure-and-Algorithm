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

void insertAtHead(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int d)
{
    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtAnyPos(node *&head, node *&tail, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    node *current = head;

    int i = 1;
    while (i < position - 1)
    {
        current = current->next;
        i++;
    }

    if (current->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    node *temp = new node(d);
    temp->next = current->next;
    current->next->prev = temp;
    current->next = temp;
    temp->prev = current;
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
    // node *firstNode = new node(10);
    node *head = NULL;
    node *tail = NULL; // if we initially empty LL, fill first node separately using if conditions like above...

    print(head);

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    print(head);
    int position = 5;

    insertAtAnyPos(head, tail, 60, position);
    print(head);

    cout << getLength(head);
}