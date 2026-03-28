/*
    LeetCode Link : https://leetcode.com/problems/minimum-path-sum/description/
*/

// Approach-1 (Recursion + Memoization)
// T.C : O(m*n)
// S.C : O(m*n) + O(m+n) (recursion stack space)

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == m - 1)
        {
            return dp[i][j] = grid[i][j] + solve(i, j + 1, grid, m, n, dp);
        }
        else if (j == n - 1)
        {
            return dp[i][j] = grid[i][j] + solve(i + 1, j, grid, m, n, dp);
        }
        else
        {
            return dp[i][j] = grid[i][j] + min(solve(i, j + 1, grid, m, n, dp), solve(i + 1, j, grid, m, n, dp));
        }
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, grid, m, n, dp);
    }
};

// Approach-2 (Tabulation)
// T.C : O(m*n)
// S.C : O(m*n)

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int j = 1; j < n; j++)
        {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};