/*
    LeetCode Link : https://leetcode.com/problems/sliding-window-maximum/
*/

// T.C : O(n) where n is the number of elements in the input array nums. Each element is processed at most twice (once when it is added to the deque and once when it is removed).
// S.C : O(k) where k is the size of the sliding window. In the worst case, the deque can hold at most k elements, which happens when all elements in the current window are in decreasing order.

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};