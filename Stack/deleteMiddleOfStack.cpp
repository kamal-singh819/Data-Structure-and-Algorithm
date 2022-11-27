#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &s, int count)
{
    if (count == s / 2)
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();
    solve(st, s, count + 1);
    st.push(num);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    int s = st.size();
    cout << "Size of Stack is : " << st.size() << endl;

    int count = 0;
    solve(st, s, count);

    cout << "Size of Stack is : " << st.size() << endl;

    for (int i = 0; i < s; i++)
    {
        int t = st.top();
        cout << t << " ";
        st.pop();
    }
}