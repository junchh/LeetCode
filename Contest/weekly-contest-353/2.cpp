/*
https://leetcode.com/contest/weekly-contest-353/problems/maximum-number-of-jumps-to-reach-the-last-index
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();

    int dp[n];
    for (int i = 0; i < n; i++) {
      dp[i] = -1;
    }

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (abs(nums[i] - nums[j]) <= target && dp[j] != -1) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return dp[n - 1];
  }
};