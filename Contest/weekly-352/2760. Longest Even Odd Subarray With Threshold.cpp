/*
https://leetcode.com/contest/weekly-contest-352/problems/longest-even-odd-subarray-with-threshold/
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int n = nums.size();

    int ans = 0;
    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        bool valid = (nums[l] <= threshold && nums[l] % 2 == 0);
        for (int a = l + 1; a <= r; a++) {
          if (nums[a] % 2 == nums[a - 1] % 2 || nums[a] > threshold) {
            valid = false;
            break;
          }
        }
        if (valid) {
          ans = max(ans, r - l + 1);
        }
      }
    }

    return ans;
  }
};