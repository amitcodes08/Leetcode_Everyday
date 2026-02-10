/*
    Leetcode Link : https://leetcode.com/problems/longest-balanced-subarray-i/
*/

// TC : O(n)
// SC : O(n)

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();

        int maxL = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> even;
            unordered_set<int> odd;

            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    even.insert(nums[j]);
                }
                else
                {
                    odd.insert(nums[j]);
                }

                if (even.size() == odd.size())
                {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }

        return maxL;
    }
};