/*
    Leetcode Link : https://leetcode.com/problems/champagne-tower/description
*/

// Time Complexity: O(query_row²)
// Space Complexity: O(query_row²) for DP table + O(query_row) for recursion stack = O(query_row²)
class Solution
{
public:
    double solve(int poured, int i, int j, vector<vector<double>> &dp)
    {
        if (i < 0 || j < 0 || i < j)
        {
            return 0.0;
        }

        if (i == 0 && j == 0)
            return poured;

        if (dp[i][j] != -1)
            return dp[i][j];

        double up_left = (solve(poured, i - 1, j - 1, dp) - 1) / 2.0;
        double up_right = (solve(poured, i - 1, j, dp) - 1) / 2.0;

        if (up_left < 0)
            up_left = 0.0;

        if (up_right < 0)
        {
            up_right = 0.0;
        }
        return dp[i][j] = up_left + up_right;
    }

    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> dp(101, vector<double>(101, -1));
        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};