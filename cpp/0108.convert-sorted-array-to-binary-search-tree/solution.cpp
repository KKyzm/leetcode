// Created by Yaniru at 2023/10/19 09:15
// leetgo: dev
// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size());
  }

  TreeNode *buildTree(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, left, mid);
    root->right = buildTree(nums, mid + 1, right);
    return root;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->sortedArrayToBST(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
