/*
https://leetcode.com/contest/weekly-contest-353/problems/apply-operations-to-make-all-array-elements-equal-to-zero
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int n, arr[100005], bit[100005];
  void add(int idx, int val) {
    while (idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  long long point_query(int idx) {
    long long res = 0;
    while (idx >= 1) {
      res += bit[idx];
      idx -= idx & -idx;
    }
    return res;
  }
  bool checkArray(vector<int>& nums, int k) {
    n = nums.size();
    for (int i = 0; i < n; i++) {
      range_add(i + 1, i + 1, nums[i]);
    }
    bool can = true;
    for (int i = 1; i <= n; i++) {
      int val = point_query(i);
      if (val < 0) {
        can = false;
        break;
      } else if (val > 0) {
        if (i + k - 1 <= n) {
          range_add(i, i + k - 1, -val);
        } else {
          can = false;
          break;
        }
      }
    }
    return can;
  }
};