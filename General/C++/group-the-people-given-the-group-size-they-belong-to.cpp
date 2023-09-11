#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    vector<pair<int, int>> ng;
    for (int i = 0; i < n; i++) {
      ng.emplace_back(groupSizes[i], i);
    }
    sort(ng.begin(), ng.end());

    vector<vector<int>> res;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
      tmp.emplace_back(ng[i].second);
      if (tmp.size() == ng[i].first) {
        res.emplace_back(tmp);
        tmp.clear();
      }
    }
    return res;
  }
};