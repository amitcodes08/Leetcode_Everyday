/*
    Leetcode Link : https://leetcode.com/problems/equal-sum-grid-partition-i/
*/

// TC : O(n*m)
// SC : O(m + n)

class Solution
{
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowSum(m, 0);
        vector<ll> colSum(n, 0);

        ll total = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += grid[i][j];

                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        if (total % 2 != 0)
        {
            return false;
        }

        ll upper = 0;
        for (int k = 0; k < m - 1; k++)
        {
            upper += rowSum[k];
            if (upper == total - upper)
            {
                return true;
            }
        }

        ll sideWise = 0;
        for (int l = 0; l < n - 1; l++)
        {
            sideWise += colSum[l];
            if (sideWise == total - sideWise)
            {
                return true;
            }
        }

        return false;
    }
};