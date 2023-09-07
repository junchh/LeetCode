/*
https://leetcode.com/contest/weekly-contest-354/problems/maximum-beauty-of-an-array-after-applying-operation
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    vector<int> pre = vector<int>(250000, 0);
    for (auto x : nums) {
      int l = max(0, x - k);
      int r = x + k;
      pre[l]++;
      pre[r + 1]--;
    }
    for (int i = 0; i < 250000; i++) {
      pre[i] += ((i == 0) ? 0 : pre[i - 1]);
    }
    int fmax = 1;
    for (int i = 0; i < 250000; i++) {
      fmax = max(fmax, pre[i]);
    }
    return fmax;
  }
};