/*
https://leetcode.com/contest/weekly-contest-357/problems/check-if-it-is-possible-to-split-array
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  bool canSplitArray(vector<int>& nums, int m) {
    bool can = false;
    int n = nums.size();
    if (n <= 2) {
      return true;
    }

    for (int i = 1; i < n; i++) {
      if (nums[i] + nums[i - 1] >= m) {
        can = true;
      }
    }
    return can;
  }
};