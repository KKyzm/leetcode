// Created by Yaniru at 2023/10/12 22:54
// leetgo: dev
// https://leetcode.cn/problems/container-with-most-water/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max_height = 0;
    int max_area = 0;

    for (int i = 0; i < height.size(); i++) {
      if (height[i] <= max_height) {
        continue;
      }
      max_height = height[i];
      for (int j = i + 1; j < height.size(); j++) {
        max_area = max(max_area, min(height[i], height[j]) * (j - i));
      }
    }
    return max_area;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> height;
  LeetCodeIO::scan(cin, height);

  Solution *obj = new Solution();
  auto res = obj->maxArea(height);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
