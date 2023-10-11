// Created by Yaniru at 2023/10/11 15:43
// leetgo: dev
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int root = inorder[0];
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> preorder;
  LeetCodeIO::scan(cin, preorder);
  vector<int> inorder;
  LeetCodeIO::scan(cin, inorder);

  Solution *obj = new Solution();
  auto res = obj->buildTree(preorder, inorder);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
