// Created by Yaniru at 2023/10/19 08:59
// leetgo: dev
// https://leetcode.cn/problems/tuple-with-same-product/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int tupleSameProduct(vector<int> &nums) {
    int ans = 0;
    unordered_map<int, int> s;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int num = nums[i] * nums[j];
        if (s.count(num)) {
          ans += s[num];
          s[num]++;
        } else {
          s[num] = 1;
        }
      }
    }
    return ans * 8;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->tupleSameProduct(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
