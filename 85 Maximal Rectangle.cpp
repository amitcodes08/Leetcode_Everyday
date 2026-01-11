/*
    Company Tags  : Amazon, Directi, Intuit, MakeMyTrip, Microsoft, Samsung
    Leetcode Link : https://leetcode.com/problems/maximal-rectangle/
*/

// T.C : O(row*(col+col)) ~= O(row*col)
// S.C : O(col)

class Solution
{
public:
    vector<int> getNSR(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> NSR(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                NSR[i] = n;
            }
            else
            {
                NSR[i] = st.top();
            }

            st.push(i);
        }

        return NSR;
    }

    vector<int> getNSL(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> NSL(n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                NSL[i] = -1;
            }
            else
            {
                NSL[i] = st.top();
            }

            st.push(i);
        }

        return NSL;
    }

    int findMaxArea(vector<int> &height)
    {
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int n = height.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int width = NSR[i] - NSL[i] - 1;
            int area = width * height[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n);

        for (int i = 0; i < n; i++)
        {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(height);

        for (int row = 1; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] == '0')
                {
                    height[col] = 0;
                }
                else
                {
                    height[col] += 1;
                }
            }

            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }
};