// Created by Yaniru at 2023/11/15 11:27
// leetgo: dev
// https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maximizeSum(vector<int> &nums, int k) {
    int m = *max_element(nums.begin(), nums.end());
    return m * k + k * (k - 1) / 2;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->maximizeSum(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
