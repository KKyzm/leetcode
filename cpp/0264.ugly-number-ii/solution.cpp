// Created by Yaniru at 2023/10/21 12:19
// leetgo: dev
// https://leetcode.cn/problems/ugly-number-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int nthUglyNumber(int n) {
    priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> pq;
    unordered_set<uint64_t> s;
    pq.push(1);
    s.insert(1);
    uint64_t res;
    while (n > 0) {
      n--;
      res = pq.top();
      uint64_t cur = pq.top();
      pq.pop();
      if (s.find(cur * 2) == s.end()) {
        pq.push(cur * 2);
        s.insert(cur * 2);
      }
      if (s.find(cur * 3) == s.end()) {
        pq.push(cur * 3);
        s.insert(cur * 3);
      }
      if (s.find(cur * 5) == s.end()) {
        pq.push(cur * 5);
        s.insert(cur * 5);
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->nthUglyNumber(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
