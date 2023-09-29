// Created by Yaniru at 2023/09/29 13:31
// leetgo: dev
// https://leetcode.cn/problems/maximum-gap/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maximumGap(vector<int> &v) {
    if (v.size() < 2)
      return 0;

    auto nums = v;
    /* int m = nums[0]; */
    /* for (int i : nums) { */
    /*   m = max(i, m); */
    /* } */
    /* int c = 0; */
    /**/
    /* while (m > 0) { */
    /*   c++; */
    /*   m /= 10; */
    /* } */

    for (int i = 0; i < 10; i++) {
      vector<vector<int>> digit(10);
      for (int num : nums) {
        int idx = (num / (int)pow(10, i)) % 10;
        digit[idx].push_back(num);
      }
      nums = vector<int>();
      for (auto list : digit) {
        for (int num : list) {
          nums.push_back(num);
        }
      }
    }

    int max_gap = 0;
    for (int i = 1; i < nums.size(); i++) {
      int gap = nums[i] - nums[i - 1];
      max_gap = max(max_gap, gap);
    }
    return max_gap;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->maximumGap(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
