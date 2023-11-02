// Created by Yaniru at 2023/10/31 16:14
// leetgo: dev
// https://leetcode.cn/problems/clone-graph/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cassert>
#include <memory>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// @lc code=begin

class Solution {
  unordered_map<int, Node *> hmap;

public:
  inline Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return node;
    Node *root = nullptr;
    if (hmap.count(node->val)) {
      root = hmap[node->val];
      return root;
    } else {
      root = new Node(node->val);
      hmap[node->val] = root;
    }
    for (auto _node : node->neighbors) {
      Node *neighbor = cloneGraph(_node);
      root->neighbors.push_back(neighbor);
    }
    return root;
  }
};
// @lc code=end

// Warning: this is a manual question, the generated test code may be
// incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> edges;
  LeetCodeIO::scan(cin, edges);

  Solution *obj = new Solution();
  auto res = obj->cloneGraph(edges);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
