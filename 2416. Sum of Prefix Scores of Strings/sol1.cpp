#include <bits/stdc++.h>
using namespace std;

// n = words size
// m = max len of a word

// tc: n*m
// sc: n*m

vector<int> sumPrefixScores(vector<string> &words)
{
    // step1: store every prefix substring in map with its count
    unordered_map<string, int> mp;

    // Populate the map with prefix counts
    for (const string &word : words)
    {
        string curr = "";
        for (char ch : word)
        {
            curr += ch; // Build the prefix incrementally
            mp[curr]++;
        }
    }

    // Step 2: Calculate prefix scores for each word
    vector<int> ans;
    for (const string &word : words)
    {
        int cnt = 0;
        string curr = "";
        for (char ch : word)
        {
            curr += ch;      // Build the prefix incrementally
            cnt += mp[curr]; // Add count of current prefix
        }
        ans.push_back(cnt);
    }

    return ans;
}

int main()
{
    return 0;
}