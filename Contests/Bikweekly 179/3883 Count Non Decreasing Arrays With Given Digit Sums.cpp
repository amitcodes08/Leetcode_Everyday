/*
    Leetcode Link : https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/description/
*/

// TC : O(N)
// SC : O(1)

class Solution
{
    typedef long long ll;
    ll M = 1e9 + 7;

public:
    int countArrays(vector<int> &digitSum)
    {
        int n = digitSum.size();

        vector<int> dSum(5001);
        for (int i = 0; i <= 5000; i++)
        {
            int x = i;
            while (x > 0)
            {
                dSum[i] += (x % 10);
                x /= 10;
            }
        }

        vector<int> ans(5001, 0);
        ans[0] = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> tans(5001, 0);
            int pref = 0;
            for (int v = 0; v <= 5000; v++)
            {
                pref += ans[v];
                pref %= M;
                if (dSum[v] != digitSum[i])
                    continue;
                tans[v] = pref;
            }
            ans = tans;
        }

        int anss = 0;
        for (int v = 0; v <= 5000; v++)
        {
            anss += ans[v];
            anss %= M;
        }

        return anss;
    }
};