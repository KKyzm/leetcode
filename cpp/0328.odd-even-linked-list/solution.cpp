// Created by Yaniru at 2023/11/02 15:26
// leetgo: dev
// https://leetcode.cn/problems/odd-even-linked-list/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    auto odds = vector<int>{};
    auto evens = vector<int>{};
    int c = 1;
    while (head != nullptr) {
      auto val = head->val;
      if (c % 2 == 1) {
        odds.push_back(val);
      } else {
        evens.push_back(val);
      }
      c++;
      head = head->next;
    }

    for (auto it = evens.rbegin(); it != evens.rend(); it++) {
      head = new ListNode(*it, head);
    }
    for (auto it = odds.rbegin(); it != odds.rend(); it++) {
      head = new ListNode(*it, head);
    }
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
  auto res = obj->oddEvenList(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
