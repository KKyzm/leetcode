// Created by Yaniru at 2023/10/17 10:30
// leetgo: dev
// https://leetcode.cn/problems/two-sum/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    if (sizeof(void *) == 8) {
      std::cout << "This is a 64-bit machine." << std::endl;
    } else if (sizeof(void *) == 4) {
      std::cout << "This is a 32-bit machine." << std::endl;
    } else {
      std::cout << "Unable to determine the system architecture." << std::endl;
    }

    return {};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int target;
  LeetCodeIO::scan(cin, target);

  Solution *obj = new Solution();
  auto res = obj->twoSum(nums, target);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
