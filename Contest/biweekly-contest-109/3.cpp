/*
https://leetcode.com/contest/biweekly-contest-109/problems/visit-array-positions-to-maximize-score
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  long long maxScore(vector<int>& nums, int x) {
    int n = nums.size();
    vector<long long> dp = vector<long long>(n, 0);

    long long fmax[2];
    if (nums[0] % 2 == 0) {
      fmax[0] = nums[0];
      fmax[1] = -x;
    } else {
      fmax[1] = nums[0];
      fmax[0] = -x;
    }
    for (int i = 1; i < n; i++) {
      if (nums[i] % 2 == 0) {
        dp[i] = max(fmax[0] + nums[i], (long long)fmax[1] + nums[i] - x);
        fmax[0] = max(fmax[0], dp[i]);
      } else {
        dp[i] = max((long long)fmax[0] + nums[i] - x, fmax[1] + nums[i]);
        fmax[1] = max(fmax[1], dp[i]);
      }
    }
    long long ans = max(fmax[0], fmax[1]);
    for (int i = 0; i < n; i++) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};