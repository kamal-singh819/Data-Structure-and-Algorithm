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

void insertAtTail(node *&head, node *&tail, int d) // insertion at tail in a Linked list------------
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

void print(node *&head) // display linked list------------------------------------------
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head) // find length of a linked list-------------------------
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

// deletion---------------------------------------------------------
void deleteAnyNode(node *&head, int position)
{
    node *temp = head;

    if (position == 1)
    {
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }
    int i = 1;

    node *temp1 = NULL;
    while (i < position)
    {
        temp1 = temp;
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        temp1->next = NULL;
        temp->prev = NULL;
        return;
    }
    temp1->next = temp->next;
    temp->next->prev = temp1;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    print(head);

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    print(head);

    deleteAnyNode(head, 1 );
    print(head);

    // cout << getLength(head);
}