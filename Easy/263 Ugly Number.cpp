/*
    LeetCode Link : https://leetcode.com/problems/ugly-number/
*/

// TC : O(log n)
// SC : O(1)

class Solution
{
public:
    bool isUgly(int n)
    {
        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return n == 1;
    }
};