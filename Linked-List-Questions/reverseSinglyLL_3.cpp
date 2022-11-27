
// Reverse a Linked List using Recursion

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

node *reverse(node *&head) // reverse function
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *smallHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
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

    //-------third approach to reverse a linked list(function is written above)----
    head = reverse(head);
    printLL(head);
}
