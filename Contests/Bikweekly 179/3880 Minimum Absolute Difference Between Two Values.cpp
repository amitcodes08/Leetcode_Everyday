/*
    Leetcode Link : https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/
*/

// TC : O(N^2)
// SC : O(1)

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums)
    {
        int n = nums.size();

        int minDiff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == 1 && nums[j] == 2)
                {
                    minDiff = min(minDiff, abs(i - j));
                }
            }
        }

        return minDiff == INT_MAX ? -1 : minDiff;
    }
};