#include <iostream>
using namespace std;
class linkedList
{
public:
    int data;
    linkedList *next;

    linkedList(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    linkedList *head;
    int size;
    int t;

    Stack(int size)
    {
        this->size = size;
        head = NULL;
        t = 0;
    }

    void push(int element)
    {
        if (t < size)
        {
            linkedList *newNode = new linkedList(element);
            newNode->next = head;
            head = newNode;
            t++;
        }
        else
            cout << "Stack OverFlow..." << endl;
    }

    void pop()
    {
        if (t > 0 && head != NULL)
        {
            linkedList *newNode;
            newNode = head;
            head = head->next;
            newNode->next = NULL;
            delete newNode;
        }
        else
            cout << "Stack UnderFlow..." << endl;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty...";
            return -1;
        }
        else
            return head->data;
    }

    void displayStack()
    {
        if (head == NULL)
        {
            cout << "Empty...";
            return;
        }

        linkedList *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    int size = 5;
    Stack st(size);

    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "The top Element is : " << st.top() << endl;
    cout << endl
         << "Stack is : ";
    st.displayStack();
    cout << endl
         << "Stack is empty ? " << st.isEmpty();
}
