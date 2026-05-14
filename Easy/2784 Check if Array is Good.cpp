/*
    LeetCode Link: https://leetcode.com/problems/check-if-array-is-good/
*/

// Approach - Sort the array and check if the first n-1 elements are 1 to n-1 and the last element is n
// T.C : O(nlogn) due to sorting
// S.C : O(1)

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return false;
            }
        }
        return nums[n] == n;
    }
};