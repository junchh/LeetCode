/*
https://leetcode.com/contest/weekly-contest-361/problems/minimum-operations-to-make-a-special-number
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minimumOperations(string num) {
    int n = num.length();
    vector<int> pos0, pos2, pos5, pos7;
    for (int i = 0; i < n; i++) {
      if (num[i] == '0') {
        pos0.emplace_back(i);
      } else if (num[i] == '2') {
        pos2.emplace_back(i);
      } else if (num[i] == '5') {
        pos5.emplace_back(i);
      } else if (num[i] == '7') {
        pos7.emplace_back(i);
      }
    }
    int ans = 1e9;
    for (auto x : pos7) {
      for (auto y : pos5) {
        if (x < y) {
          ans = min(ans, n - x - 2);
        }
      }
    }
    for (auto x : pos2) {
      for (auto y : pos5) {
        if (x < y) {
          ans = min(ans, n - x - 2);
        }
      }
    }
    for (auto x : pos5) {
      for (auto y : pos0) {
        if (x < y) {
          ans = min(ans, n - x - 2);
        }
      }
    }
    for (auto x : pos0) {
      ans = min(ans, n - 1);
      for (auto y : pos0) {
        if (x < y) {
          ans = min(ans, n - x - 2);
        }
      }
    }
    if (ans == 1e9) {
      ans = n;
    }
    return ans;
  }
};