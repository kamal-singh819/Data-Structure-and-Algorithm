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

void deleteNode(node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty, please check again.." << endl;
        return;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (curr == prev) // if only one node in the list
            tail = NULL;
        else if (tail == curr) // when greater than two node in the list
            tail = prev;
        curr->next = NULL;
        delete curr;
    }
}

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
    if (tail == NULL)
    {
        cout << "List is empty..";
        return;
    }
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

    // print(tail);
    // insertNode(tail, 3, 6);
    // print(tail);
    // insertNode(tail, 6, 8);
    // print(tail);
    // insertNode(tail, 6, 10);
    // print(tail);
    // insertNode(tail, 3, 15);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}