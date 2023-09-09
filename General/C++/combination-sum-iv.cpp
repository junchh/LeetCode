#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    const int MAXN = (1 << 31) - 1;
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < n; j++) {
        if (nums[j] > i) continue;
        if (1ll * dp[i] + 1ll * dp[i - nums[j]] > MAXN) continue;
        dp[i] += dp[i - nums[j]];
      }
    }
    return dp[target];
  }
};