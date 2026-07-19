/*
    LeetCode Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

// Approach-1 (Using string as a stack)
// T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
// S.C : O(1)
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.length();
        string result;

        vector<bool> taken(26, false); // O(1) space
        vector<int> lastIndex(26);     // O(1) space

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            lastIndex[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++)
        {

            int idx = s[i] - 'a';

            if (taken[idx] == true)
                continue;

            while (result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i)
            {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(s[i]);
            taken[idx] = true;
        }

        return result;
    }
};

// Approach-2 (Using stack)
// T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
// S.C : O(n) stack
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.length();
        stack<char> st;

        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            lastIndex[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++)
        {

            int idx = s[i] - 'a';

            if (taken[idx] == true)
                continue;

            while (!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i)
            {
                taken[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            taken[idx] = true;
        }

        string result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};

// Approach-3 (Using Recursion + Backtracking) - Not a good solution because contraints are high
/*
At ever character i have two choices - take or not take.
I can take it if that character is not taken before.
Once I reach out of bounds, i will see my temp string and keeping updating the result which is lexically smaller
*/
class Solution
{
public:
    string result = "";
    int n;
    int unique_characters;

    void solve(int idx, string s, string temp, unordered_set<char> &st)
    {
        if (idx >= n)
        {
            if (result == "")
                result = s;
            else if (temp.size() == unique_characters)
                result = result > temp ? temp : result;

            return;
        }

        if (st.find(s[idx]) == st.end())
        {
            temp.push_back(s[idx]); // taking idx'th char
            st.insert(s[idx]);
            solve(idx + 1, s, temp, st);

            // Removing it for trying "Not Taking this Char"
            st.erase(s[idx]); // Not taking idx'th char
            temp.pop_back();
        }

        solve(idx + 1, s, temp, st);
    }

    string removeDuplicateLetters(string s)
    {
        n = s.length();
        unordered_set<char> st;

        for (char &ch : s)
        {
            st.insert(ch);
        }
        unique_characters = st.size();

        st.clear();

        solve(0, s, "", st);

        return result;
    }
};
