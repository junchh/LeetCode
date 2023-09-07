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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode*> ar = {nullptr};
    auto cur = head;
    int n = 0;
    while (cur != nullptr) {
      ar.emplace_back(cur);
      cur = cur->next;
      n++;
    }
    for (int i = right; i >= left + 1; i--) {
      ar[i]->next = ar[i - 1];
    }
    if (left == 1) {
      if (right + 1 <= n) {
        ar[left]->next = ar[right + 1];
      } else {
        ar[left]->next = nullptr;
      }
      return ar[right];
    } else {
      ar[left - 1]->next = ar[right];
      if (right + 1 <= n) {
        ar[left]->next = ar[right + 1];
      } else {
        ar[left]->next = nullptr;
      }
      return ar[1];
    }
  }
};