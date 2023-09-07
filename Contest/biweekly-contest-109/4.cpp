/*
https://leetcode.com/contest/biweekly-contest-109/problems/ways-to-express-an-integer-as-sum-of-powers
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int poww(int a, int b) {
    int res = 1;
    for (int i = 1; i <= b; i++) {
      res *= a;
    }
    return res;
  }

  int numberOfWays(int n, int x) {
    long long MOD = 1000000000 + 7;
    long long cnt[301];
    for (int i = 0; i <= 300; i++) {
      cnt[i] = 0;
    }
    cnt[0] = 1;
    for (int i = 1; poww(i, x) <= n; i++) {
      for (int j = 300; j >= 1; j--) {
        if (j - poww(i, x) >= 0) {
          cnt[j] = (cnt[j] + cnt[j - poww(i, x)]) % MOD;
        }
      }
    }
    long long ans = cnt[n] % MOD;
    return (int)ans;
  }
};