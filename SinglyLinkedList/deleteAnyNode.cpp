#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void deletionAnyPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position == 1)
    {
        temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
        return;
    }
    int i = 1;
    Node *current = head;
    Node *prev = NULL;
    while (i < position)
    {
        prev = current;
        current = current->next;
        i++;
    }
    temp = current;
    prev->next = current->next;
    temp->next = NULL;
    delete temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *firstNode = new Node(1);
    Node *head = firstNode;
    Node *tail = firstNode;

    int n;
    cout << "Enter the value of n+1 : ";
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int data;
        cout << "Enter the data : ";
        cin >> data;

        insertAtTail(tail, data);
    }

    int position;
    cout << "Enter position : ";
    cin >> position;
    deletionAnyPosition(head, position);
    cout << endl
         << "Linked List is : ";
    printLinkedList(head);
    return 0;
}