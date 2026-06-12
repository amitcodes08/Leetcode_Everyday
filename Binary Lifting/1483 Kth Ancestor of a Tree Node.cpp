/*
    LeetCode Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
*/

// Approach (Using Binary Lifting)
// T.C : O(Q * log(n)) , Q = number of queries , n = number of nodes
// S.C : O(n * log(n)) to store events in map
class TreeAncestor
{
public:
    vector<vector<int>> ancestorTable;
    int rows;
    int cols;

    TreeAncestor(int n, vector<int> &parent)
    {
        rows = n;
        cols = log2(n) + 1;

        ancestorTable.resize(rows, vector<int>(cols, -1));

        // fill the 0th column first - immediate parent(ancestor)
        for (int node = 0; node < n; node++)
        { // O(n)
            ancestorTable[node][0] = parent[node];
        }

        for (int j = 1; j < cols; j++)
        { // O(log(n))
            for (int node = 0; node < n; node++)
            {

                if (ancestorTable[node][j - 1] != -1)
                {
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {

        for (int j = 0; j < cols; j++)
        { // O(log(n))
            if (k & (1 << j))
            { // jth bit is set so we can take 2^j wala jump
                node = ancestorTable[node][j];

                if (node == -1)
                    return -1;
            }
        }

        return node;
    }
};
