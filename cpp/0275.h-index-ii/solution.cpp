// Created by Yaniru at 2023/10/30 09:39
// leetgo: dev
// https://leetcode.cn/problems/h-index-ii/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    int h = citations.size();
    int l = 0;
    int ans = 0;
    while (l < h) {
      int m = l + (h - l) / 2;
      if (citations[m] == n - m) {
        return n - m;
      } else if (citations[m] > n - m) {
        h = m;
        ans = max(ans, n - m);
      } else {
        l = m + 1;
        ans = max(ans, citations[m]);
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> citations;
  LeetCodeIO::scan(cin, citations);

  Solution *obj = new Solution();
  auto res = obj->hIndex(citations);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
