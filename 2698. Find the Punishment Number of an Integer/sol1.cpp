class Solution
{
public:
    bool isPartitionNo(string &str, int &target)
    {
        if (target < 0)
            return false;
        if (str == "" && target == 0)
            return true;

        bool ans = false;
        for (int i = 0; i < str.size(); i++)
        {
            string left = str.substr(0, i + 1);
            string right = str.substr(i + 1);
            int leftNum = stoi(left);
            if (isPartitionNo(right, target - leftNum))
            {
                ans = true;
                break;
            }
        }
        return ans;
    }

    int punishmentNumber(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int sqr = i * i;
            if (isPartitionNo(to_string(sqr), i))
            {
                sum += sqr;
            }
        }
        return sum;
    }
};

// isPartitionNo(str, target)	O(2^d * d) ≈ O(2^(log n) * log n)	O(log n)
// punishmentNumber(n)	O(n log n 2^(log n))	O(log n)