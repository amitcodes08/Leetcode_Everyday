/*
    LeetCode Link : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
*/

// Approach - Simply do what is asked in the problem statement

// TC : O(nlogn)
// SC : O(n)

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> prefixGcd(n);
        int maxEl = -1;

        for (int i = 0; i < n; i++)
        {
            maxEl = max(maxEl, nums[i]);
            prefixGcd[i] = __gcd(nums[i], maxEl);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        int i = 0, j = n - 1;

        while (i < j)
        {
            sum += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};