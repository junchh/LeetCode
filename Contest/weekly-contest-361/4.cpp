/*
https://leetcode.com/contest/weekly-contest-361/problems/minimum-edge-weight-equilibrium-queries-in-a-tree
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int N;
  int LOGN = 20;
  vector<int> par, depth;
  vector<vector<int>> up, dp;
  vector<vector<pair<int, int>>> adj;

  void dfs(int v, int p) {
    par[v] = p;
    up[v][0] = p;
    for (auto x : adj[v]) {
      if (x.first != p) {
        for (int i = 1; i <= 26; i++) {
          dp[x.first][i] = dp[v][i];
        }
        dp[x.first][x.second]++;
        depth[x.first] = depth[v] + 1;
        dfs(x.first, v);
      }
    }
  }

  int lca(int a, int b) {
    if (depth[a] < depth[b]) {
      swap(a, b);
    }
    int len = depth[a] - depth[b];
    for (int j = LOGN - 1; j >= 0; j--) {
      if (len & (1 << j)) {
        a = up[a][j];
      }
    }
    if (a == b) return a;
    for (int j = LOGN - 1; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
      }
    }
    return up[a][0];
  }
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges,
                                   vector<vector<int>>& queries) {
    par = vector<int>(n, -1);
    depth = vector<int>(n, 0);
    up = vector<vector<int>>(n, vector<int>(LOGN, 0));
    dp = vector<vector<int>>(n, vector<int>(27, 0));
    adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    for (auto x : edges) {
      adj[x[0]].push_back({x[1], x[2]});
      adj[x[1]].push_back({x[0], x[2]});
    }
    dfs(0, 0);
    for (int i = 1; i < LOGN; i++) {
      for (int j = 0; j < n; j++) {
        up[j][i] = up[up[j][i - 1]][i - 1];
      }
    }
    vector<int> res;

    for (auto x : queries) {
      int c = lca(x[0], x[1]);
      int cnt = 0;
      int fmax = 0;
      for (int i = 1; i <= 26; i++) {
        int sum = dp[x[0]][i] + dp[x[1]][i] - 2 * dp[c][i];
        if (sum != 0) {
          cnt += sum;
          fmax = max(fmax, sum);
        }
      }
      res.emplace_back(cnt - fmax);
    }
    return res;
  }
};