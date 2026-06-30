/*
    Leetcode Link : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/description/
*/

// Approach - Simple Brute Force
// TC : O(n^2)
// SC : O(1)

class Solution
{
public:
    int countOfSubstrings(string s, int k)
    {
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int a = 0, e = 0, m = 0, o = 0, u = 0, c = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (s[j] == 'a')
                    a++;
                else if (s[j] == 'e')
                    e++;
                else if (s[j] == 'i')
                    m++;
                else if (s[j] == 'o')
                    o++;
                else if (s[j] == 'u')
                    u++;
                else
                    c++;

                if (a && e && m && o && u && c == k)
                    ans++;
            }
        }

        return ans;
    }
};