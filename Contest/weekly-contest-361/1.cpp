/*
https://leetcode.com/contest/weekly-contest-361/problems/count-symmetric-integers
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int countSymmetricIntegers(int low, int high) {
    int cnt = 0;
    for (int i = low; i <= high; i++) {
      string s = "";
      int g = i;
      while (g > 9) {
        s += (g % 10) + '0';
        g /= 10;
      }
      s += g + '0';
      int len = s.length();
      int sum = 0;
      if (len % 2 == 0) {
        for (int i = 0; i < len / 2; i++) {
          sum += s[i] - '0';
        }
        int sum2 = 0;
        for (int i = len - 1; i >= len / 2; i--) {
          sum2 += s[i] - '0';
        }
        if (sum == sum2) cnt++;
      }
    }
    return cnt;
  }
};