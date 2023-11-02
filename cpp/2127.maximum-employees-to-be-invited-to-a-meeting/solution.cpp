// Created by Yaniru at 2023/11/01 20:51
// leetgo: dev
// https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <unordered_set>
#include <utility>
#include <variant>
using namespace std;

// @lc code=begin

class Solution {
  unordered_set<int> visited{};
  bool is_visited(int i) { return visited.find(i) != visited.end(); }
  unordered_map<int, vector<int>> m{};

  vector<int> find_cycle_from(int i, const vector<int> &favorite) {
    auto v = vector<int>{};
    v.push_back(i);
    while (true) {
      int fav = favorite[i];
      if (is_visited(fav)) {
        auto iter = find(v.begin(), v.end(), fav);
        if (iter == v.end()) {
          break;
        } else {
          return {iter, v.end()};
        }
      }
      visited.insert(fav);
      v.push_back(fav);
      i = fav;
    }

    return {};
  }

  int find_pair_max_len(pair<int, int> p, const vector<int> &favorite) {
    int max_len = 0;
    int first = p.first;
    int second = p.second;
    // node_no, layer_no
    auto trace = stack<pair<int, int>>{};
    trace.push(make_pair(first, 1));
    while (not trace.empty()) {
      auto top = trace.top();
      trace.pop();
      auto cur = top.first;
      auto len = top.second;
      max_len = max(max_len, len);
      auto fans = m[cur];
      for (auto fan : fans) {
        if (fan == second)
          continue;
        trace.push(make_pair(fan, len + 1));
      }
    }
    return max_len;
  }

public:
  int maximumInvitations(vector<int> &favorite) {
    int max_num = 0;

    for (int j = 0; j < favorite.size(); j++) {
      m[favorite[j]].push_back(j);
    }
    auto bidirs = vector<int>{};
    for (int i = 0; i < favorite.size(); i++) {
      if (is_visited(i)) {
        continue;
      }
      visited.insert(i);
      auto cycle = find_cycle_from(i, favorite);
      int num = cycle.size();
      if (num == 2) {
        bidirs.push_back(
            find_pair_max_len(make_pair(cycle[0], cycle[1]), favorite) +
            find_pair_max_len(make_pair(cycle[1], cycle[0]), favorite));
      }
      max_num = max(max_num, num);
    }

    max_num = max(max_num, accumulate(bidirs.begin(), bidirs.end(), 0));

    return max_num;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> favorite;
  LeetCodeIO::scan(cin, favorite);

  Solution *obj = new Solution();
  auto res = obj->maximumInvitations(favorite);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
