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

void insertNode(node *&tail, int element, int d)
{
    // empty list---
    if (tail == NULL)
    {
        node *first = new node(d);
        tail = first;
        first->next = first;
    }

    else
    {
        // non empty list
        // assuming that 'element' is already present in the list and we will insert after the 'element'...
        node *curr = tail;

        while (curr->data != element)
            curr = curr->next;

        // element found
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(node *tail)
{
    node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

int main()
{
    node *tail = NULL;

    insertNode(tail, 5, 3);

    print(tail);
    insertNode(tail, 3, 6);
    print(tail);
    insertNode(tail, 6, 8);
    print(tail);
    insertNode(tail, 6, 10);
    print(tail);
    insertNode(tail, 3, 15);
    print(tail);

    return 0;
}