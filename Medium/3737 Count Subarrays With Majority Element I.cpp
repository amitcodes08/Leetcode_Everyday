/*
    Leetcode Link : https://leetcode.com/problems/count-subarrays-with-majority-element-i/
*/

// TC : O(n^2)
// SC : O(n)

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[nums[j]]++;
                if (mp[target] > (j - i + 1) / 2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};