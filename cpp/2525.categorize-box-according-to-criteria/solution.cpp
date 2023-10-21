// Created by Yaniru at 2023/10/20 10:15
// leetgo: dev
// https://leetcode.cn/problems/categorize-box-according-to-criteria/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  // clang-format off
  vector<vector<string>> categories = {
    {"Both", "Bulky"},
    {"Heavy", "Neither"}
  };
  // clang-format on

  bool isBulky(int length, int width, int height) {
    if (length >= 1E4 || width >= 1E4 || height >= 1E4) {
      return true;
    }
    unsigned long long volume = (unsigned long long)length * width * height;
    if (volume >= 1E9) {
      return true;
    }
    return false;
  }

  bool isHeavy(int mass) { return mass >= 100; }

public:
  string categorizeBox(int length, int width, int height, int mass) {
    int i = isBulky(length, width, height) ? 0 : 1;
    int j = isHeavy(mass) ? 0 : 1;
    return categories[i][j];
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int length;
  LeetCodeIO::scan(cin, length);
  int width;
  LeetCodeIO::scan(cin, width);
  int height;
  LeetCodeIO::scan(cin, height);
  int mass;
  LeetCodeIO::scan(cin, mass);

  Solution *obj = new Solution();
  auto res = obj->categorizeBox(length, width, height, mass);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
