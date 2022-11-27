#include <iostream>
#include <stack>
using namespace std;

//-----------------------------------Implementation of Stack--------------------------------------
class Stack
{
public:
    int *arr;
    int size;
    int top;

public:
    Stack(int size)
    { // constructor
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack OverFlow..." << endl;
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack is UnderFlow..." << endl;

        else
            top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty...";
            return -1;
        }
        else
            return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void display()
    {
        int i = top;
        cout << "The Stack is : ";
        while (i >= 0)
        {
            cout << arr[i] << " ";
            i--;
        }
    }
};

int main()
{
    int size = 5;
    Stack st(size);
    // Stack *st = new Stack(size); //stack variable is created dynamically

    int temp[5] = {23, 24, 25, 26, 27};

    for (int i = 0; i < 5; i++)
    {
        st.push(temp[i]);
    }

    st.display(); // display whole stack

    cout << endl
         << "The peak element is : " << st.peek() << endl;

    st.pop();
    st.display();

    //------------------Stack in STL--------------//
    stack<int> s;
    s.push(10);
    cout << endl
         << "Top is : ";
    cout << s.top() << endl;

}