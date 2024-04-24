#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tribonacci(int n)
{
    // base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main()
{
    return 0;
}