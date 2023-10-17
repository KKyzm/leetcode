// Created by Yaniru at 2023/10/16 22:30
// leetgo: dev
// https://leetcode.cn/problems/3sum/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {}
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->threeSum(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
