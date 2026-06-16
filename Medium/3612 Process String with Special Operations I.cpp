/*
    LeetCode Link : https://leetcode.com/problems/process-string-with-special-operations-i/description/
*/


// Approach : Simulation
// TC : O(n)
// SC : O(n)

class Solution
{
public:
    string processStr(string s)
    {
        string result = "";
        for (auto it : s)
        {
            if (it == '*')
            {
                if (result.size())
                {
                    result.pop_back();
                }
            }
            else if (it == '#')
            {
                result += result;
            }
            else if (it == '%')
            {
                result = string(result.rbegin(), result.rend());
            }
            else
            {
                result += it;
            }
        }
        return result;
    }
};