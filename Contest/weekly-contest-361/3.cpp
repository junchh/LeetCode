/*
https://leetcode.com/contest/weekly-contest-361/problems/count-of-interesting-subarrays
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    int n = nums.size();
    vector<int> ar(n + 1, 0), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
      ar[i + 1] = (nums[i] % modulo == k);
      prefix[i + 1] = prefix[i] + ar[i + 1];
    }
    map<int, int> mp;
    mp[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int g = (prefix[i] + modulo - k) % modulo;
      ans += (long long)mp[g];
      mp[prefix[i] % modulo]++;
    }
    return ans;
  }
};