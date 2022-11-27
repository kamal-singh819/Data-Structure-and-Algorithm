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

insertAtMid(node *&head, int d, int position)
{
    node *temp = new node(d);
    node *curr1 = NULL;
    node *curr2 = head;
    int i = 1;
    while (i < position)
    {
        curr1 = curr2;
        curr2 = curr2->next;
        i++;
    }

    curr1->next = temp;
    curr2->prev = temp;
    temp->next = curr2;
}

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
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
    node *tail = firstNode;

    print(head);

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    print(head);
    int position = 6;

    insertAtMid(head, 20, position);
    print(head);

    cout << getLength(head);
}