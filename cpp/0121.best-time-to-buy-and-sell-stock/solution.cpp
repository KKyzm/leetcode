// Created by Yaniru at 2023/10/01 09:41
// leetgo: dev
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1)
      return 0;
    int maxprofit = 0;
    int minprice = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < minprice) {
        minprice = prices[i];
      } else {
        maxprofit = max(maxprofit, prices[i] - minprice);
      }
    }
    return maxprofit;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> prices;
  LeetCodeIO::scan(cin, prices);

  Solution *obj = new Solution();
  auto res = obj->maxProfit(prices);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
