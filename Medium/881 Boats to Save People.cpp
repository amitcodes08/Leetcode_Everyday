/*
    Leetcode Link : https://leetcode.com/problems/boats-to-save-people/description/
*/

// TC : O(NlogN)
// SC: O(1)

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int boats = 0;
        sort(people.begin(), people.end());
        int l = 0, r = n - 1;
        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
            {
                boats++;
                l++;
                r--;
            }
            else
            {
                boats += 1;
                r--;
            }
        }
        return boats;
    }
};