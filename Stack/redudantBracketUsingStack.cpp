#include <iostream>
#include <stack>
using namespace std;

bool isRedundantBracket(string &str)
{
    stack<char> st;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // ya to koi alphabet hoga ya phir closing bracket
            if (ch == ')')
            {
                bool redundant = true;
                while (st.top() != '(')
                {
                    char topp = st.top();
                    if (topp == '+' || topp == '-' || topp == '*' || topp == '/')
                        redundant = false;
                    st.pop();
                }

                if (redundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string str = "(b)*(a+b)";

    cout << isRedundantBracket(str);
}