#include <iostream>
#include <stack>
using namespace std;

void insertSortedWay(stack<int> &st, int element)
{
    // base case
    if (st.empty() || st.top() < element)
    {
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();
    insertSortedWay(st, element); // recursive call
    st.push(num);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);

    insertSortedWay(st, num); // insert all the elements in sorted order
}

int main()
{
    stack<int> st;
    int arr[6] = {1, -2, -3, 4, 5, -4};
    for (int i = 0; i < 6; i++)
    {
        st.push(arr[i]);
    }

    sortStack(st);

    for (int i = 0; i < 6; i++)
    {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
}