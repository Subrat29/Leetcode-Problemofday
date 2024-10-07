#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: n

int minLength(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            string str;
            str.push_back(st.top());
            str.push_back(s[i]);

            if (str == "AB" || str == "CD")
                st.pop();
            else
                st.push(s[i]);
        }
    }
    return st.size();
}

int main()
{
    return 0;
}