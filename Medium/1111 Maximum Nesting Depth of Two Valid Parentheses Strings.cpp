/*
    LeetCode Link : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
*/

// Approach (Greedy)
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        int depth = 0;

        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') {
                depth++;
                result[i] = (depth % 2 == 0) ? 0 : 1;
            }
            else {
                result[i] = (depth % 2 == 0) ? 0 : 1;
                depth--;
            }
        }


        return result;
    }
};