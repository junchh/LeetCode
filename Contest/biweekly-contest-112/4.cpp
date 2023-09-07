/*
https://leetcode.com/contest/biweekly-contest-112/problems/count-k-subsequences-of-a-string-with-maximum-beauty
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int countKSubsequencesWithMaxBeauty(string s, int k) {
    const long long MOD = 1e9 + 7;
    map<char, int> mp;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    int m = mp.size();
    if (k > m) {
      return 0;
    }

    vector<int> v;
    for (auto x : mp) {
      v.emplace_back(x.second);
    }
    sort(v.begin(), v.end(), greater<int>());

    int maxSum = 0;
    for (int i = 0; i < k; i++) {
      maxSum += v[i];
    }
    int val = v[k - 1];
    long long ans = 1;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      if (v[i] != val) {
        long long h = (long long)v[i];
        ans = (ans * h) % MOD;
      } else {
        cnt++;
      }
    }
    int tot = 0;
    for (int i = 0; i < m; i++) {
      if (v[i] == val) {
        tot++;
      }
    }

    auto binpow = [&](long long a, long long b) {
      a = a % MOD;
      long long res = 1;
      while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
      }
      return res;
    };

    auto com = [&](long long a, long long b) {
      long long num = 1;
      for (long long i = 1; i <= a; i++) {
        num = (num * i) % MOD;
      }
      long long denom = 1;
      for (long long i = 1; i <= b; i++) {
        denom = (denom * i) % MOD;
      }
      for (long long i = 1; i <= a - b; i++) {
        denom = (denom * i) % MOD;
      }
      long long res = (num * binpow(denom, MOD - 2)) % MOD;
      return res;
    };

    long long comm = (binpow((long long)val, cnt) * com(tot, cnt)) % MOD;
    ans = (ans * comm) % MOD;
    return ans;
  }
};