/*
    Leetcode Link : https://leetcode.com/problems/maximum-population-year/description
*/

//Approach - 1 : DAT( Difference Array Technique)
// TC : O(N + Y) // N -> Size of Logs , Y -> Years
// SC : O(Y)

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> years(2051, 0);

        for (auto &log : logs)
        {
            int birthYear = log[0];
            int deathYear = log[1];

            years[birthYear] += 1;
            years[deathYear] -= 1;
        }

        int currPop = 0;
        int maxPop = 0;
        int minYear = 0;

        for (int i = 1950; i < 2051; i++)
        {
            currPop += years[i];

            if (currPop > maxPop)
            {
                maxPop = currPop;
                minYear = i;
            }
        }

        return minYear;
    }
};

// Approach - 2 : Using Line Sweep Algo
// TC : O(nlogn)
// SC : O()

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<pair<int, int>> events;

        for (auto &log : logs)
        {
            events.push_back({log[0], 1});
            events.push_back({log[1], -1});
        }

        sort(events.begin(), events.end());

        int currPop = 0;
        int maxPop = 0;
        int minYear = 2050;

        for (auto &e : events)
        {
            currPop += e.second;

            if (currPop > maxPop)
            {
                maxPop = currPop;
                minYear = e.first;
            }
        }

        return minYear;
    }
};