// Created by Yaniru at 2023/11/09 10:00
// leetgo: dev
// https://leetcode.cn/problems/escape-the-spreading-fire/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

// @lc code=begin

class Solution {
  using Grid = vector<vector<int>>;

public:
  int maximumMinutes(Grid &grid) {
    fireSpreadBFS(grid);

    // play clever
    // clang-format off
    if (grid[0][1] == 0 or grid[1][0] == 0) {
      auto visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
      auto visitcell = [&](int x, int y, int min) -> bool {
        if (not isvalid(grid, x, y)) { return false; }
        if (grid[x][y] > 0)          { return false; }
        if (visited[x][y] == 1)      { return false; }
        visited[x][y] = 1;
        return true;
      };
      auto q = queue<node>{};
      q.push({0, 0, 0});
      visited[0][0] = 1;
      while (q.empty() == false) {
        auto n = q.front();
        if (n.x == grid.size() - 1 and n.y == grid[0].size() - 1) return 1E9;
        q.pop();
        if (visitcell(n.x - 1, n.y, n.min + 1)) { q.push({n.x - 1, n.y, n.min + 1}); }
        if (visitcell(n.x + 1, n.y, n.min + 1)) { q.push({n.x + 1, n.y, n.min + 1}); }
        if (visitcell(n.x, n.y - 1, n.min + 1)) { q.push({n.x, n.y - 1, n.min + 1}); }
        if (visitcell(n.x, n.y + 1, n.min + 1)) { q.push({n.x, n.y + 1, n.min + 1}); }
      }
      return -1;
    }

    // binary search
    int l = 0;
    int r = 2E4;
    int ans = -1;
    while (l <= r) {
      int m = l  + (r - l) / 2;
      auto visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
      auto visitcell = [&](int x, int y, int min) -> bool {
        if ((x == grid.size() - 1 and y == grid[0].size() - 1) 
            and (0 - grid[x][y] == m + min)) { return true; }
        if (not isvalid(grid, x, y))                     { return false; }
        if (visited[x][y] == 1)                          { return false; }
        if (grid[x][y] > 0)                              { return false; }
        if (grid[x][y] < 0 && 0 - grid[x][y] <= m + min) { return false; }
        visited[x][y] = 1;
        return true;
      };
      auto q = queue<node>{};
      q.push({0, 0, 0});
      visited[0][0] = 1;
      while (q.empty() == false) {
        auto n = q.front();
        if (n.x == grid.size() - 1 and n.y == grid[0].size() - 1) break;
        q.pop();
        if (visitcell(n.x - 1, n.y, n.min + 1)) { q.push({n.x - 1, n.y, n.min + 1}); }
        if (visitcell(n.x + 1, n.y, n.min + 1)) { q.push({n.x + 1, n.y, n.min + 1}); }
        if (visitcell(n.x, n.y - 1, n.min + 1)) { q.push({n.x, n.y - 1, n.min + 1}); }
        if (visitcell(n.x, n.y + 1, n.min + 1)) { q.push({n.x, n.y + 1, n.min + 1}); }
      }
      if (q.empty())  r = m - 1;
      else { ans = m; l = m + 1; }
    }

    return ans;
    // clang-format on
  }

private:
  struct node {
    int x;
    int y;
    int min;
  };

  /*
   * check whether [x, y] is valid index of grid
   */
  bool isvalid(Grid &grid, int x, int y) {
    return not(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size());
  }

  /*
   * for each fire-reachable cell:
   * if grid[x][y] is minus, it means fire will reach this cell in at least
   * -grid[x][y] minutes
   */
  void fireSpreadBFS(Grid &grid) {
    auto q = queue<node>{};
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 1)
          q.push({i, j, 0});
    auto setcell = [&](int x, int y, int min) -> bool {
      // clang-format off
      if (not isvalid(grid, x, y)) { return false; }
      if (grid[x][y] == 0) { grid[x][y] = -min; return true; }
      else { return false; }
      // clang-format on
    };
    while (q.empty() == false) {
      auto n = q.front();
      q.pop();
      // clang-format off
      if (setcell(n.x, n.y - 1, n.min + 1)) { q.push({n.x, n.y - 1, n.min + 1}); }
      if (setcell(n.x, n.y + 1, n.min + 1)) { q.push({n.x, n.y + 1, n.min + 1}); }
      if (setcell(n.x - 1, n.y, n.min + 1)) { q.push({n.x - 1, n.y, n.min + 1}); }
      if (setcell(n.x + 1, n.y, n.min + 1)) { q.push({n.x + 1, n.y, n.min + 1}); }
      // clang-format on
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> grid;
  LeetCodeIO::scan(cin, grid);

  Solution *obj = new Solution();
  auto res = obj->maximumMinutes(grid);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
