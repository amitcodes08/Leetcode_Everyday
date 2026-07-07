/*
    LeetCode Link : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i
*/

// Approach 1 : Convert into string and stimulate
// TC : O(logn)
// SC : O(logn)

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0;
        long long sum = 0;
        string s = to_string(n);
        for (char c : s)
        {
            int d = c - '0';
            sum += d;
            if (d > 0)
            {
                x = x * 10 + d;
            }
        }
        return x * sum;
    }
};

// Approach 2 : traverse from right to left find x and sum
// TC : O(logn)
// SC : O(1)

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0, sum = 0, pow10 = 1;
        while (n > 0)
        {
            int d = n % 10;
            sum += d;
            if (d > 0)
            {
                x += d * pow10;
                pow10 *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};