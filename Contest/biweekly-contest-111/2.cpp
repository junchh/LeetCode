/*
https://leetcode.com/contest/biweekly-contest-111/problems/make-string-a-subsequence-using-cyclic-increments
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < n && j < m) {
      if (str2[j] == str1[i]) {
        i++;
        j++;
        cnt++;
      } else if (str1[i] == 'z' && str2[j] == 'a') {
        i++;
        j++;
        cnt++;
      } else if (str1[i] + 1 == str2[j]) {
        i++;
        j++;
        cnt++;
      } else {
        i++;
      }
    }
    return cnt == str2.length();
  }
};