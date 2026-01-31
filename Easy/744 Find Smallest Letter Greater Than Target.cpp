/*
    Leetcode Link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
*/

// TC: O(N)
// SC : O(1)

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char ans = letters[0];

        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                ans = letters[i];
                break;
            }
        }

        return ans;
    }
};