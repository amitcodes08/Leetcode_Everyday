/*
    LeetCode Link : https://leetcode.com/problems/is-graph-bipartite/
*/

class Solution
{
public:
    bool checkBipartiteBfs(int u, vector<int> &color, vector<vector<int>> &adj, int currColor)
    {
        queue<int> q;
        q.push(u);
        color[u] = currColor;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto &v : adj[u])
            {
                if (color[v] == color[u])
                {
                    return false;
                }
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (checkBipartiteBfs(i, color, graph, 1) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};