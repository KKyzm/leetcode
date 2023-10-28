// Created by Yaniru at 2023/10/28 10:37
// leetgo: dev
// https://leetcode.cn/problems/take-gifts-from-the-richest-pile/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  void max_heapify_up(vector<int> &v) {
    for (int i = v.size() / 2; i >= 0; i--) {
      max_heapify_down(v, i);
    }
  }

  void max_heapify_down(vector<int> &v, int i) {
    if (is_leaf(v, i))
      return;
    int j = left(i);
    if (is_valid(v, right(i)) and v[left(i)] < v[right(i)]) {
      j = right(i);
    }
    if (v[i] < v[j]) {
      swap(v[i], v[j]);
      max_heapify_down(v, j);
    }
  }

  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }
  bool is_leaf(vector<int> &v, int i) { return left(i) >= v.size(); }
  bool is_valid(vector<int> &v, int i) { return i >= 0 and i < v.size(); }

public:
  long long pickGifts(vector<int> &gifts, int k) {
    max_heapify_up(gifts);
    while (k > 0) {
      gifts[0] = sqrt(gifts[0]);
      max_heapify_down(gifts, 0);
      k--;
    }

    return accumulate(gifts.begin(), gifts.end(), 0ll);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> gifts;
  LeetCodeIO::scan(cin, gifts);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->pickGifts(gifts, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
