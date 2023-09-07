/*
https://leetcode.com/contest/biweekly-contest-111/problems/number-of-beautiful-integers-in-the-range
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<int> dig;
  int divi;
  int dp[10][20][11][11][2][2];
  int h;
  int fun(int pos, int rem, int cntEven, int cntOdd, int free,
          int isFrontZero) {
    if (dp[pos][rem][cntEven][cntOdd][free][isFrontZero] != -1)
      return dp[pos][rem][cntEven][cntOdd][free][isFrontZero];

    int res = 0;
    int limit = 9;
    if (free == 0) {
      limit = dig[pos];
    }

    if (pos == h - 1) {
      int ans = 0;
      for (int i = 0; i <= limit; i++) {
        int newRem = (rem * 10 + i) % divi;
        int newCntEven = cntEven;
        int newCntOdd = cntOdd;
        if (i % 2 == 0) {
          newCntEven++;
        } else {
          newCntOdd++;
        }
        if (newCntEven == newCntOdd && newRem == 0) {
          ans++;
        }
      }
      dp[pos][rem][cntEven][cntOdd][free][isFrontZero] = ans;
      return dp[pos][rem][cntEven][cntOdd][free][isFrontZero];
    }

    int ans = 0;
    for (int i = 0; i <= limit; i++) {
      int newRem = (rem * 10 + i) % divi;
      int newCntEven = cntEven;
      int newCntOdd = cntOdd;
      if (i % 2 == 0) {
        if (i != 0) {
          newCntEven++;
        } else {
          if (isFrontZero == 0) {
            newCntEven++;
          }
        }
      } else {
        newCntOdd++;
      }
      int newFrontZero;
      if (isFrontZero == 1 && i == 0) {
        newFrontZero = 1;
      } else if (isFrontZero == 1 && i != 0) {
        newFrontZero = 0;
      } else if (isFrontZero == 0 && i == 0) {
        newFrontZero = 0;
      } else if (isFrontZero == 0 && i != 0) {
        newFrontZero = 0;
      }
      if (i == limit && free == 0) {
        ans += fun(pos + 1, newRem, newCntEven, newCntOdd, 0, newFrontZero);
      } else {
        ans += fun(pos + 1, newRem, newCntEven, newCntOdd, 1, newFrontZero);
      }
    }
    dp[pos][rem][cntEven][cntOdd][free][isFrontZero] = ans;
    return dp[pos][rem][cntEven][cntOdd][free][isFrontZero];
  }

  int numberOfBeautifulIntegers(int low, int high, int k) {
    divi = k;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 20; j++) {
        for (int a = 0; a < 11; a++) {
          for (int b = 0; b < 11; b++) {
            dp[i][j][a][b][0][0] = -1;
            dp[i][j][a][b][0][1] = -1;
            dp[i][j][a][b][1][0] = -1;
            dp[i][j][a][b][1][1] = -1;
          }
        }
      }
    }
    while (high > 9) {
      dig.push_back(high % 10);
      high /= 10;
    }
    dig.push_back(high);
    reverse(dig.begin(), dig.end());
    h = dig.size();
    int answerHigh = fun(0, 0, 0, 0, 0, 1);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 20; j++) {
        for (int a = 0; a < 11; a++) {
          for (int b = 0; b < 11; b++) {
            dp[i][j][a][b][0][0] = -1;
            dp[i][j][a][b][0][1] = -1;
            dp[i][j][a][b][1][0] = -1;
            dp[i][j][a][b][1][1] = -1;
          }
        }
      }
    }
    dig.clear();
    low--;
    while (low > 9) {
      dig.push_back(low % 10);
      low /= 10;
    }
    dig.push_back(low);
    reverse(dig.begin(), dig.end());

    h = dig.size();
    int answerLow = fun(0, 0, 0, 0, 0, 1);
    return answerHigh - answerLow;
  }
};