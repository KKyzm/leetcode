// Created by Yaniru at 2023/11/02 00:49
// leetgo: dev
// https://leetcode.cn/problems/rings-and-rods/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// @lc code=begin

class Solution {
public:
  int countPoints(string rings) {
    int ans = 0;
    auto m = unordered_map<int, unordered_set<char>>{};
    for (int i = 0; i < rings.length() / 2; i++) {
      m[rings[2 * i + 1] - '0'].insert(rings[2 * i]);
    }
    for (auto p : m) {
      ans += p.second.size() == 3 ? 1 : 0;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string rings;
  LeetCodeIO::scan(cin, rings);

  Solution *obj = new Solution();
  auto res = obj->countPoints(rings);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
