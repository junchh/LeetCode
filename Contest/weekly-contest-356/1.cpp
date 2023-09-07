/*
https://leetcode.com/contest/weekly-contest-356/problems/number-of-employees-who-met-the-target
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int cnt = 0;
    for (auto x : hours) {
      if (x >= target) {
        cnt++;
      }
    }
    return cnt;
  }
};
