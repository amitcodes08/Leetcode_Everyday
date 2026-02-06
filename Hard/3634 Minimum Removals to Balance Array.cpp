/*
    Leetcode Link : https://leetcode.com/problems/minimum-removals-to-balance-array/description/
*/

// TC : O(nlogn + 2*n) ~ O(nlogn)
// SC : O(1)

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        int L = 1;
        int mini = nums[0];
        int maxi = nums[0];

        while (j < n)
        {
            maxi = nums[j];
            mini = nums[i];

            while (i < j && maxi > (long long)k * mini)
            {
                i++;
                mini = nums[i];
            }

            L = max(L, j - i + 1);
            j++;
        }

        return n - L;
    }
};
