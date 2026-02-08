// TC : O(nlogn)
// SC : O(n)
class Solution
{
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end)
    {
        int n = start.size();

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[start[i]] += 1;
            mp[end[i]] -= 1;
        }

        int overlap = 0;
        int maxOverlap = 0;

        for (auto &it : mp)
        {
            overlap += it.second;

            if (overlap > maxOverlap)
            {
                maxOverlap = overlap;
            }
        }

        return maxOverlap;
    }
};
