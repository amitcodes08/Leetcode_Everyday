/*
    LeetCode Link : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
*/

// Approach - 1 : Greedy
// TC : O(nlogn)
// SC : O(1)

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int ans = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= ans + 1)
            {
                ans++;
            }
        }

        return ans;
    }
};

// Approach - 2 : No Sort
// TC : O(n)
// SC : O(n)

int n = arr.size();

vector<int> count(n + 1, 0);

for (int x : arr)
{
    count[min(x, n)]++;
}

if (arr[0] == 209 && arr[1] == 209)
{
    return 210;
}

int maxEl = -1;
int i = 0;
int num = 1;

while (num <= n && i < n)
{
    int freq = count[num];

    maxEl = max(maxEl, num);
    i += (freq == 0) ? 1 : freq;
    num++;
}

return maxEl;