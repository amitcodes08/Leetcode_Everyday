/*
    Leetcode Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/
*/

// TC : O(n*32)
// SC : O(1)

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
            {
                ans.push_back(-1);
                continue;
            }

            bool found = false;

            for (int p = 1; p < 32; p++)
            {
                if ((nums[i] & (1 << p)) > 0)
                {
                    continue;
                }

                int prev = p - 1;

                int x = (nums[i] ^ (1 << prev));

                ans.push_back(x);
                found = true;
                break;
            }

            if (!found)
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};