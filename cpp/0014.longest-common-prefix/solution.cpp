// Created by Yaniru at 2023/10/16 17:35
// leetgo: dev
// https://leetcode.cn/problems/longest-common-prefix/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1)
      return strs[0];

    string res = "";
    int len = strs[0].length();
    for (auto str : strs) {
      if (str.length() < len)
        len = str.length();
    }

    for (int i = 0; i < len; i++) {
      char c = strs[0][i];
      for (auto str : strs) {
        if (str[i] != c) {
          return res;
        }
      }
      res += c;
    }

    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> strs;
  LeetCodeIO::scan(cin, strs);

  Solution *obj = new Solution();
  auto res = obj->longestCommonPrefix(strs);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
