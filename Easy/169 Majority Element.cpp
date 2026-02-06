/*
    Leetcode Link : https://leetcode.com/problems/majority-element/description/
*/

// Optimal Soln (Boyre Moore Algorithm)

// TC : O(n)
// SC : O(1)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int maj = NULL;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj)
            {
                count++;
            }
            else if (count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            else
            {
                count--;
            }
        }
        // we can also verify here
        return maj;
    }
};