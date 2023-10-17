// Created by Yaniru at 2023/10/17 11:05
// leetgo: dev
// https://leetcode.cn/problems/generate-parentheses/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
private:
  vector<string> res;

public:
  vector<string> generateParenthesis(int n) {
    foo("", n, 0, 0);
    return res;
  }

  void foo(string str, int n, int l, int r) {
    if (l < n) {
      foo(str + "(", n, l + 1, r);
    }
    if (r < l) {
      foo(str + ")", n, l, r + 1);
    }

    if (l == n and r == n) {
      res.push_back(str);
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->generateParenthesis(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
