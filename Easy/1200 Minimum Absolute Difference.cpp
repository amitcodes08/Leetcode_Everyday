/*
    Leetcode Link : https://leetcode.com/problems/minimum-absolute-difference/description/
*/

// TC : O(NlogN)
// SC: O(1)

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> ans;
        for (int i = 1; i < n; i++)
        {
            int diff = arr[i] - arr[i - 1];

            if (diff == minDiff)
            {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};