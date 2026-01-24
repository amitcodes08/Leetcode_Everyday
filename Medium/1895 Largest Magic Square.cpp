/*
    Leetcode Link : https://leetcode.com/problems/largest-magic-square/description/
*/

// TC : O(M*N*min(M,N))
// SC : O(N*M)

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> rowCumSum(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++)
        {
            rowCumSum[i][0] = grid[i][0];
            for (int j = 1; j < cols; j++)
            {
                rowCumSum[i][j] = rowCumSum[i][j - 1] + grid[i][j];
            }
        }

        vector<vector<int>> colCumSum(rows, vector<int>(cols));
        for (int j = 0; j < cols; j++)
        {
            colCumSum[0][j] = grid[0][j];
            for (int i = 1; i < rows; i++)
            {
                colCumSum[i][j] = colCumSum[i - 1][j] + grid[i][j];
            }
        }

        for (int side = min(rows, cols); side >= 2; side--)
        {

            for (int i = 0; i + side - 1 < rows; i++)
            {
                for (int j = 0; j + side - 1 < cols; j++)
                {

                    int targetSum = rowCumSum[i][j + side - 1] -
                                    (j > 0 ? rowCumSum[i][j - 1] : 0);
                    bool allSame = true;

                    for (int r = i + 1; r < i + side; r++)
                    {
                        int rowSum = rowCumSum[r][j + side - 1] -
                                     (j > 0 ? rowCumSum[r][j - 1] : 0);

                        if (rowSum != targetSum)
                        {
                            allSame = false;
                            break;
                        }
                    }

                    if (!allSame)
                        continue;

                    for (int c = j; c < j + side; c++)
                    {
                        int colSum = colCumSum[i + side - 1][c] -
                                     (i > 0 ? colCumSum[i - 1][c] : 0);

                        if (colSum != targetSum)
                        {
                            allSame = false;
                            break;
                        }
                    }

                    if (!allSame)
                    {
                        continue;
                    }

                    int diag = 0;
                    int antiDiag = 0;

                    for (int k = 0; k < side; k++)
                    {
                        diag += grid[i + k][j + k];
                        antiDiag += grid[i + k][j + side - 1 - k];
                    }

                    if (diag == targetSum && antiDiag == targetSum)
                    {
                        return side;
                    }
                }
            }
        }

        return 1;
    }
};