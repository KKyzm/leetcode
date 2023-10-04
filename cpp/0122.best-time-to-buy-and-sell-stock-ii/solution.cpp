// Created by Yaniru at 2023/10/02 10:06
// leetgo: dev
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    vector<int> profits(prices.size(), 0);
    for (int i = 0; i < profits.size() - 1; i++) {
      profits[i] = prices[i + 1] - prices[i];
    }
    for (int profit : profits) {
      if (profit > 0)
        max_profit += profit;
    }
    return max_profit;
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
