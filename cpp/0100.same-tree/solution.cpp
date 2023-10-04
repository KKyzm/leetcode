// Created by Yaniru at 2023/10/03 23:40
// leetgo: dev
// https://leetcode.cn/problems/same-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr and q != nullptr)
      return false;
    if (q == nullptr and p != nullptr)
      return false;
    if (q == nullptr and p == nullptr)
      return true;

    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode *p;
  LeetCodeIO::scan(cin, p);
  TreeNode *q;
  LeetCodeIO::scan(cin, q);

  Solution *obj = new Solution();
  auto res = obj->isSameTree(p, q);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
