/*
    Leetcode Link : https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/


class Solution
{
public:
    // Function to find the largest rectangle area
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size(); // Size of array

        // Stack
        stack<int> st;

        // To store largest area
        int largestArea = 0;

        // To store current area
        int area;

        /* To store the indices of next
        and previous smaller elements */
        int nse, pse;

        // Traverse on the array
        for (int i = 0; i < n; i++)
        {

            /* Pop the elements in the stack until
            the stack is not empty and the top
            elements is not the smaller element */
            while (!st.empty() &&
                   heights[st.top()] >= heights[i])
            {

                // Get the index of top of stack
                int ind = st.top();
                st.pop();

                /* Update the index of
                previous smaller element */
                pse = st.empty() ? -1 : st.top();

                /* Next smaller element index for
                the popped element is current index */
                nse = i;

                // Calculate the area of the popped element
                area = heights[ind] * (nse - pse - 1);

                // Update the maximum area
                largestArea = max(largestArea, area);
            }

            // Push the current index in stack
            st.push(i);
        }

        // For elements that are not popped from stack
        while (!st.empty())
        {

            // NSE for such elements is size of array
            nse = n;

            // Get the index of top of stack
            int ind = st.top();
            st.pop();

            // Update the previous smaller element
            pse = st.empty() ? -1 : st.top();

            // Calculate the area of the popped element
            area = heights[ind] * (nse - pse - 1);

            // Update the maximum area
            largestArea = max(largestArea, area);
        }

        // Return largest area found
        return largestArea;
    }
};

