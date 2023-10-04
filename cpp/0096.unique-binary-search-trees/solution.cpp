// Created by Yaniru at 2023/10/04 10:15
// leetgo: dev
// https://leetcode.cn/problems/unique-binary-search-trees/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <map>
#include <utility>
using namespace std;

// @lc code=begin

class Solution {
public:
  map<int, int> m;
  Solution() {
    m.insert(make_pair(0, 1));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 5));
  }

  int numTrees(int n) {
    if (m.find(n) != m.end()) {
      return m[n];
    }

    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
      int left_child = i;
      int right_child = n - i - 1;
      sum += numTrees(left_child) * numTrees(right_child);
    }

    sum *= 2;

    if (n % 2 == 1) {
      sum += pow(numTrees(n / 2), 2);
    }

    m[n] = sum;

    return sum;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->numTrees(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
