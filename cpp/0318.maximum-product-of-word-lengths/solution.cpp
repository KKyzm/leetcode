// Created by Yaniru at 2023/11/06 10:24
// leetgo: dev
// https://leetcode.cn/problems/maximum-product-of-word-lengths/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstdint>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxProduct(vector<string> &words) {
    int ans = 0;
    auto v = vector<pair<uint32_t, int>>();
    for (auto word : words) {
      int len = word.length();
      uint32_t layout = 0;
      for (auto c : word) {
        layout |= 1 << static_cast<int>(c - 'a');
      }
      v.push_back(make_pair(layout, len));
    }
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        if ((v[i].first & v[j].first) != 0)
          continue;
        ans = max(ans, v[i].second * v[j].second);
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> words;
  LeetCodeIO::scan(cin, words);

  Solution *obj = new Solution();
  auto res = obj->maxProduct(words);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
