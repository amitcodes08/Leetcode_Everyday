/*
    Leetcode Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
*/

// TC : O(n * max(nums[i])) 
// SC : O(1)


class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            bool found = false;
            for (int x = 0; x < nums[i]; x++)
            {
                if ((x | x + 1) == nums[i])
                {
                    ans.push_back(x);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};