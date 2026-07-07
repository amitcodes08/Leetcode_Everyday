/*
    LeetCode Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

// Approach - 1 : Sorting
// TC : O(nlogn)
// SC : O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;
        int lastSmaller = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == lastSmaller)
                continue;
            if (nums[i] - 1 == lastSmaller)
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
            }
            lastSmaller = nums[i];
            longest = max(longest, cnt);
        }
        return longest;
    }
};

// Approach - 2 : Hashing
// TC : O(n)
// SC : O(n)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;
        int largest = 1;

        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        for (auto &it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int x = it;
                int cnt = 1;

                while (st.find(x + 1) != st.end())
                {
                    x += 1;
                    cnt += 1;
                }

                largest = max(largest, cnt);
            }
        }

        return largest;
    }
};
