/*
    Leetcode Link : https://leetcode.com/problems/remove-covered-intervals/description/
*/

// Approach (Using sorting)
// T.C : O(nlogn)
// S.C : O(1)
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        auto lambda = [](auto &vec1, auto &vec2)
        {
            if (vec1[1] != vec2[1])
                return vec1[1] < vec2[1];
            return vec1[0] > vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        int count = 1;
        int lastIntervalKaEnd = intervals[0][1];

    for(int i = 1; i < n; i++) {
        if (lastIntervalKaEnd >= intervals[i][1]) {
            continue;
        }
        lastIntervalKaEnd = intervals[i][1];
        count++;
    }
       
        return count;
    }
};
