// Created by Yaniru at 2023/09/29 13:16
// leetgo: dev
// https://leetcode.cn/problems/can-place-flowers/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.insert(flowerbed.end(), 0);
    flowerbed.insert(flowerbed.end(), 1);
    int count_zero = 0;
    for (int i : flowerbed) {
      if (n <= 0)
        break;
      if (i == 0) {
        count_zero++;
      } else if (i == 1) {
        n -= (count_zero - 1) / 2;
        count_zero = 0;
      }
    }
    return n <= 0;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> flowerbed;
  LeetCodeIO::scan(cin, flowerbed);
  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->canPlaceFlowers(flowerbed, n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
