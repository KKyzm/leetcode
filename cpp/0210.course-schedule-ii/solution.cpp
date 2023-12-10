// Created by Yaniru at 2023/12/03 15:44
// leetgo: dev
// https://leetcode.cn/problems/course-schedule-ii/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  int findZeroDegree(unordered_map<int, size_t> &degrees) {
    for (auto [nodeid, degree] : degrees) {
      if (degree == 0) {
        degrees.erase(nodeid);
        return nodeid;
      }
    }
    return -1;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    auto ans = vector<int>();
    auto adjt = unordered_map<int, unordered_set<int>>();
    auto degrees = unordered_map<int, size_t>();
    /* init degree for each node */
    for (int i = 0; i < numCourses; i++) {
      degrees[i] = 0;
    }
    /* build adjacency table */
    for (auto prer : prerequisites) {
      // prer[1] --> prer[0]
      degrees[prer[0]]++;
      adjt[prer[1]].insert(prer[0]);
    }
    /* topology sort */
    while (!degrees.empty()) {
      int nodeid = findZeroDegree(degrees);
      if (nodeid < 0)
        return {};
      ans.push_back(nodeid);
      auto adjs = adjt[nodeid];
      for (auto adj : adjs) {
        degrees[adj]--;
      }
    }
    return ans;
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
  auto res = obj->findOrder(numCourses, prerequisites);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
