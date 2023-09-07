/*
https://leetcode.com/contest/weekly-contest-355/problems/largest-element-in-an-array-after-merge-operations
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long curMax = 0;
    long long cur = nums[n - 1];
    int l = n - 2, r = n - 1;
    while (l <= r && l >= 0) {
      if (l >= 0 && cur >= nums[l]) {
        cur += (long long)nums[l];
        l--;
      } else {
        curMax = max(curMax, cur);
        if (l >= 0) {
          cur = nums[l];
          r = l;
          l--;
        }
      }
    }
    curMax = max(curMax, cur);
    return curMax;
  }
};