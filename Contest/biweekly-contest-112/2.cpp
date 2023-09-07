/*
https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-ii
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    vector<vector<char>> s(4, vector<char>());
    int n = s1.length();
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        s[0].emplace_back(s1[i]);
        s[2].emplace_back(s2[i]);
      } else {
        s[1].emplace_back(s1[i]);
        s[3].emplace_back(s2[i]);
      }
    }
    for (int i = 0; i < 4; i++) {
      sort(s[i].begin(), s[i].end());
    }
    int siz = s[0].size();
    for (int i = 0; i < siz; i++) {
      if (s[0][i] != s[2][i]) {
        return false;
      }
    }
    int siz2 = s[1].size();
    for (int i = 0; i < siz2; i++) {
      if (s[1][i] != s[3][i]) {
        return false;
      }
    }
    return true;
  }
};