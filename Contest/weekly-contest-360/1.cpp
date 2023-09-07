/*
https://leetcode.com/contest/weekly-contest-360/problems/furthest-point-from-origin
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int sum = 0;
    int k = 0;
    for (auto c : moves) {
      if (c == 'L') {
        sum++;
      } else if (c == 'R') {
        sum--;
      } else {
        k++;
      }
    }
    return abs(sum) + k;
  }
};