// Created by Yaniru at 2023/10/01 13:51
// leetgo: dev
// https://leetcode.cn/problems/powx-n/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == -1)
      return (1 / x);
    if (x == 0 or x == 1 or n == 1)
      return x;

    double t = myPow(x, n / 2);
    x = n > 0 ? x : 1 / x;
    return n % 2 == 0 ? t * t : t * t * x;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  double x;
  LeetCodeIO::scan(cin, x);
  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->myPow(x, n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
