/*
https://leetcode.com/contest/biweekly-contest-109/problems/sort-vowels-in-a-string
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  string sortVowels(string s) {
    int n = s.length();
    map<char, int> mp;
    mp['A'] = 0;
    mp['E'] = 1;
    mp['I'] = 2;
    mp['O'] = 3;
    mp['U'] = 4;
    mp['a'] = 5;
    mp['e'] = 6;
    mp['i'] = 7;
    mp['o'] = 8;
    mp['u'] = 9;

    string vowel = "";
    for (int i = 0; i < n; i++) {
      if (mp.find(s[i]) != mp.end()) {
        vowel += s[i];
      }
    }

    auto cmp = [&](char a, char b) { return mp[a] < mp[b]; };

    sort(vowel.begin(), vowel.end(), cmp);
    string res = "";
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (mp.find(s[i]) == mp.end()) {
        res += s[i];
      } else {
        res += vowel[cur];
        cur++;
      }
    }
    return res;
  }
};