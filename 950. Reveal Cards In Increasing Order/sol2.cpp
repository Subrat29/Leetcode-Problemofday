#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ordering of the deck that would reveal the cards in decreasing order.

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    deque<int> q;
    q.push_front(deck[0]);
    for (int i = 1; i < deck.size(); i++)
    {
        q.push_front(q.back());
        q.pop_back();
        q.push_front(deck[i]);
    }
    vector<int> ans(q.begin(), q.end());
    return ans;
}

int main()
{
    vector<int> input = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = deckRevealedIncreasing(input);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}