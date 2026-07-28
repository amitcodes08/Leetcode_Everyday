/*
    Leetcode Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
*/

// Approach : Sort first half and then mirror it to the second half. If odd length, place the middle character in the middle.
// TC : O(nlogn) for sorting, SC : O(1) as we are modifying the string in place.

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int len = s.length();
        int partition = len / 2;

        sort(s.begin(), s.begin() + partition);

        for (int i = 0; i < partition; ++i)
        {
            s[len - 1 - i] = s[i];
        }

        return s;
    }
};

// Approach : Count the frequency of each character and then place them in lexicographical order. If odd length, place the middle character in the middle.
// TC : O(n) for counting, O(26) for placing characters, SC : O(1) as we are using a fixed size array for counting.

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        string half = "";
        char mid = 0;

        for (int i = 0; i < 26; i++)
        {
            half += string(freq[i] / 2, 'a' + i);
            if (freq[i] % 2)
                mid = 'a' + i;
        }

        string ans = half;
        if (mid)
            ans += mid;
        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }
};