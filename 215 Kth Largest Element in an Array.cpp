/*
    Leetcode Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

// Approach-1 : Using Min-Heap

// TC : O(N * log(K))
// SC : O(K)

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &num : nums)
        {
            pq.push(num);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// Approach-2 : Using Quick Select
// TC : O(N) on average, O(N^2) in worst case
// SC : O(1)

class Solution
{
public:
    int partition_algo(vector<int> &nums, int L, int R)
    {

        int P = nums[L];
        int i = L + 1; // 0
        int j = R;     // 0

        while (i <= j)
        {

            if (nums[i] < P && nums[j] > P)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if (nums[i] >= P)
            {
                i++;
            }

            if (nums[j] <= P)
            {
                j--;
            }
        }

        swap(nums[L], nums[j]);
        return j; // P is at jth index
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        int L = 0;
        int R = n - 1;

        int pivot_idx = 0;

        // kth largest pivot element - nums[k-1] (descendinforder me partition karenge)

        while (true)
        {

            pivot_idx = partition_algo(nums, L, R);

            if (pivot_idx == k - 1)
            {
                break;
            }
            else if (pivot_idx > k - 1)
            { // 2nd larget , 4th larget
                R = pivot_idx - 1;
            }
            else
            {
                L = pivot_idx + 1;
            }
        }

        return nums[pivot_idx];
    }
};
