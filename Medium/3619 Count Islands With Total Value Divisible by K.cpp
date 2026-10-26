/*
    LeetCode Link : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
*/

// Approach (Using BFS)
// T.C : O(m*n)
// S.C : O(1)

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        long long sum = grid[i][j];
        grid[i][j] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (vector<int>& dir : directions) {
                int i_ = x + dir[0];
                int j_ = y + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                    sum += grid[i_][j_];
                    grid[i_][j_] = 0;
                    q.push({i_, j_});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(i, j, grid);
                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};