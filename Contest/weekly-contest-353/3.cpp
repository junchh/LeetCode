/*
https://leetcode.com/contest/weekly-contest-353/problems/longest-non-decreasing-subarray-from-two-arrays
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int dp[n][2];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
      if (nums1[i] >= nums1[i - 1]) {
        if (nums1[i] >= nums2[i - 1]) {
          dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
          dp[i][0] = dp[i - 1][0] + 1;
        }
      } else {
        if (nums1[i] >= nums2[i - 1]) {
          dp[i][0] = dp[i - 1][1] + 1;
        } else {
          dp[i][0] = 1;
        }
      }
      if (nums2[i] >= nums1[i - 1]) {
        if (nums2[i] >= nums2[i - 1]) {
          dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
          dp[i][1] = dp[i - 1][0] + 1;
        }
      } else {
        if (nums2[i] >= nums2[i - 1]) {
          dp[i][1] = dp[i - 1][1] + 1;
        } else {
          dp[i][1] = 1;
        }
      }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};