#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

bool isEqual(vector<int> &s1, vector<int> &s2)
{
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
        return false;

    vector<int> freqOfs1(26, 0);
    vector<int> freqOfs2(26, 0);

    for (auto &&i : s1)
        freqOfs1[i - 'a']++;

    int i = 0, j = 0;
    int m = s1.size();
    int n = s2.size();

    while (j < n)
    {
        freqOfs2[s2[j] - 'a']++;

        if (j - i + 1 == m)
        {
            if (isEqual(freqOfs1, freqOfs2))
                return true;
        }
        if (j - i + 1 < m)
            j++;
        else
        {
            freqOfs2[s2[i] - 'a']--;
            i++;
            j++;
        }
    }
    return false;
}

int main()
{
    return 0;
}