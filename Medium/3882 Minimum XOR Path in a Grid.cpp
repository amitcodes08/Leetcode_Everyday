/*
    Leetcode Link : https://leetcode.com/problems/minimum-xor-path-in-a-grid/
*/

//Approach (Using Recursion + Memoization)
// T.C : O(m*n*1024)
// S.C : O(m*n*1024)

class Solution {
public:
    int m;
    int n;

    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int xr, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return INT_MAX;
        }

        if(i == m - 1 && j == n - 1) {
            return xr ^ grid[i][j];
        }

        if(dp[i][j][xr] != -1) {
            return dp[i][j][xr];
        }

        int right = solve(i, j+1, xr ^ grid[i][j], grid);
        int down = solve(i+1, j, xr ^ grid[i][j], grid);

        return dp[i][j][xr] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return solve(0, 0, 0, grid);
    }
};