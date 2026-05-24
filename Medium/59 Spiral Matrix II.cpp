/*
    Leetcode Link : https://leetcode.com/problems/spiral-matrix-ii/description/
*/

// Approach-1 (Simulation)
// T.C : O(n^2)
// S.C : O(n^2)

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));

        int minr = 0, maxr = n - 1;
        int minc = 0, maxc = n - 1;
        int val = 1;

        while (minr <= maxr && minc <= maxc)
        {
            for (int i = minc; i <= maxc; i++)
            {
                ans[minr][i] = val++;
            }
            minr++;

            for (int j = minr; j <= maxr; j++)
            {
                ans[maxc][j] = val++;
            }

            maxc--;

            for (int k = maxc; k >= minc; k--)
            {
                ans[maxr][k] = val++;
            }
            maxr--;

            for (int l = maxr; l >= minr; l--)
            {
                ans[minc][l] = val++;
            }

            minc++;
        }

        return ans;
    }
};