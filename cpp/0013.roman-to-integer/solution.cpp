// Created by Yaniru at 2023/10/16 17:13
// leetgo: dev
// https://leetcode.cn/problems/roman-to-integer/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
using namespace std;

// @lc code=begin

class Solution {
private:
  // clang-format off
  map<char, int> roman = {
    {'I', 1},   {'V', 5},
    {'X', 10},  {'L', 50},
    {'C', 100}, {'D', 500},
    {'M', 1000}
  };
  // clang-format on

public:
  int romanToInt(string s) {
    int last = 0;
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      int num = roman[s[i]];
      if (num < last) {
        num = -num;
      }
      last = num;
      res += num;
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->romanToInt(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
