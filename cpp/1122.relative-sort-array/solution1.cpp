// Created by Yaniru at 2023/09/26 21:00
// leetgo: dev
// https://leetcode.cn/problems/relative-sort-array/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans;

    set<int> s(arr1.begin(), arr1.end());
    for (int i : arr2) {
      int counts = count(arr1.begin(), arr1.end(), i);
      ans.insert(ans.end(), counts, i);
      s.erase(i);
    }

    vector<int> tmp(s.begin(), s.end());
    sort(tmp.begin(), tmp.end());
    for (int i : tmp) {
      int counts = count(arr1.begin(), arr1.end(), i);
      ans.insert(ans.end(), counts, i);
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> arr1;
  LeetCodeIO::scan(cin, arr1);
  vector<int> arr2;
  LeetCodeIO::scan(cin, arr2);

  Solution *obj = new Solution();
  auto res = obj->relativeSortArray(arr1, arr2);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
