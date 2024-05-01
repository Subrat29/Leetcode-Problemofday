#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch)
{

    int idx = -1;
    for (int i = 0; i < word.length(); i++)
    {
        if (ch == word[i])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1 || 0)
        return word;

    int p1 = 0;

    while (p1 < idx)
    {
        char temp = word[idx];
        word[idx] = word[p1];
        word[p1] = temp;
        p1++;
        idx--;
    }
    return word;
}

int main()
{
    return 0;
}