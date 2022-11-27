#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Time Complexity - O(N)   and Space Complexity is also O(N)...

int main()
{
    string name = "KamalSingh";
    string rev = "";
    stack<char> st;

    for (int i = 0; i < name.length(); i++)
    {
        st.push(name[i]);
    }

    while (!st.empty())
    {
        rev.push_back(st.top());
        st.pop();
    }

    cout << "reversed string is : " << rev;
}