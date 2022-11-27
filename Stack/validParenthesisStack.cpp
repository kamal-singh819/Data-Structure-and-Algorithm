#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool matched(char ch, char topp)
{
    if (topp == '(' && ch == ')')
        return true;
    else if (topp == '{' && ch == '}')
        return true;
    else if (topp == '[' && ch == ']')
        return true;

    else
        return false;
}

bool isValidParenthesis(string str)
{
    int s = str.length();
    stack<int> stac;

    for (int i = 0; i < s; i++)
    {
        // if opening bracket, push in stack
        // if closing bracket, check stack top if same type then pop, otherwise return false
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
            stac.push(ch);

        else
        {
            if (!stac.empty())
            {
                char topp = stac.top();
                if (matched(ch, topp))
                    stac.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (stac.empty())
        return true;

    else
        return false;
}

int main()
{

    string str = "[{(])}]";

    bool ans = isValidParenthesis(str);

    cout << "is valid : " << ans;
    return 0;
}