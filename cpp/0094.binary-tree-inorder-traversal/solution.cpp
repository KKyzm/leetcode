// Created by Yaniru at 2023/10/03 23:35
// leetgo: dev
// https://leetcode.cn/problems/binary-tree-inorder-traversal/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    traversalWithRecursion(root, result);
    return result;
  }

private:
  void traversalWithRecursion(TreeNode *root, vector<int> &result) {
    if (root == nullptr)
      return;
    traversalWithRecursion(root->left, result);
    result.push_back(root->val);
    traversalWithRecursion(root->right, result);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->inorderTraversal(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
