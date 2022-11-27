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

int getLength(node *temp)
{
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
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

    //-----------------------the approach to finad the middle ---
    int len = getLength(head);
    node *middle = head;
    int cnt = 1;
    while (cnt < (len / 2) + 1)
    {
        middle = middle->next;
        cnt++;
    }

    // return middle;
    cout << endl
         << "The Middle is : " << middle->data;
}
