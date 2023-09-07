/*
https://leetcode.com/contest/biweekly-contest-112/problems/maximum-sum-of-almost-unique-subarray
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  long long maxSum(vector<int>& nums, int m, int k) {
    long long curSum = 0;
    int n = nums.size();
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < k; i++) {
      curSum += (long long)nums[i];
      mp[nums[i]]++;
      st.insert(nums[i]);
    }
    long long ans = 0;
    if ((int)st.size() >= m) {
      ans = curSum;
    }
    int le = 0;
    for (int i = k; i < n; i++) {
      if (mp[nums[le]] == 1) {
        st.erase(nums[le]);
        mp[nums[le]] = 0;
      } else {
        mp[nums[le]]--;
      }
      curSum -= (long long)nums[le];
      curSum += (long long)nums[i];
      st.insert(nums[i]);
      mp[nums[i]]++;
      le++;
      if ((int)st.size() >= m) {
        ans = max(ans, curSum);
      }
    }
    return ans;
  }
};