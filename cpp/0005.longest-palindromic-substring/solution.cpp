// Created by Yaniru at 2023/10/14 17:30
// leetgo: dev
// https://leetcode.cn/problems/longest-palindromic-substring/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
private:
  string ans;

  inline void foo(int h, int l, string &s) {
    while (h >= 0 && l < s.size() && s[h] == s[l]) {
      h--;
      l++;
    }
    // h + 1 ... l - 1
    int len = l - h - 1;
    if (len > ans.size()) {
      ans = s.substr(h + 1, len);
    }
  }

public:
  string longestPalindrome(string s) {
    ans = s[0];
    for (int i = 1; i < s.size(); i++) {
      foo(i - 1, i + 1, s);
      if (s[i] == s[i - 1])
        foo(i - 2, i + 1, s);
    }
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
  auto res = obj->longestPalindrome(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
