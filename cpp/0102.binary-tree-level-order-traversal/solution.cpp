// Created by Yaniru at 2023/10/11 15:21
// leetgo: dev
// https://leetcode.cn/problems/binary-tree-level-order-traversal/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<vector<int>> res;
    vector<int> v;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    int curr_level = 0;
    while (!q.empty()) {
      auto item = q.front();
      q.pop();
      if (item.second != curr_level) {
        res.push_back(v);
        v.clear();
        curr_level = item.second;
      }
      if (item.first == nullptr)
        continue;
      v.push_back(item.first->val);
      q.push(make_pair(item.first->left, curr_level + 1));
      q.push(make_pair(item.first->right, curr_level + 1));
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->levelOrder(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
