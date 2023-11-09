// Created by Yaniru at 2023/11/06 10:52
// leetgo: dev
// https://leetcode.cn/problems/perfect-squares/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
public:
  int numSquares(int n) {
    auto q = queue<pair<int, int>>{};
    q.push(make_pair(n, 0));
    while (q.empty() == false) {
      auto f = q.front();
      q.pop();
      for (int i = 1; i <= 100; i++) {
        if (i * i > f.first)
          break;
        if (i * i == f.first)
          return f.second + 1;
        q.push(make_pair(f.first - i * i, f.second + 1));
      }
    }
    return 0;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->numSquares(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
