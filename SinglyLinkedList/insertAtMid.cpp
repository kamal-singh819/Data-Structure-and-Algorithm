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

// When we have tail pointer----------------------------------

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);

    tail->next = temp;
    tail = temp;
}

// If we don't have tail pointer then insert at end-----------

void insertAtMid(node *&head, int d, int position)
{
    node *current = head; // to traverse the linked list

    node *temp = new node(d);

    int i = 1;
    while (i < position - 1)
    {
        current = current->next;
        i++;
    }

    temp->next = current->next;
    current->next = temp;
}

// To display the linked list-----------------------------------

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

    node *head = firstNode;
    node *tail = firstNode; // to insert at end(if we have only one node we can make it tail
                            // directly otherwise traverse using while loop to make tail to the last node)

    printLL(head);
    insertAtTail(tail, 12);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    printLL(head);

    int position = 7;
    insertAtMid(head, 60, position);
    printLL(head);
}
