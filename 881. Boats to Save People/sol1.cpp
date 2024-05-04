#include <bits/stdc++.h>
using namespace std;

// sort array
// if smallerwt+largerwt within the limit -> same boat i++ , j--
// otherwise larger_wt will sit alone -> j--

// tc: nlogn, sc: 1

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int boats = 0;
    int i = 0;
    int j = people.size() - 1;
    while (i < j)
    {
        if (people[i] + people[j] <= limit)
        {
            boats++;
            i++;
            j--;
        }
        else if (people[i] + people[j] > limit)
        {
            j--;
        }
    }
    return boats;
}

int main()
{
    return 0;
}