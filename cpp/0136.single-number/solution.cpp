// Created by Yaniru at 2023/10/14 17:15
// leetgo: dev
// https://leetcode.cn/problems/single-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

// @lc code=begin

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    unordered_set<int> s;
    for (int num : nums) {
      if (s.find(num) != s.end()) {
        s.erase(num);
      } else {
        s.insert(num);
      }
    }
    assert(s.size() == 1);
    return *s.begin();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->singleNumber(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
