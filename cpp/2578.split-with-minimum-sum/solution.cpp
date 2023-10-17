// Created by Yaniru at 2023/10/17 10:48
// leetgo: dev
// https://leetcode.cn/problems/split-with-minimum-sum/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
private:
  map<char, int> m{
      {'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0},
      {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0},
  };

public:
  int splitNum(int num) {
    int res = 0;
    int base = 0;
    int count = 0;
    string s = to_string(num);
    for (char c : s) {
      if (m.count(c) == 0) {
        return -1;
      }
      m[c] += 1;
    }
    for (char k = '9'; k >= '0'; k--) {
      while (m[k] > 0) {
        if (count > 0 and count % 2 == 0) {
          base++;
        }
        res += (k - '0') * pow(10, base);
        count++;
        m[k]--;
      }
    }
    return res;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int num;
  LeetCodeIO::scan(cin, num);

  Solution *obj = new Solution();
  auto res = obj->splitNum(num);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
