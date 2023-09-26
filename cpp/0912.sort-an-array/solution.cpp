// Created by Yaniru at 2023/09/26 21:52
// leetgo: dev
// https://leetcode.cn/problems/sort-an-array/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<vector<int>> digits(10);
    for (int &num : nums) {
      num += 50000;
    }

    int max_value = *max_element(nums.begin(), nums.end());
    int max_digit = 0;
    while (max_value > 0) {
      max_digit++;
      max_value /= 10;
    }

    for (int i = 0; i < max_digit; i++) {
      for (int num : nums) {
        int idx = (num / (int)pow(10, i)) % 10;
        digits[idx].push_back(num);
      }
      nums = vector<int>();
      for (auto digit : digits) {
        nums.insert(nums.end(), digit.begin(), digit.end());
      }
      digits = vector<vector<int>>(10);
    }

    for (int &num : nums) {
      num -= 50000;
    }
    return nums;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->sortArray(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
