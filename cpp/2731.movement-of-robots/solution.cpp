// Created by Yaniru at 2023/10/17 09:33
// leetgo: dev
// https://leetcode.cn/problems/movement-of-robots/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
private:
  const int UPPER_BOUND = 1e9 + 7;

public:
  int sumDistance(vector<int> &nums, string s, int d) {
    if (nums.size() != s.length())
      return -1;

    int res = 0;
    vector<long long> lnums(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      if (s[i] == 'R') {
        lnums[i] = ((long long)(nums[i]) + d);
      } else {
        lnums[i] = ((long long)(nums[i]) - d);
      }
    }
    sort(lnums.begin(), lnums.end());
    for (int i = 1; i < lnums.size(); ++i) {
      long long distance = (lnums[i] - lnums[i - 1]);
      // wrong
      /* res += distance * (((lnums.size() - i) * i) % UPPER_BOUND); */
      // right
      res += distance * (lnums.size() - i) % UPPER_BOUND * i % UPPER_BOUND;
      res %= UPPER_BOUND;
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
  string s;
  LeetCodeIO::scan(cin, s);
  int d;
  LeetCodeIO::scan(cin, d);

  Solution *obj = new Solution();
  auto res = obj->sumDistance(nums, s, d);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
