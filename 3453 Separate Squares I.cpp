/*
    Leetcode Link : https://leetcode.com/problems/separate-squares-i/description/
    TC : O(N * log(M))
    SC : O(1)
*/



class Solution
{
public:
    bool check(vector<vector<int>> &squares, double mid_y, double totalArea)
    {
        double botArea = 0.00000;
        for (auto &square : squares)
        {
            double y = square[1];
            double l = square[2];

            double boty = y;
            double topy = y + l;

            if (mid_y >= topy)
            {
                botArea += (l * l);
            }
            else if (mid_y > boty)
            {
                botArea += l * (mid_y - y);
            }
        }

        return botArea >= totalArea / 2.0;
    }

    double separateSquares(vector<vector<int>> &squares)
    {
        double low = INT_MAX;
        double high = INT_MIN;
        double totalArea = 0.00000;

        for (auto &square : squares)
        {
            double x = square[0];
            double y = square[1];
            double l = square[2];

            totalArea += l * l;

            low = min(low, y);
            high = max(high, y + l);
        }

        double result_y = 0.00000;

        while (high - low > 1e-5)
        {
            double mid_y = low + (high - low) / 2;
            result_y = mid_y;

            if (check(squares, mid_y, totalArea) == true)
            {
                high = mid_y;
            }
            else
            {
                low = mid_y;
            }
        }

        return result_y;
    }
};