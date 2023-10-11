// Created by Yaniru at 2023/10/11 14:28
// leetgo: dev
// https://leetcode.cn/problems/unique-binary-search-trees-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0)
      return {nullptr};
    else
      return generateSubtree(1, n);
  }

  vector<TreeNode *> generateSubtree(int l, int r) {
    if (l > r)
      return {nullptr};
    vector<TreeNode *> res;
    for (int i = l; i <= r; i++) {
      vector<TreeNode *> left_child = generateSubtree(l, i - 1);
      vector<TreeNode *> right_child = generateSubtree(i + 1, r);
      for (auto left : left_child) {
        for (auto right : right_child) {
          TreeNode *root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->generateTrees(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
