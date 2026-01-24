/*
    Leetcode Link : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
*/

//  TC : O(N log N + M log M)
//  SC : O(1)

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutivehBars = 1;
        int maxConsecutivevBars = 1;

        int currConsecutivehBars = 1;

        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] - hBars[i - 1] == 1)
            {
                currConsecutivehBars++;
            }
            else
            {
                currConsecutivehBars = 1;
            }

            maxConsecutivehBars = max(maxConsecutivehBars, currConsecutivehBars);
        }

        int currentConsecutivevBars = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] - vBars[i - 1] == 1)
            {
                currentConsecutivevBars++;
            }
            else
            {
                currentConsecutivevBars = 1;
            }

            maxConsecutivevBars = max(maxConsecutivevBars, currentConsecutivevBars);
        }

        int side = min(maxConsecutivevBars, maxConsecutivehBars) + 1;

        return side * side;
    }
};