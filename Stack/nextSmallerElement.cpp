// CodeStudio

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(3);
    int n = vec.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int a = vec[i];
        while (a <= st.top())
            st.pop();

        ans[i] = st.top();
        st.push(a);
    }

    cout << "Initially vector was : ";
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    cout << "Ans is : ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}