/*
    Leetcode Link : https://leetcode.com/problems/transformed-array/description/
*/

// TC : O(n)
// SC : O(1)

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int shift = nums[i] % n;
            int newInd = (i + shift) % n;

            if (newInd < 0)
            {
                newInd += n;
            }

            result[i] = nums[newInd];
        }

        return result;
    }
};