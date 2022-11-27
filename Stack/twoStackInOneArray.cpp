#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];

        top1 = -1;
        top2 = size;
    }

    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = elememt;
        }
        else
            cout << "Stack OverFlow..." << endl;
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
            cout << "Stack OverFlow..." << endl;
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
        }

        else
            return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
        }

        else
            return -1;
    }
};

int main()
{
    Stack st(6);
    st.push1(1);
    st.push1(2);
    st.push1(2);
    st.push2(2);
    st.push2(2);
    st.push1(2);
    st.push1(1);
}