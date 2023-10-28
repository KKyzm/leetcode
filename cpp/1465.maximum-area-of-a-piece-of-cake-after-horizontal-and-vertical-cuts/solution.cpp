// Created by Yaniru at 2023/10/27 09:31
// leetgo: dev
// https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  static constexpr int MOD = 1e9 + 7;

  int maxInterval(vector<int> &arr) {
    int interval = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] - arr[i - 1] > interval) {
        interval = arr[i] - arr[i - 1];
      }
    }
    return interval;
  }

public:
  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);
    int max_h = maxInterval(horizontalCuts);
    int max_w = maxInterval(verticalCuts);

    return ((long long)max_h % MOD * max_w % MOD) % MOD;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int h;
  LeetCodeIO::scan(cin, h);
  int w;
  LeetCodeIO::scan(cin, w);
  vector<int> horizontalCuts;
  LeetCodeIO::scan(cin, horizontalCuts);
  vector<int> verticalCuts;
  LeetCodeIO::scan(cin, verticalCuts);

  Solution *obj = new Solution();
  auto res = obj->maxArea(h, w, horizontalCuts, verticalCuts);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
