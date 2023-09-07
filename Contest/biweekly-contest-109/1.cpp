/*
https://leetcode.com/contest/biweekly-contest-109/problems/check-if-array-is-good
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  bool isGood(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n == 1) {
      return false;
    }
    n = n - 1;
    int c = 1;
    bool can = true;
    for (auto x : nums) {
      if (x != c) {
        can = false;
      }
      c++;
      if (c > n) {
        c = n;
      }
    }
    return can;
  }
};