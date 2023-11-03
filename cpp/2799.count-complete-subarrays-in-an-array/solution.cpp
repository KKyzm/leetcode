// Created by Yaniru at 2023/11/02 19:11
// leetgo: dev
// https://leetcode.cn/problems/count-complete-subarrays-in-an-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <list>
#include <set>
using namespace std;

// @lc code=begin

class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    int ans = 0;
    auto v = vector<int>(nums.size(), 0);
    auto ml = unordered_map<int, int>{};
    for (auto num : nums) {
      ml[num]++;
    }

    for (int i = 0; i < nums.size(); i++) {
      auto mr = unordered_map<int, int>(ml);
      for (int j = nums.size() - 1; j >= i; j--) {
        ans++;
        if (mr[nums[j]] == 1) {
          break;
        }
        mr[nums[j]] -= 1;
      }

      if (ml[nums[i]] == 1)
        break;
      ml[nums[i]]--;
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->countCompleteSubarrays(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
