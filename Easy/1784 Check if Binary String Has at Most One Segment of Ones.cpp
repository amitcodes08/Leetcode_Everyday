/*
    Leetcode Link : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
*/

// TC : O(1)
// SC : O(1)

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        return s.find("01") == string::npos;
    }
};