/*
https://leetcode.com/contest/weekly-contest-357/problems/faulty-keyboard
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  string finalString(string s) {
    string res = "";
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'i') {
        reverse(res.begin(), res.end());
      } else {
        res += s[i];
      }
    }
    return res;
  }
};