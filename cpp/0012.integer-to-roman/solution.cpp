// Created by Yaniru at 2023/10/16 17:22
// leetgo: dev
// https://leetcode.cn/problems/integer-to-roman/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
private:
  // clang-format off
  map<int, string> m = {
    {1, "I"},    {4, "IV"},   {5, "V"},   {9, "IX"},
    {10, "X"},   {40, "XL"},  {50, "L"},  {90, "XC"},
    {100, "C"},  {400, "CD"}, {500, "D"}, {900, "CM"},
    {1000, "M"}, {INT_MAX, "IMPOSSIBLE"}
  };
  // clang-format on

public:
  string intToRoman(int num) {
    string res = "";
    auto it = m.end();
    it--;
    while (num > 0) {
      while (it->first > num) {
        it--;
      }
      res += it->second;
      num -= it->first;
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int num;
  LeetCodeIO::scan(cin, num);

  Solution *obj = new Solution();
  auto res = obj->intToRoman(num);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
