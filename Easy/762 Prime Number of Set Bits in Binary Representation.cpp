/*
    Leetcode Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
*/

// TC : O(n) where n is the number of integers in the range [L, R]
// SC : O(1)

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        unordered_set<int> primeNo = {2, 3, 5, 7, 11, 13, 17, 19};
        int result = 0;
        for (int i = left; i <= right; i++)
        {
            int setBits = __builtin_popcount(i);

            if (primeNo.count(setBits))
            {
                result += 1;
            }
        }

        return result;
    }
};