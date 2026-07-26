/*
    LeetCode Link : https://leetcode.com/problems/maximum-product-of-three-numbers/
*/

// Approach (Sorting)
// T.C : O(nlogn)
// S.C : O(1)

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int result1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int result2 = nums[0] * nums[1] * nums[n - 1];

        return max(result1, result2);
    }
};

// Approach (One Pass)
// T.C : O(n)
// S.C : O(1)

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;     

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3)
            {
                max3 = nums[i];
            }

            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2)
            {
                min2 = nums[i];
            }
        }

        int result1 = max1 * max2 * max3;
        int result2 = min1 * min2 * max1;

        return max(result1, result2);
    }
};