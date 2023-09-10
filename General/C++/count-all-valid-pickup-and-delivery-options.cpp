#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countOrders(int n) {
    const int MOD = 1e9 + 7;

    auto binpow = [&](int a, int b) -> int {
      a = a % MOD;
      long long res = 1;
      while (b > 0) {
        if (b & 1) res = (res * 1ll * a) % MOD;
        a = (1ll * a * a) % MOD;
        b >>= 1;
      }
      return res;
    };

    int po = 1;
    int ans = 1;
    for (int i = 1; i <= 2 * n; i++) {
      if (i <= n) po = (1ll * po * 2) % MOD;
      ans = (1ll * ans * i) % MOD;
    }
    ans = (1ll * ans * binpow(po, MOD - 2)) % MOD;
    return ans;
  }
};