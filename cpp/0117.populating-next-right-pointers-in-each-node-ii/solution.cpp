// Created by Yaniru at 2023/11/03 09:31
// leetgo: dev
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=begin

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return nullptr;

    auto nodes = queue<Node *>{};
    nodes.push(root);
    nodes.push(nullptr);
    while (nodes.empty() == false) {
      auto node = nodes.front();
      nodes.pop();
      if (node == nullptr) {
        if (nodes.empty() == false)
          nodes.push(nullptr);
      } else {
        node->next = nodes.front();
        if (node->left != nullptr)
          nodes.push(node->left);
        if (node->right != nullptr)
          nodes.push(node->right);
      }
    }

    return root;
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  Node *root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->connect(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
