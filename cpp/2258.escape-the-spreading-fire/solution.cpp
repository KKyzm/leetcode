// Created by Yaniru at 2023/11/09 10:00
// leetgo: dev
// https://leetcode.cn/problems/escape-the-spreading-fire/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <functional>
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
    if (grid[0][1] == 0 or grid[1][0] == 0) {
      auto visitcell = [&](int x, int y, int min) -> bool {
        if (not isvalid(grid, x, y)) {
          return false;
        }
        if (grid[x][y] != 0) {
          return false;
        }
        return true;
      };
      if (BFS(grid, visitcell)) {
        return 1E9;
      } else {
        return -1;
      }
    }

    // binary search
    int l = 0;
    int r = 2E4;
    int ans = -1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      auto visitcell = [&](int x, int y, int min) -> bool {
        if ((x == grid.size() - 1 and y == grid[0].size() - 1) and
            (0 - grid[x][y] == m + min)) {
          return true;
        }
        if (not isvalid(grid, x, y)) {
          return false;
        }
        if (grid[x][y] > 0) {
          return false;
        }
        if (grid[x][y] < 0 && 0 - grid[x][y] <= m + min) {
          return false;
        }
        return true;
      };
      if (BFS(grid, visitcell)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return ans;
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
    auto q = list<node>{};
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 1)
          q.push_front({i, j, 0});
    auto setcell = [&](int x, int y, int min) -> bool {
      if (not isvalid(grid, x, y)) {
        return false;
      }
      if (grid[x][y] == 0) {
        grid[x][y] = -min;
        return true;
      } else {
        return false;
      }
    };
    BFS(grid, setcell, false, q);
  }

  bool BFS(Grid &grid, function<bool(int, int, int)> visitcell, bool fe = true,
           list<node> q = list<node>{{0, 0, 0}}) {
    auto visited =
        vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
    for (auto n : q) {
      visited[n.x][n.y] = 1;
    }
    while (q.empty() == false) {
      auto n = q.back();
      if (fe and n.x == grid.size() - 1 and n.y == grid[0].size() - 1)
        return true;
      q.pop_back();
      if (visitcell(n.x - 1, n.y, n.min + 1) and (visited[n.x - 1][n.y] == 0)) {
        visited[n.x - 1][n.y] = 1;
        q.push_front({n.x - 1, n.y, n.min + 1});
      }
      if (visitcell(n.x + 1, n.y, n.min + 1) and (visited[n.x + 1][n.y] == 0)) {
        visited[n.x + 1][n.y] = 1;
        q.push_front({n.x + 1, n.y, n.min + 1});
      }
      if (visitcell(n.x, n.y - 1, n.min + 1) and (visited[n.x][n.y - 1] == 0)) {
        visited[n.x][n.y - 1] = 1;
        q.push_front({n.x, n.y - 1, n.min + 1});
      }
      if (visitcell(n.x, n.y + 1, n.min + 1) and (visited[n.x][n.y + 1] == 0)) {
        visited[n.x][n.y + 1] = 1;
        q.push_front({n.x, n.y + 1, n.min + 1});
      }
    }
    return false;
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
