// Created by Yaniru at 2023/10/01 13:46
// leetgo: dev
// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr or head->next == nullptr)
      return head;
    auto tail = head->next->next;
    head->next->next = head;
    head = head->next;
    head->next->next = swapPairs(tail);
    return head;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode *head;
  LeetCodeIO::scan(cin, head);

  Solution *obj = new Solution();
  auto res = obj->swapPairs(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
