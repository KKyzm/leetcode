// Created by Yaniru at 2023/10/01 13:06
// leetgo: dev
// https://leetcode.cn/problems/palindrome-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isPalindrome(int x) {
    ostringstream os;
    os << x;
    string str = os.str();
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
      if (str[i] != str[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int x;
  LeetCodeIO::scan(cin, x);

  Solution *obj = new Solution();
  auto res = obj->isPalindrome(x);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
