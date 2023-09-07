/*
https://leetcode.com/contest/weekly-contest-358/problems/apply-operations-to-maximize-score
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<int> pr;
  int lp[100005], lo[100005], st[100005][20];
  int cntPrime(int x) {
    set<int> st;
    while (x > 1) {
      st.insert(lp[x]);
      x /= lp[x];
    }
    return st.size();
  }
  int q(int l, int r) {
    l++;
    r++;
    int j = lo[r - l + 1];
    return max(st[l][j], st[r - (1 << j) + 1][j]);
  }

  long long binpow(long long a, long long b, long long m) {
    a = a % m;
    long long res = 1;
    while (b > 0) {
      if (b & 1) res = (res * a) % m;
      a = (a * a) % m;
      b >>= 1;
    }
    return res % m;
  }

  int maximumScore(vector<int>& nums, int k) {
    long long MOD = 1e9 + 7;
    for (int i = 2; i < 100005; i++) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }

      int siz = pr.size();
      for (int j = 0; j < siz && pr[j] <= lp[i] && i * pr[j] < 100005; j++) {
        lp[i * pr[j]] = pr[j];
      }
    }
    int n = nums.size();
    vector<int> cnt, prevIdx(n), nextIdx(n);
    map<int, int> idx;

    for (int i = 0; i < n; i++) {
      cnt.push_back(cntPrime(nums[i]));
      if (idx.find(cnt[i]) == idx.end()) {
        idx[cnt[i]] = i;
        prevIdx[i] = -1;
      } else {
        prevIdx[i] = idx[cnt[i]];
        idx[cnt[i]] = i;
      }
    }
    idx.clear();
    for (int i = n - 1; i >= 0; i--) {
      if (idx.find(cnt[i]) == idx.end()) {
        idx[cnt[i]] = i;
        nextIdx[i] = n;
      } else {
        nextIdx[i] = idx[cnt[i]];
        idx[cnt[i]] = i;
      }
    }

    for (int i = 2; i <= n; i++) {
      lo[i] = lo[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) {
      st[i][0] = cnt[i - 1];
    }

    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }

    vector<pair<long long, long long>> vt;
    for (int i = 0; i < n; i++) {
      int l = prevIdx[i] + 1, r = i, ans = -1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (q(mid, i) == cnt[i]) {
          ans = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      l = i, r = n - 1;
      int ans2 = -1;
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (q(i, mid) == cnt[i]) {
          ans2 = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      long long le = (i - ans + 1);
      long long ri = (ans2 - i + 1);
      vt.push_back({(long long)nums[i], le * ri});
    }

    sort(vt.begin(), vt.end(),
         [&](pair<long long, long long> a, pair<long long, long long> b) {
           if (a.first == b.first) {
             return a.second > b.second;
           } else {
             return a.first > b.first;
           }
         });
    long long ans = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += vt[i].second;
      if (k >= sum) {
        ans = (ans * binpow(vt[i].first, vt[i].second, MOD)) % MOD;
      } else {
        sum -= vt[i].second;
        long long dif = k - sum;
        if (dif != 0) {
          ans = (ans * binpow(vt[i].first, dif, MOD)) % MOD;
        }
        break;
      }
    }

    return ans;
  }
};