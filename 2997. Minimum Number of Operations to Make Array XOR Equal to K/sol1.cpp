#include <bits/stdc++.h>
using namespace std;

// Note: However, if we observe closely, we notice the result of XOR is 1 when the number of 1 bits is
// odd and 0 otherwise.

int minOperations(vector<int> &nums, int k)
{
    int Xor = 0;
    for (auto &&i : nums)
    {
        Xor ^= i;
    }

    int cnt = 0;
    while (Xor || k)
    {
        if (Xor % 2 != k % 2)
            cnt++;

        k /= 2;
        Xor /= 2;
    }
    return cnt;
}

int main()
{
    return 0;
}