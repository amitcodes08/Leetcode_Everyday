/*
    LeetCode Link : https://leetcode.com/problems/extra-characters-in-a-string/description/
*/

class Solution
{
public:
    int n;
    unordered_set<string> st;
    vector<int> memo;

    int solve(int i, string &s)
    {
        if (i >= n)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int res = 1 + solve(i + 1, s);

        for (int l = 1; i + l <= n; l++)
        {
            string temp = s.substr(i, l);
            if (st.count(temp))
            {
                res = min(res, solve(i + l, s));
            }
        }

        return memo[i] = res;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        n = s.length();
        for (string &w : dictionary)
            st.insert(w);
        memo.assign(n, -1);
        return solve(0, s);
    }
};