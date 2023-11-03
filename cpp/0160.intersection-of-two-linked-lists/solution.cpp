// Created by Yaniru at 2023/11/03 10:06
// leetgo: dev
// https://leetcode.cn/problems/intersection-of-two-linked-lists/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ans = nullptr;
    auto A = vector<ListNode *>{};
    auto B = vector<ListNode *>{};
    while (headA != nullptr) {
      A.push_back(headA);
      headA = headA->next;
    }
    while (headB != nullptr) {
      B.push_back(headB);
      headB = headB->next;
    }
    auto itA = A.rbegin();
    auto itB = B.rbegin();
    while (itA != A.rend() and itB != B.rend()) {
      if (*itA == *itB) {
        ans = *itA;
        itA++;
        itB++;
      } else {
        break;
      }
    }
    return ans;
  }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int intersectVal;
  LeetCodeIO::scan(cin, intersectVal);
  ListNode *listA;
  LeetCodeIO::scan(cin, listA);
  ListNode *listB;
  LeetCodeIO::scan(cin, listB);
  int skipA;
  LeetCodeIO::scan(cin, skipA);
  int skipB;
  LeetCodeIO::scan(cin, skipB);

  Solution *obj = new Solution();
  auto res = obj->getIntersectionNode(intersectVal, listA, listB, skipA, skipB);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
