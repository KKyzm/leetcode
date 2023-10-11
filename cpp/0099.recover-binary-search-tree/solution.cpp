// Created by Yaniru at 2023/10/11 14:51
// leetgo: dev
// https://leetcode.cn/problems/recover-binary-search-tree/

#include "LC_IO.h"
#include <any>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> res;
    getTraversalOrder(root, res);
    TreeNode *x = nullptr;
    TreeNode *y = nullptr;
    for (int i = 0; i < res.size() - 1; i++) {
      if (res[i]->val > res[i + 1]->val) {
        x = res[i];
        break;
      }
    }
    for (int i = res.size() - 1; i >= 1; i--) {
      if (res[i]->val < res[i - 1]->val) {
        y = res[i];
        break;
      }
    }

    swap(x->val, y->val);
  }

  void getTraversalOrder(TreeNode *root, vector<TreeNode *> &res) {
    if (root == nullptr)
      return;
    getTraversalOrder(root->left, res);
    res.push_back(root);
    getTraversalOrder(root->right, res);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->recoverTree(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
