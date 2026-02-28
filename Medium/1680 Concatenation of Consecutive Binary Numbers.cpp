/*
    Leetcode Link : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/

// TC : O(n)
// SC : O(1)

class Solution
{
public:
    int M = 1e9 + 7;
    int concatenatedBinary(int n)
    {
        long result = 0;
        int digits = 0;
        for (int num = 1; num <= n; num++)
        {
            if ((num & (num - 1)) == 0)
                digits++;
            result = ((result << digits) % M + num) % M;
        }
        return result;
    }
};