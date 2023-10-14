// Created by Yaniru at 2023/10/14 17:07
// leetgo: dev
// https://leetcode.cn/problems/avoid-flood-in-the-city/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    vector<int> res(rains.size(), 1);
    set<int> free_days;
    map<int, int> m;
    for (int i = 0; i < rains.size(); i++) {
      if (rains[i] > 0) {
        res[i] = -1;
        if (m.count(rains[i]) == 0) {
          m.insert(make_pair(rains[i], i));
        } else {
          auto it = free_days.lower_bound(m[rains[i]]);
          if (it == free_days.end()) {
            return {};
          }
          res[*it] = rains[i];
          free_days.erase(it);
          m[rains[i]] = i;
        }
      } else {
        free_days.insert(i);
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> rains;
  LeetCodeIO::scan(cin, rains);

  Solution *obj = new Solution();
  auto res = obj->avoidFlood(rains);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
