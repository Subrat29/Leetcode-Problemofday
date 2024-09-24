#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// m = size of arr1
// n = size of arr2
// d 1 = maximum number of digits in any integer in arr1
// d 2= maximum number of digits in any integer in arr2

// tc: m.d1 + n>d2
// sc: m.d1

int countDigits(int number)
{
    int count = 0;
    if (number == 0)
        return 1; // Special case for 0
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> st;
    for (int i = 0; i < arr1.size(); i++)
    {
        int n = arr1[i];
        while (n)
        {
            st.insert(n);
            n = n / 10;
        }
    }

    int ans = 0;
    for (int i = 0; i < arr2.size(); i++)
    {
        int n = arr2[i];
        while (n)
        {
            if (st.find(n) != st.end())
            {
                ans = max(ans, countDigits(n));
            }
            n = n / 10;
        }
    }
    return ans;
}

int main()
{
    return 0;
}