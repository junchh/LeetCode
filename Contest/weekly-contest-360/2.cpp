/*
https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  long long minimumPossibleSum(int n, int target) {
    long long sum = 0;
    set<int> st;
    int g = 1;
    for (int i = 1; i <= n; i++) {
      while (st.count(target - g)) {
        g++;
      }
      sum += (long long)g;
      st.insert(g);
      g++;
    }
    return sum;
  }
};