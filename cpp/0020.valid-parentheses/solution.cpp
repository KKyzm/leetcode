// Created by Yaniru at 2023/09/29 14:00
// leetgo: dev
// https://leetcode.cn/problems/valid-parentheses/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if (isLeft(c)) {
        stk.push(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        char top = stk.top();
        stk.pop();
        if (!isPair(top, c)) {
          return false;
        }
      }
    }

    if (stk.empty()) {
      return true;
    } else {
      return false;
    }
  }

private:
  inline bool isLeft(char c) { return c == '(' or c == '[' or c == '{'; }
  inline bool isPair(char left, char right) {
    if (left == '(' and right == ')')
      return true;
    if (left == '[' and right == ']')
      return true;
    if (left == '{' and right == '}')
      return true;
    return false;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->isValid(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
