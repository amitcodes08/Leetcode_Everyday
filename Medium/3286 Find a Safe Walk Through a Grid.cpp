/*
    LeetCode Link : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/
*/

// Approach : 0-1 BFS
// TC : O(m*n)
// SC : O(m*n)

class Solution
{
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        result[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (d > result[r][c])
                continue;

            for (auto &dd : dir)
            {
                int nr = r + dd[0];
                int nc = c + dd[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (result[nr][nc] > d + grid[nr][nc])
                {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({d + grid[nr][nc], nr, nc});
                }
            }
        }

        int x = result[m - 1][n - 1];
        return (health - x >= 1);
    }
};

// Approach : Dijkstra's Algorithm
// TC : O(m*n*log(m*n))
// SC : O(m*n)

class Solution
{
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        result[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (d > result[r][c])
                continue;

            for (auto &dd : dir)
            {
                int nr = r + dd[0];
                int nc = c + dd[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (result[nr][nc] > d + grid[nr][nc])
                {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({d + grid[nr][nc], nr, nc});
                }
            }
        }

        int x = result[m - 1][n - 1];
        return (health - x >= 1);
    }
};