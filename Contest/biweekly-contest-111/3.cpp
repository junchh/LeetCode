/*
https://leetcode.com/contest/biweekly-contest-111/problems/sorting-three-groups
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(3, 1));

    int firstVal = nums[0] - 1;
    dp[0][firstVal] = 0;
    for (int i = 1; i < n; i++) {
      int val = nums[i] - 1;
      dp[i][2] =
          min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + (val != 2);
      dp[i][0] = dp[i - 1][0] + (val != 0);
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (val != 1);
    }

    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  }
};