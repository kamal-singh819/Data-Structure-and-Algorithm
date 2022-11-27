#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    int ans = 0;
    cout << "Enter a string containing brackets : ";
    cin >> str;

    if (str.length() % 2 == 1)
    {
        ans = -1;
        cout << endl
             << "Minimum cost to make string valid is : " << ans;
        return 0;
    }
    // agar length of string even hai ---
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
            st.push(ch);

        else
        {
            // close braces hoga...
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }
    // yaha tak valid parts of string remove ho chuka hai....
    int a = 0; // count for close braces
    int b = 0; // count for opening braces

    while (!st.empty())
    {
        if (st.top() == '{')
            b++;
        else
            a++;

        st.pop();
    }

    ans = (a + 1) / 2 + (b + 1) / 2;

    cout << endl
         << "Minimum cost to make string valid is : " << ans;
    return 0;
}