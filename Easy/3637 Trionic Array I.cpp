/*
    https://leetcode.com/problems/trionic-array-i/description/
*/

// TC : O(N)
// SC : O(1)

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int i = 1;
        int n = nums.size();

        while (i < n && nums[i] > nums[i - 1])
        {
            i++;
        }
        int p = i - 1;

        while (i < n && nums[i] < nums[i - 1])
        {
            i++;
        }
        int q = i - 1;

        while (i < n && nums[i] > nums[i - 1])
        {
            i++;
        }

        return (p >= 1) && (q > p) && (i == n) && (i - 1 > q);
    }
};