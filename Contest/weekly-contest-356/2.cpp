/*
https://leetcode.com/contest/weekly-contest-356/problems/count-complete-subarrays-in-an-array
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    set<int> st;
    for (auto x : nums) {
      st.insert(x);
    }
    int h = st.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      set<int> st2;
      for (int j = i; j < n; j++) {
        st2.insert(nums[j]);
        if (st2.size() == h) {
          cnt++;
        }
      }
    }
    return cnt;
  }
};