#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: n

int minAddToMakeValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty())
        {
            if (st.top() == '(' && s[i] == ')')
                st.pop();
            else
                st.push(s[i]);
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.size();
}

int main()
{
    return 0;
}