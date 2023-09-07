/*
https://leetcode.com/contest/weekly-contest-355/problems/split-strings-by-separator
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> res;
    for (auto x : words) {
      int len = x.length();
      string cur = "";
      for (int i = 0; i < len; i++) {
        if (x[i] == separator) {
          if (cur != "") res.push_back(cur);
          cur = "";
        } else {
          cur += x[i];
        }
      }
      if (cur != "") res.push_back(cur);
    }
    return res;
  }
};