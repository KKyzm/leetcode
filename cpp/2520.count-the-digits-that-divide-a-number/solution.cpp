// Created by Yaniru at 2023/10/26 09:55
// leetgo: dev
// https://leetcode.cn/problems/count-the-digits-that-divide-a-number/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int countDigits(int num) {
    int ans = 0;
    vector<int> s;
    int num2 = num;
    while (num2 > 0) {
      s.push_back(num2 % 10);
      num2 /= 10;
    }
    for (auto x : s) {
      if (num % x == 0)
        ans++;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int num;
  LeetCodeIO::scan(cin, num);

  Solution *obj = new Solution();
  auto res = obj->countDigits(num);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
