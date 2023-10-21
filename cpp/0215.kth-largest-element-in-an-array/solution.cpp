// Created by Yaniru at 2023/10/20 11:30
// leetgo: dev
// https://leetcode.cn/problems/kth-largest-element-in-an-array/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }
  int parent(int i) { return (i - 1) / 2; }
  bool is_leaf(vector<int> &nums, int i) { return not is_valid(nums, left(i)); }
  bool is_valid(vector<int> &nums, int i) { return i >= 0 && i < nums.size(); }

  /* void heapify_up(vector<int> &nums, int i) { */
  /*   if (i == 0) */
  /*     return; */
  /*   if (nums[i] > nums[parent(i)]) { */
  /*     swap(nums[i], nums[parent(i)]); */
  /*     heapify_up(nums, parent(i)); */
  /*   } */
  /* } */

  void heapify_down(vector<int> &nums, int i) {
    if (is_leaf(nums, i))
      return;
    int j;
    if (not is_valid(nums, right(i)) or nums[left(i)] >= nums[right(i)]) {
      j = left(i);
    } else {
      j = right(i);
    }
    if (nums[i] < nums[j]) {
      swap(nums[i], nums[j]);
      heapify_down(nums, j);
    }
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    int res = 0;
    for (int i = nums.size() / 2; i >= 0; i--) {
      heapify_down(nums, i);
    }

    while (k > 0) {
      res = nums[0];
      swap(nums[0], nums[nums.size() - 1]);
      nums.pop_back();
      heapify_down(nums, 0);
      k--;
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->findKthLargest(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
