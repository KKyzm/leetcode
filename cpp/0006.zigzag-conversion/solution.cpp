// Created by Yaniru at 2023/10/12 22:31
// leetgo: dev
// https://leetcode.cn/problems/zigzag-conversion/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  enum Direction { UP, DOWN };
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    Direction dir = Direction::UP;
    int curlev = 0;
    vector<string> v(numRows);
    for (int i = 0; i < s.length(); i++) {
      v[curlev].push_back(s[i]);
      if (dir == Direction::DOWN) {
        if (curlev == 0) {
          curlev = 1;
          dir = Direction::UP;
        } else {
          curlev--;
        }
      } else if (dir == Direction::UP) {
        if (curlev == numRows - 1) {
          curlev = numRows - 2;
          dir = Direction::DOWN;
        } else {
          curlev++;
        }
      }
    }

    string res;
    for (int i = 0; i < numRows; i++) {
      res += v[i];
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
  int numRows;
  LeetCodeIO::scan(cin, numRows);

  Solution *obj = new Solution();
  auto res = obj->convert(s, numRows);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
