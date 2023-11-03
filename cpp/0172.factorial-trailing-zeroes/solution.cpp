// Created by Yaniru at 2023/11/03 10:17
// leetgo: dev
// https://leetcode.cn/problems/factorial-trailing-zeroes/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  int foo(int num, int factor) {
    if (num % factor != 0)
      return 0;
    int ans = 0;
    while (num % factor == 0) {
      ans++;
      num /= factor;
    }
    return ans;
  }

public:
  int trailingZeroes(int n) {
    int n2 = 0;
    int n5 = 0;
    for (int i = 1; i <= n; i++) {
      n2 += foo(i, 2);
      n5 += foo(i, 5);
    }
    return min(n2, n5);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->trailingZeroes(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
