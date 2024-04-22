#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> deadend(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    if (target == "0000")
        return 0;
    if (deadend.find("0000") != deadend.end())
        return -1;

    int minTurns = 0;
    queue<string> q;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty())
    {
        int l = q.size();
        while (l--)
        {
            string front = q.front();
            q.pop();

            if (front == target)
                return minTurns;

            for (int i = 0; i < 4; i++)
            {
                string up = front, down = front;
                char upChar = up[i];
                char downChar = down[i];

                up[i] = (upChar == '9' ? '0' : upChar + 1);
                down[i] = (downChar == '0' ? '9' : upChar - 1);

                if (visited.find(up) == visited.end() && deadend.find(up) == deadend.end())
                {
                    q.push(up);
                    visited.insert(up);
                }
                if (visited.find(down) == visited.end() && deadend.find(down) == deadend.end())
                {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        minTurns++;
    }
    return -1;
}

int main()
{
    return 0;
}
