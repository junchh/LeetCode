#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> valley;

    for (int i = 0; i < n; i++) {
      bool l = (i == 0) ? 1 : (ratings[i] <= ratings[i - 1]);
      bool r = (i == n - 1) ? 1 : (ratings[i] <= ratings[i + 1]);
      if (l && r) valley.emplace_back(i);
    }

    vector<int> res(n);
    for (auto v : valley) {
      res[v] = 1;
      int cur = 2;
      for (int i = v + 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
          res[i] = cur;
          cur++;
        } else {
          break;
        }
      }

      cur = 2;
      for (int i = v - 1; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
          if (res[i] >= cur) break;
          res[i] = cur;
          cur++;
        } else {
          break;
        }
      }
    }

    int ans = accumulate(res.begin(), res.end(), 0);
    return ans;
  }
};