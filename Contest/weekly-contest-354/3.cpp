/*
https://leetcode.com/contest/weekly-contest-354/problems/minimum-index-of-a-valid-split
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    map<int, int> mp1, mp2;
    vector<int> dominant = vector<int>(n, -1);
    set<pair<int, int>> st;
    mp1[nums[0]]++;
    mp2[nums[0]]++;
    st.insert({1, nums[0]});
    dominant[0] = nums[0];
    for (int i = 1; i < n; i++) {
      mp2[nums[i]]++;
      st.erase({mp1[nums[i]], nums[i]});
      mp1[nums[i]]++;
      st.insert({mp1[nums[i]], nums[i]});
      auto it = st.rbegin();
      if (it->first * 2 > (i + 1)) {
        dominant[i] = it->second;
      }
    }
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
      mp2[nums[i]]--;
      if (dominant[i] != -1) {
        int len = n - i - 1;
        if (mp2[dominant[i]] * 2 > len) {
          ans = i;
          break;
        }
      }
    }
    return ans;
  }
};