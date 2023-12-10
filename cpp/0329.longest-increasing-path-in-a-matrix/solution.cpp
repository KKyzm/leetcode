// Created by Yaniru at 2023/12/10 15:54
// leetgo: dev
// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=begin

class Solution {
  using martix_t = vector<vector<int>>;
  using graph_t = unordered_map<string, set<string>>;

  unordered_map<string, size_t> memo{};
  graph_t adjt{};

  void buildGraph(martix_t &matrix) {
    auto f = [&](size_t i, size_t j, size_t u, size_t v) -> void {
      if (isValid(matrix, u, v) and matrix[i][j] < matrix[u][v]) {
        adjt[str(i, j)].insert(str(u, v));
      }
    };
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[0].size(); j++) {
        f(i, j, i, j - 1);
        f(i, j, i, j + 1);
        f(i, j, i - 1, j);
        f(i, j, i + 1, j);
      }
    }
  }

  size_t longestPathFrom(const string key) {
    if (memo.find(key) != memo.end())
      return memo[key];
    auto adjlen = size_t{0};
    auto adj = adjt[key];
    for (auto a : adj) {
      adjlen = longestPathFrom(a) > adjlen ? longestPathFrom(a) : adjlen;
    }
    memo[key] = adjlen + 1;
    return adjlen + 1;
  }

  bool isValid(martix_t &matrix, size_t i, size_t j) {
    auto m = matrix.size();
    auto n = matrix[0].size();
    return (i >= 0) and (i < m) and (j >= 0) and (j < n);
  }

  string str(size_t i, size_t j) { return to_string(i) + "-" + to_string(j); }

public:
  int longestIncreasingPath(martix_t &matrix) {
    buildGraph(matrix);
    int ans = 0;
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[0].size(); j++) {
        auto key = str(i, j);
        if (memo.find(key) == memo.end()) {
          ans = longestPathFrom(key) > ans ? longestPathFrom(key) : ans;
        }
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> matrix;
  LeetCodeIO::scan(cin, matrix);

  Solution *obj = new Solution();
  auto res = obj->longestIncreasingPath(matrix);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
