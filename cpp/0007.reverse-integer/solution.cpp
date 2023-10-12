// Created by Yaniru at 2023/10/12 22:05
// leetgo: dev
// https://leetcode.cn/problems/reverse-integer/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

// @lc code=begin

class Solution {
public:
  int reverse(int x) {
    if (x == 0)
      return 0;

    ostringstream os;
    os << x;
    string str = os.str();
    if (x > 0) {
      str = strReverse(str);
    } else if (x < 0) {
      str = "-" + strReverse(str.substr(1));
    }

    int res;
    try {
      res = stoi(str);
    } catch (out_of_range const &ex) {
      res = 0;
    }
    return res;
  }

  string strReverse(string str) {
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
      swap(str[i], str[j]);
      i++;
      j--;
    }
    return str;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int x;
  LeetCodeIO::scan(cin, x);

  Solution *obj = new Solution();
  auto res = obj->reverse(x);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
