/*
    Leetcode Link : https://leetcode.com/problems/poor-pigs/description/
*/

// Approach-1
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int T = minutesToTest / minutesToDie + 1;

        int pigs = 0;

        while (pow(T, pigs) < buckets)
        {
            pigs++;
        }

        return pigs;
    }
};

// Approach-2 (Using simple one liner)
class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        //(T+1)^pigs = buckets
        // pigs = log(buckets)/log(T+1)

        return ceil(log2(buckets) / log2(minutesToTest / minutesToDie + 1));
    }
};
