/*
    Leetcode Link : https://leetcode.com/problems/separate-the-digits-in-an-array/
*/

// Approach-1 (Brute Force)
// T.C : O(n * log10(max(nums[i])))
// S.C : O(n * log10(max(nums[i])))

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            vector<int> digit;
            while (num > 0)
            {
                int ld = num % 10;
                digit.push_back(ld);
                num /= 10;
            }

            for (int j = digit.size() - 1; j >= 0; j--)
            {
                result.push_back(digit[j]);
            }
        }
        return result;
    }
};
