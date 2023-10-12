// Created by Yaniru at 2023/10/12 09:51
// leetgo: dev
// https://leetcode.cn/problems/find-the-array-concatenation-value/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  long long findTheArrayConcVal(vector<int> &nums) {
    return concat(nums, 0, nums.size());
  }

  long long concat(vector<int> &nums, int l, int h) {
    if (l == h)
      return 0;
    if (l + 1 == h)
      return nums[l];
    ostringstream is;
    is << nums[l] << nums[h - 1];
    return stoll(is.str()) + concat(nums, l + 1, h - 1);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->findTheArrayConcVal(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
