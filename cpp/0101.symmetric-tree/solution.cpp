// Created by Yaniru at 2023/10/04 00:28
// leetgo: dev
// https://leetcode.cn/problems/symmetric-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isSymmetric(TreeNode *root) { return isSame(root->left, root->right); }

private:
  bool isSame(TreeNode *p, TreeNode *q) {
    if (p == nullptr and q != nullptr)
      return false;
    if (q == nullptr and p != nullptr)
      return false;
    if (q == nullptr and p == nullptr)
      return true;
    if (p->val != q->val) {
      return false;
    }
    return isSame(p->left, q->right) and isSame(p->right, q->left);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->isSymmetric(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
