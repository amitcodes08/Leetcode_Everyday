/*
    LeetCode Link : https://leetcode.com/problems/gcd-of-odd-and-even-sums/
*/

// Approach : Straight forward
// T.C : O(log n)
// S.C : O(1)

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return __gcd(n * n, n * (n + 1));
    }
};