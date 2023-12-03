// Created by Yaniru at 2023/11/14 16:22
// leetgo: dev
// https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <climits>
#include <memory>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  unique_ptr<vector<vector<int>>> graph{};

  int foo(int v, int distanceThreshold) {
    int ans = 0;
    auto q = make_unique<queue<pair<int, int>>>();
    auto visited = make_unique<vector<int>>(graph->size(), -1);
    q->push({v, 0});
    (*visited)[v] = 0;
    while (q->empty() == false) {
      auto item = q->front();
      q->pop();
      for (int i = 0; i < (*graph)[item.first].size(); i++) {
        if ((*graph)[item.first][i] == 0) {
          continue;
        }
        auto cost = item.second + (*graph)[item.first][i];
        if ((*visited)[i] >= 0 and (*visited)[i] <= cost) {
          continue;
        }
        if (cost <= distanceThreshold) {
          if ((*visited)[i] < 0)
            ans++;
          q->push({i, cost});
          (*visited)[i] = cost;
        }
      }
    }
    return ans;
  }

public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    int ans = 0;
    int cnt = INT_MAX;
    graph.reset(new vector<vector<int>>(n, vector<int>(n, 0)));
    for (auto e : edges) {
      (*graph)[e[0]][e[1]] = e[2];
      (*graph)[e[1]][e[0]] = e[2];
    }
    for (int i = 0; i < n; i++) {
      int ncnt = foo(i, distanceThreshold);
      if (ncnt <= cnt) {
        cnt = ncnt;
        ans = i;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);
  vector<vector<int>> edges;
  LeetCodeIO::scan(cin, edges);
  int distanceThreshold;
  LeetCodeIO::scan(cin, distanceThreshold);

  Solution *obj = new Solution();
  auto res = obj->findTheCity(n, edges, distanceThreshold);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
