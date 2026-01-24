/*
    Leetcode Link : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/
*/

//TC : O(N^2)
//SC : O(1)

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int minSum = INT_MAX;

        int ind = -1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + nums[i + 1] < minSum)
            {
                minSum = nums[i] + nums[i + 1];
                ind = i;
            }
        }

        return ind;
    }
    int minimumPairRemoval(vector<int> &nums)
    {
        int op = 0;

        while (!is_sorted(nums.begin(), nums.end()))
        {
            int ind = minPairSum(nums);

            nums[ind] += nums[ind + 1];

            nums.erase(nums.begin() + ind + 1);
            op++;
        }

        return op;
    }
};