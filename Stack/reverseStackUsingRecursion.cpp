#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(num);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    reverseStack(st); // remaining stack is reversed using recursion
    // now insert num at bottom

    insertAtBottom(st, num);
}

int main()
{
    stack<int> st;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        st.push(arr[i]);
    }

    reverseStack(st);

    for (int i = 0; i < 6; i++)
    {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
}