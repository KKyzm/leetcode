// Created by Yaniru at 2023/11/02 09:02
// leetgo: dev
// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    int res = 0, last2 = -1, last1 = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= left && nums[i] <= right) {
        last1 = i;
      } else if (nums[i] > right) {
        last2 = i;
        last1 = -1;
      }
      if (last1 != -1) {
        res += last1 - last2;
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int left;
  LeetCodeIO::scan(cin, left);
  int right;
  LeetCodeIO::scan(cin, right);

  Solution *obj = new Solution();
  auto res = obj->numSubarrayBoundedMax(nums, left, right);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
