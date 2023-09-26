// Created by Yaniru at 2023/09/26 20:52
// leetgo: dev
// https://leetcode.cn/problems/height-checker/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    int ans = 0;
    vector expected = heights;
    sort(expected.begin(), expected.end());
    for (int i = 0; i < heights.size(); i++) {
      if (expected[i] != heights[i])
        ans++;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> heights;
  LeetCodeIO::scan(cin, heights);

  Solution *obj = new Solution();
  auto res = obj->heightChecker(heights);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
