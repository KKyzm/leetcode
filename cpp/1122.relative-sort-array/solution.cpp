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
    int hash[1001];
    for (int i = 0; i < 1001; i++) {
      hash[i] = 0;
    }
    for (int i : arr1) {
      hash[i]++;
    }
    for (int i : arr2) {
      ans.insert(ans.end(), hash[i], i);
      hash[i] = 0;
    }
    for (int i = 0; i < 1001; i++) {
      ans.insert(ans.end(), hash[i], i);
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
