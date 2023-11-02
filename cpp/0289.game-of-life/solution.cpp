// Created by Yaniru at 2023/11/02 15:07
// leetgo: dev
// https://leetcode.cn/problems/game-of-life/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  int getnum1(vector<vector<int>> &vv, int i, int j) {
    int ans = 0;
    return foo(vv, i - 1, j - 1) + foo(vv, i - 1, j) + foo(vv, i - 1, j + 1) +
           foo(vv, i, j - 1) + foo(vv, i, j + 1) + foo(vv, i + 1, j - 1) +
           foo(vv, i + 1, j) + foo(vv, i + 1, j + 1);
  }

  int foo(vector<vector<int>> &vv, int i, int j) {
    if (i < 0 or i >= vv.size() or j < 0 or j >= vv[0].size())
      return 0;
    else
      return vv[i][j] % 10;
  }

public:
  void gameOfLife(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        int num1 = getnum1(board, i, j);
        if ((board[i][j] == 0 and num1 == 3) or
            (board[i][j] == 1 and num1 == 2 or num1 == 3)) {
          board[i][j] += 10;
        }
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        board[i][j] /= 10;
      }
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> board;
  LeetCodeIO::scan(cin, board);

  Solution *obj = new Solution();
  auto res = obj->gameOfLife(board);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
