
//Reverse a Linked List using Recursion

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

// To display the linked list-----------------------------------

void printLL(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(node *&head, node *curr, node *prev) // reverse function
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    reverse(head, curr->next, curr);
    curr->next = prev;
}

int main()
{
    int i = 10;
    node *firstNode = new node(i);

    node *head = firstNode;
    node *tail = firstNode;

    insertAtTail(tail, 12);
    insertAtTail(tail, 20);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    printLL(head);

    //-------second approach to reverse a linked list(function is written above)----
    node *prev = NULL;
    node *curr = head;
    reverse(head, curr, prev);
    printLL(head);
}
