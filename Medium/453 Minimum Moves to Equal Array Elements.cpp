/*
    LeetCode Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
*/

// Approach (Greedy)
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int minEle = *min_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return sum - (n * minEle);
    }
};