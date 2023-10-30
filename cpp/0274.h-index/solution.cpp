// Created by Yaniru at 2023/10/29 10:37
// leetgo: dev
// https://leetcode.cn/problems/h-index/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int ans = 0;
    sort(citations.begin(), citations.end(), greater());
    for (int i = 0; i < citations.size(); i++) {
      int h = min(i + 1, citations[i]);
      if (ans < h)
        ans = h;
      else
        break;
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
