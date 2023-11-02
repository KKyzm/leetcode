// Created by Yaniru at 2023/11/01 15:47
// leetgo: dev
// https://leetcode.cn/problems/course-schedule/

#include "LC_IO.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <memory>
#include <queue>
#include <stack>
#include <system_error>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  template <typename T> class Stk {
  public:
    void push(T t) { stk_.push_back(t); }
    void pop() { stk_.pop_back(); }
    bool has(T t) { return find(stk_.begin(), stk_.end(), t) != stk_.end(); }

  private:
    vector<T> stk_{};
  };

  Stk<int> stk_{};
  map<int, vector<int>> m{};
  unordered_set<int> visited{};
  bool is_visited(int i) { return visited.find(i) != visited.end(); };

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    for (int i = 0; i < numCourses; i++) {
      m[i] = vector<int>{};
    }
    for (auto p : prerequisites) {
      m[p[0]].push_back(p[1]);
    }

    // depth first search
    for (int i = 0; i < numCourses; i++) {
      if (is_visited(i))
        continue;
      if (dfs(i) == false)
        return false;
    }

    return true;
  }

  bool dfs(int t) {
    stk_.push(t);
    visited.insert(t);
    for (auto neighbor : m[t]) {
      if (is_visited(neighbor)) {
        if (stk_.has(neighbor))
          return false;
        continue;
      } else {
        if (dfs(neighbor) == false)
          return false;
      }
    }
    stk_.pop();
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int numCourses;
  LeetCodeIO::scan(cin, numCourses);
  vector<vector<int>> prerequisites;
  LeetCodeIO::scan(cin, prerequisites);

  Solution *obj = new Solution();
  auto res = obj->canFinish(numCourses, prerequisites);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
