// Created by Yaniru at 2023/11/10 09:22
// leetgo: dev
// https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    auto ans = vector<int>(spells.size(), 0);
    auto foo = vector<double>(potions.size(), 0);
    for (int i = 0; i < potions.size(); i++) {
      foo[i] = static_cast<double>(success) / potions[i];
    }
    sort(foo.begin(), foo.end());
    for (int i = 0; i < spells.size(); i++) {
      ans[i] = minIdx(foo, spells[i]);
    }

    return ans;
  }

private:
  int minIdx(vector<double> &vec, int num) {
    if (vec.front() > num)
      return 0;
    if (vec.back() <= num)
      return vec.size();

    int l = 0;
    int r = vec.size() - 1;
    int ans = 0;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (vec[m] <= num) {
        l = m + 1;
      } else {
        ans = m;
        r = m - 1;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> spells;
  LeetCodeIO::scan(cin, spells);
  vector<int> potions;
  LeetCodeIO::scan(cin, potions);
  int64_t success;
  LeetCodeIO::scan(cin, success);

  Solution *obj = new Solution();
  auto res = obj->successfulPairs(spells, potions, success);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
