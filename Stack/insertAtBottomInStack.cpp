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

int main()
{
    stack<int> st;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        st.push(arr[i]);
    }

    cout << "Size before insertion : " << st.size() << endl;
    int element = 10;
    insertAtBottom(st, element);
    cout << "Size after insertion : " << st.size();
}
