/*
    Leetcode Link : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/
*/

// TC : O(ElogV)
// SC: O(E + V)

class Solution
{
public:
    typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>> &edges)
    {
        priority_queue<P, vector<P>, greater<P>> pq;

        unordered_map<int, vector<P>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }

        pq.push({0, 0});
        vector<int> result(n, INT_MAX);
        result[0] = 0;

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1)
            {
                return result[n - 1];
            }

            for (auto &p : adj[node])
            {
                int adjNode = p.first;
                int dt = p.second;

                if (d + dt < result[adjNode])
                {
                    result[adjNode] = d + dt;
                    pq.push({d + dt, adjNode});
                }
            }
        }

        return -1;
    }
};