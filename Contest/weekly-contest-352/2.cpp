/*
https://leetcode.com/contest/weekly-contest-352/problems/prime-pairs-with-target-sum
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<bool> prime = vector<bool>(n + 1, 1);

    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= n; i++) {
      if (prime[i]) {
        for (int j = 2 * i; j <= n; j += i) {
          prime[j] = 0;
        }
      }
    }

    vector<vector<int>> result;
    for (int i = 2; i <= n / 2; i++) {
      if (prime[i] && prime[n - i]) {
        vector<int> temp = {i, n - i};
        result.push_back(temp);
      }
    }

    return result;
  }
};