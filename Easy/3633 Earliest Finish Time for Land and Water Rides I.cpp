/*
    LeetCode Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
*/

// Approach-1 (Brute Force)
// T.C : O(n^2)
// S.C : O(1)

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
        {
            for (int j = 0; j < waterStartTime.size(); j++)
            {
                int land_t = landStartTime[i] + landDuration[i];
                int water_s = max(land_t, waterStartTime[j]);
                int finish1 = water_s + waterDuration[j];

                int water_f = waterStartTime[j] + waterDuration[j];
                int land_s = max(water_f, landStartTime[i]);
                int finish2 = land_s + landDuration[i];

                ans = min({ans, finish1, finish2});
            }
        }
        return ans;
    }
};