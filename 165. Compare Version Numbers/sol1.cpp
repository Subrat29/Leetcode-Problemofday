#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    int i = 0;
    int j = 0;
    int l1 = version1.length();
    int l2 = version2.length();

    while (i < l1 || j < l2)
    {
        int num1 = 0, num2 = 0;
        while (i < l1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < l2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 < num2)
            return -1;
        else if (num1 > num2)
            return 1;
        i++;
        j++;
    }
    return 0;
}

int main()
{
    return 0;
}