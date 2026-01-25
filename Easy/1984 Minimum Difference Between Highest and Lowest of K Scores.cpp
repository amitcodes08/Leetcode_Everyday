/*
    Leetcode Link : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
*/

// TC : O(NlogN)
// SC: O(1)

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();

        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        int i = 0, j = k - 1;

        while (j < n)
        {
            int minEle = nums[i];
            int maxEle = nums[j];

            minDiff = min(minDiff, maxEle - minEle);

            i++;
            j++;
        }

        return minDiff;
    }
};