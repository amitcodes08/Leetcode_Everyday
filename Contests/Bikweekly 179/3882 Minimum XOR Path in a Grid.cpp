/*
    Leetcode Link : https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/

// TC : O(M*N*V)
// SC : O(M*N*V)

class Solution
{
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, int XOR, vector<vector<vector<int>>> &dp)
    {
        int curr = XOR ^ grid[i][j];

        if (i == m - 1 && j == n - 1)
        {
            return curr;
        }

        if (dp[i][j][curr] != -1)
        {
            return dp[i][j][curr];
        }

        if (i == m - 1)
        {
            return dp[i][j][curr] = solve(i, j + 1, m, n, grid, curr, dp);
        }
        else if (j == n - 1)
        {
            return dp[i][j][curr] = solve(i + 1, j, m, n, grid, curr, dp);
        }

        return dp[i][j][curr] = min(
                   solve(i + 1, j, m, n, grid, curr, dp),
                   solve(i, j + 1, m, n, grid, curr, dp));
    }

    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(1025, -1)));
        return solve(0, 0, m, n, grid, 0, dp);
    }
};