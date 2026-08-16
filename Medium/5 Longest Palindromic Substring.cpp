/*
    LeetCode Link : https://leetcode.com/problems/longest-palindromic-substring/
*/

// Approach 1 - Recursion + Memoization
// Memoization will help reduce time complexity for cases like - "aaaaaaaaa"
// T.C : O(n^2) - Because the AMortized Time Complexity of solve() will become 1 due to memoization.
// S.C : O(n^2)
class Solution
{
public:
    int t[1001][1001];

    bool solve(string &s, int l, int r)
    {
        if (l >= r)
            return 1;

        if (t[l][r] != -1)
        {
            return t[l][r];
        }

        if (s[l] == s[r])
        {
            return t[l][r] = solve(s, l + 1, r - 1);
        }

        return t[l][r] = false;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                if (solve(s, i, j))
                {
                    if (j - i + 1 > maxlen)
                    {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// Approach 2 - Looping simply in solve()
// T.C : O(n^3)
class Solution
{
public:
    bool solve(string &s, int l, int r)
    {

        while (l <= r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                if (solve(s, i, j))
                {
                    if (j - i + 1 > maxlen)
                    {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// Approach 3 - Using Bottom Up (Elaborated for simplicity) - My favourite BluePrint for solving palindromic DP problems
// T.C : O(n^2)
// S.C : O(n^2)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        int maxL = 0;
        int index = 0;

        vector<vector<bool>> t(n, vector<bool>(n));
        // t[i][j] = lps in s[i...j]

        maxL = 1; // every letter is a substring and pallindrome as well
        for (int i = 0; i < n; i++)
        {
            t[i][i] = true;
            /*
                s[0..0] = pallindrome
                s[1..1] = pallindrome
                s[2..2] = pallindrome
                .
                .
                .
            */
        }

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n - L + 1; i++)
            {
                int j = i + L - 1;

                if (s[i] == s[j] && L == 2)
                {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                }
                else if (s[i] == s[j] && t[i + 1][j - 1] == true)
                {
                    t[i][j] = true;
                    if (j - i + 1 > maxL)
                    {
                        maxL = j - i + 1;
                        index = i;
                    }
                }
                else
                {
                    t[i][j] = false;
                }
            }
        }

        return s.substr(index, maxL);
    }
};

// Approach 4 :  (Simplifiying Approach-2 above)
// Simplified solution
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxL = 1;
        int start = 0;

        for (int i = 0; i < n; i++)
            t[i][i] = true;

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n - L + 1; i++)
            {
                int j = i + L - 1;

                if (s[i] == s[j] && (t[i + 1][j - 1] || L == 2))
                {
                    t[i][j] = true;
                    if (L > maxL)
                    {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxL);
    }
};
