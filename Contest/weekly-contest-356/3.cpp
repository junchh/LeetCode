/*
https://leetcode.com/contest/weekly-contest-356/problems/shortest-string-that-contains-three-strings
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  bool isIn(string b, string a) {
    int len = b.length();
    for (int i = 0; i + len - 1 < a.length(); i++) {
      if (a.substr(i, len) == b) {
        return true;
      }
    }
    return false;
  }
  string merge(string a, string b, string c) {
    int lena = a.length();
    int lenb = b.length();
    int lenc = c.length();
    string cur = "";
    if (lenb <= lena && isIn(b, a)) {
      cur = a;
    } else {
      for (int i = 0; i < lena; i++) {
        string subs = a.substr(i, lena - i);
        if (lena - i <= lenb && subs == b.substr(0, lena - i)) {
          cur = a.substr(0, i) + b;
          break;
        }
      }
    }
    if (cur == "") cur = a + b;
    string temp = "";
    int lencur = cur.length();
    if (lenc <= lencur && isIn(c, cur)) {
      temp = cur;
    } else {
      for (int i = 0; i < lencur; i++) {
        string subs = cur.substr(i, lencur - i);
        if (lencur - i <= lenc && subs == c.substr(0, lencur - i)) {
          temp = cur.substr(0, i) + c;
          break;
        }
      }
    }
    if (temp == "") temp = cur + c;
    cout << temp << '\n';
    return temp;
  }

  string minimumString(string a, string b, string c) {
    vector<string> s;
    s.push_back(merge(a, b, c));
    s.push_back(merge(a, c, b));
    s.push_back(merge(b, c, a));
    s.push_back(merge(b, a, c));
    s.push_back(merge(c, a, b));
    s.push_back(merge(c, b, a));

    int fmin = 10000000;
    for (auto x : s) {
      if (x.length() < fmin) {
        fmin = x.length();
      }
    }

    set<string> st;
    for (auto x : s) {
      if (x.length() == fmin) {
        st.insert(x);
      }
    }
    auto it = st.begin();
    return *it;
  }
};