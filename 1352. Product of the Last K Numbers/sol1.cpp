#include <bits/stdc++.h>
using namespace std;

// tc of add() - O(1)
// sc of add() - O(1)

// tc of getProc() - O(1)
// sc of getProc() - O(1)

class ProductOfNumbers
{
public:
    vector<int> arr;
    ProductOfNumbers() { arr.push_back(1); }

    void add(int num)
    {
        if (num == 0)
        {
            arr = {1};
        }
        else
        {
            arr.push_back(arr.back() * num);
        }
    }

    int getProduct(int k)
    {
        int n = arr.size();
        if (n < k + 1)
            return 0;
        return arr[n - 1] / arr[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main()
{
    return 0;
}