/*
    Leetcode Link : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

// TC : O(N * K)
// SC : O(N * K) in worst case when all substrings are unique, but generally O(2^K) since there are at most 2^K unique binary codes of size K.

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> st;
        int codes = 1 << k;

        for (int i = k; i <= s.length(); i++)
        {
            string sub = s.substr(i - k, k);

            if (!st.count(sub))
            {
                st.insert(sub);
                codes--;
            }

            if (codes == 0)
            {
                return true;
            }
        }

        return false;
    }
};