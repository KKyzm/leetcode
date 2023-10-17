// Created by Yaniru at 2023/10/17 09:22
// leetgo: dev
// https://leetcode.cn/problems/sum-multiples/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int sumOfMultiples(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 or i % 5 == 0 or i % 7 == 0) {
        res += i;
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->sumOfMultiples(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
