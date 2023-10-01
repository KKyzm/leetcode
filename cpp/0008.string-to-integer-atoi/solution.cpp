// Created by Yaniru at 2023/10/01 13:11
// leetgo: dev
// https://leetcode.cn/problems/string-to-integer-atoi/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

// @lc code=begin

class Solution {
public:
  int myAtoi(string s) {
    int ans = 0;
    istringstream is(s);
    is >> ans;
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->myAtoi(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
