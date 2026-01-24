/*
    Leetcode Link : https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/
*/

//  TC : O(N^2 + M^2)
//  SC : O(N + M)

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> widths;

        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = i + 1; j < vFences.size(); j++)
            {
                int width = vFences[j] - vFences[i];
                widths.insert(width);
            }
        }

        int maxWidth = 0;

        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = i + 1; j < hFences.size(); j++)
            {
                int height = hFences[j] - hFences[i];

                if (widths.find(height) != widths.end())
                {
                    maxWidth = max(maxWidth, height);
                }
            }
        }

        if (maxWidth == 0)
            return -1;

        long long area = (1LL * maxWidth * maxWidth) % MOD;
        return area;
    }
};