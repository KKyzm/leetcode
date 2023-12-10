// Created by Yaniru at 2023/12/10 15:47
// leetgo: dev
// https://leetcode.cn/problems/is-subsequence/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = -1;
    for (auto c : s) {
      i++;
      while (i < t.length()) {
        if (c == t[i]) {
          break;
        }
        i++;
      }
      if (i == t.length())
        return false;
    }
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);
  string t;
  LeetCodeIO::scan(cin, t);

  Solution *obj = new Solution();
  auto res = obj->isSubsequence(s, t);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
