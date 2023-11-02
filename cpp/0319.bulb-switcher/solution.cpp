// Created by Yaniru at 2023/11/02 01:01
// leetgo: dev
// https://leetcode.cn/problems/bulb-switcher/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

// @lc code=begin

class Solution {

public:
  int bulbSwitch(int n) { return sqrt(n + 0.5); }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->bulbSwitch(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
