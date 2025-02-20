#include <bits/stdc++.h>
using namespace std;

// tc:
// For 1st char we have - 3 choice
//     n-1 char we have - 2 choice (because of condition that current char not similar to prev)
// 3 * 2*2*2*2....n = 3*2^n-1
// sc: n

void solve(int n, int &k, string &s, string &ans, vector<char> &arr)
{
    if (n < 0 || k < 0)
    {
        return;
    }

    if (n == 0)
    {
        k--;
        if (k == 0)
        {
            ans = s;
        }
        cout << "ans string: " << s << endl;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (k == 0 || !s.empty() && s.back() == arr[i])
        {
            continue;
        }
        s.push_back(arr[i]);
        solve(n - 1, k, s, ans, arr);
        s.pop_back();
    }
}

string getHappyString(int n, int k)
{
    vector<char> arr = {'a', 'b', 'c'};
    string ans = "", s = "";
    solve(n, k, s, ans, arr);
    return ans;
}

int main()
{
    return 0;
}