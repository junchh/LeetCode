/*
https://leetcode.com/contest/weekly-contest-358/problems/double-a-number-represented-as-a-linked-list
*/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    vector<int> num;
    while (head != nullptr) {
      num.push_back(head->val);
      head = head->next;
    }
    reverse(num.begin(), num.end());

    num.push_back(0);
    int siz = num.size();
    int carry = 0;
    for (int i = 0; i < siz; i++) {
      if (num[i] * 2 > 9) {
        num[i] = (num[i] * 2) % 10;
        num[i] += carry;
        carry = 1;
      } else {
        num[i] = num[i] * 2 + carry;
        carry = 0;
      }
    }
    ListNode* ne = nullptr;
    for (int i = 0; i < siz; i++) {
      if (i == siz - 1 && num[i] == 0) {
        continue;
      }
      ListNode* nw = new ListNode();
      nw->val = num[i];
      nw->next = ne;
      ne = nw;
    }

    return ne;
  }
};
