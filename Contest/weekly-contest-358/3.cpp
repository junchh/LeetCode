/*
https://leetcode.com/contest/weekly-contest-358/problems/minimum-absolute-difference-between-elements-with-constraint
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minAbsoluteDifference(vector<int>& nums, int x) {
    multiset<int> st;
    int siz = nums.size();
    for (int i = x; i < siz; i++) {
      st.insert(nums[i]);
    }
    int ans = 2e9;
    for (int i = 0; i + x < siz; i++) {
      auto it = st.lower_bound(nums[i]);
      if (it == st.end()) {
        ans = min(ans, abs(*(st.rbegin()) - nums[i]));
      } else {
        if (*it == nums[i]) {
          ans = min(ans, 0);
        } else {
          ans = min(ans, abs(*it - nums[i]));
          if (it != st.begin()) {
            it--;
            ans = min(ans, abs(*it - nums[i]));
          }
        }
      }
      st.erase(st.find(nums[i + x]));
    }
    return ans;
  }
};