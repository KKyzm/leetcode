// Created by Yaniru at 2023/11/02 14:50
// leetgo: dev
// https://leetcode.cn/problems/combination-sum/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  vector<vector<int>> ans{};

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    foo(0, candidates, target, {});
    return ans;
  }

  void foo(int n, vector<int> &v, int t, vector<int> a) {
    for (int i = n; i < v.size(); i++) {
      if (v[i] <= t) {
        auto aa = vector<int>{a};
        aa.push_back(v[i]);
        if (t - v[i] == 0) {
          ans.push_back(aa);
          break;
        } else {
          foo(i, v, t - v[i], aa);
        }
      } else {
        break;
      }
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> candidates;
  LeetCodeIO::scan(cin, candidates);
  int target;
  LeetCodeIO::scan(cin, target);

  Solution *obj = new Solution();
  auto res = obj->combinationSum(candidates, target);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
