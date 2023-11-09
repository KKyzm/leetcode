// Created by Yaniru at 2023/11/08 13:39
// leetgo: dev
// https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    if (s.empty())
      return 0;
    int ans = 0;
    int i = 0;
    while (i < s.length()) {
      int cnt0 = 0;
      int cnt1 = 0;
      while (s[i] == '0' and i < s.length()) {
        cnt0++;
        i++;
      }
      while (s[i] == '1' and i < s.length()) {
        cnt1++;
        i++;
      }
      ans = max(ans, 2 * min(cnt0, cnt1));
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
  auto res = obj->findTheLongestBalancedSubstring(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
