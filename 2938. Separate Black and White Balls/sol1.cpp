#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: 1

long long minimumSteps(string s)
{
    long long zeroCnt = 0, ans = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
            zeroCnt++;
        else
            ans += zeroCnt;
    }
    return ans;
}

int main()
{
    return 0;
}