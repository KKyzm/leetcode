// Created by Yaniru at 2023/10/11 14:38
// leetgo: dev
// https://leetcode.cn/problems/validate-binary-search-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// @lc code=begin

class Solution {
public:
  double neg_inf = -numeric_limits<double>::infinity();
  double pos_inf = numeric_limits<double>::infinity();
  bool isValidBST(TreeNode *root) {
    return isSubtreeVaildBST(root, neg_inf, pos_inf);
  }

  bool isSubtreeVaildBST(TreeNode *root, double low, double high) {
    if (root == nullptr)
      return true;
    else if (not inside(root->val, low, high)) {
      return false;
    } else {
      bool left = isSubtreeVaildBST(root->left, low, root->val);
      bool right = isSubtreeVaildBST(root->right, root->val, high);
      return left and right;
    }
  }

  inline bool inside(double val, double low, double high) {
    return val > low and val < high;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->isValidBST(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
