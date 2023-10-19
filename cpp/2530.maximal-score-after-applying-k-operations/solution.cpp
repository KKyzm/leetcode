// Created by Yaniru at 2023/10/18 09:07
// leetgo: dev
// https://leetcode.cn/problems/maximal-score-after-applying-k-operations/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  long long maxKelements(vector<int> &nums, int k) {
    if (nums.empty())
      return 0;

    priority_queue<int> pq(nums.begin(), nums.end());
    long long res = 0;
    while (k > 0) {
      int num = pq.top();
      res += num;
      pq.pop();
      pq.push(ceil(num / 3.0));
      k--;
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
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->maxKelements(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
