// Created by Yaniru at 2023/10/30 10:28
// leetgo: dev
// https://leetcode.cn/problems/merge-k-sorted-lists/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;

    priority_queue<int> pq{};
    ListNode *node = new ListNode;
    for (auto l : lists) {
      while (l != nullptr) {
        pq.push(l->val);
        l = l->next;
      }
    }
    while (pq.empty() == false) {
      node->next = new ListNode(pq.top(), node->next);
      pq.pop();
    }
    return node->next;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<ListNode *> lists;
  LeetCodeIO::scan(cin, lists);

  Solution *obj = new Solution();
  auto res = obj->mergeKLists(lists);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
