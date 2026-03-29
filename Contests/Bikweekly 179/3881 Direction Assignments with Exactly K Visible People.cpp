/*
    Leetcode Link : https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/description/
*/

// TC : O(k + log M)
// SC : O(log M)

class Solution
{
public:
    typedef long long ll;
    ll M = 1e9 + 7;

    ll power(ll a, ll b)
    {
        if (b == 0)
        {
            return 1;
        }

        if (b % 2 == 0)
        {
            return power((a % M) * (a % M) % M, b / 2);
        }
        return (a * power(a, b - 1)) % M;
    }

    int countVisiblePeople(int n, int pos, int k)
    {
        if (k > n - 1)
            return 0;

        ll numr = 1;
        ll denr = 1;

        for (int i = 0; i < k; i++)
        {
            numr = (numr * (n - i - 1)) % M;
            denr = (denr * (i + 1)) % M;
        }

        ll ans = (numr * power(denr, M - 2)) % M;

        return (2 * ans) % M;
    }
};