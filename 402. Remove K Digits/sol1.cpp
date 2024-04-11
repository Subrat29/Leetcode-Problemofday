#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tle on last case
string removeKdigits(string num, int k)
{
    while (k > 0)
    {
        int i;
        for (i = 0; i < num.size() - 1 && num[i] <= num[i + 1]; i++)
            ;
        num.erase(i, 1);
        k--;
    }

    // leading 0s
    int idx = 0;
    while (!num.empty() && num[idx] == '0')
        idx++;
    num.erase(0, idx);

    return num == "" ? "0" : num;
}

int main()
{
    string num = "112";
    int k = 1;
    string ans = removeKdigits(num, k);
    cout << "ans: " << ans;
    return 0;
}