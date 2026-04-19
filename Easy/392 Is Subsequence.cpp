/*
    Leetcode Link : https://leetcode.com/problems/is-subsequence/description/
*/

// TC : O(N + M)
// SC : O(1) 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        int i = 0, j = 0;

        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++, j++;
            }
            else {
                j++;
            }
        }

        return i == m ? true : false;
    }
};