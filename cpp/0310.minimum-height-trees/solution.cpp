// Created by Yaniru at 2023/12/03 16:50
// leetgo: dev
// https://leetcode.cn/problems/minimum-height-trees/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// @lc code=begin

class Solution {
  class Util {

  public:
    Util(unordered_map<int, unordered_set<int>> *adjt_ptr) : adjt(adjt_ptr) {}

    /*
     * return path from srcnode to farthest node
     */
    vector<int> findFarthestNode(int srcnode) {
      dfsToFarthest(srcnode, 1);
      return res;
    }

  private:
    unordered_map<int, unordered_set<int>> *adjt = nullptr;
    vector<int> res{};
    unordered_set<int> visited{};
    vector<int> stk{};
    int deepest = 0;

    void dfsToFarthest(int srcnode, int depth) {
      visited.insert(srcnode);
      stk.push_back(srcnode);
      auto n = stk.back();
      auto adj = (*adjt)[n];
      if (adj.size() == 1 && depth > deepest) {
        deepest = depth;
        res = stk;
      }
      for (auto nnodeid : adj) {
        if (visited.find(nnodeid) == visited.end())
          dfsToFarthest(nnodeid, depth + 1);
      }

      stk.pop_back();
      return;
    }
  };

public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return {0};
    if (n == 2)
      return {0, 1};

    /* build adjcent table */
    for (auto edge : edges) {
      adjt[edge[0]].insert(edge[1]);
      adjt[edge[1]].insert(edge[0]);
    }
    auto path1 = Util(&adjt).findFarthestNode(0);
    auto path2 = Util(&adjt).findFarthestNode(path1.back());
    auto len = path2.size();
    if (len % 2 == 0) {
      return {path2[len / 2], path2[len / 2 - 1]};
    } else {
      return {path2[len / 2]};
    }
  }

private:
  unordered_map<int, unordered_set<int>> adjt;
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);
  vector<vector<int>> edges;
  LeetCodeIO::scan(cin, edges);

  Solution *obj = new Solution();
  auto res = obj->findMinHeightTrees(n, edges);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
