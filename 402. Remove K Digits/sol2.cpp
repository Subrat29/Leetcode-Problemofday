#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;
    st.push(num[0]);
    for (int i = 1; i < num.size(); i++)
    {
        while (k && !st.empty() && st.top() > num[i])
        {
            k--;
            st.pop();
        }
        st.push(num[i]);

        // leading 0's
        if (st.size() == 1 && st.top() == '0')
            st.pop();
    }

    // string like: 1234
    while (k && !st.empty())
    {
        st.pop();
        k--;
    }

    num = "";
    while (!st.empty())
    {
        num.push_back(st.top());
        st.pop();
    }
    reverse(num.begin(), num.end());

    if (num == "")
        return "0";
    return num;
}

int main()
{
    return 0;
}