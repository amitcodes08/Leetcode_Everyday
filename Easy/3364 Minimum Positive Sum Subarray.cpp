/*
    Leetcode Link : https://leetcode.com/problems/minimum-positive-sum-subarray
*/

//Approach-1 (Super Brute Force)
//T.C : O(n*r)
//S.C : O(1)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX;
    
        for (int i = 0; i < n; ++i) {
            int currSum = 0;

            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                currSum += nums[j];

                if ((j - i + 1) >= l && currSum > 0) {
                    result = min(result, currSum);
                }
            }
        }

        return result == INT_MAX ? -1 : result;    
    }
};


//Approach-2 (Improved Brute Force)
//T.C : O(n*(r-l+1))
//S.C : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {

            for (int len = l; len <= r && i + len <= n; len++) {
                int j = i + len - 1;

                int sum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

                if (sum > 0) 
                    result = min(result, sum);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};



//Approach-3 (Using Sliding Window and Multiset)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        multiset<int> st;
        st.insert(0);

        int result = INT_MAX;

        for(int j = l-1; j < n; j++) {
            if(j - l >= 0) {
                st.insert(prefixSum[j-l]);
            }

            int outOld = j-r-1;
            if(outOld >= 0) {
                st.erase(st.find(prefixSum[outOld]));
            } else if(outOld == -1) {
                st.erase(st.find(0));
            }

            auto it = st.lower_bound(prefixSum[j]);
            if(it != begin(st)) {
                it--;
                result = min(result, prefixSum[j] - *it);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};