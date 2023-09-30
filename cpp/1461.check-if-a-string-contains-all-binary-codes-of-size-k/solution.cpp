// Created by Yaniru at 2023/09/30 21:26
// leetgo: dev
// https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <math.h>
#include <set>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (s.size() <= k)
      return false;

    int num = static_cast<int>(pow(2, k));
    unordered_set<string> se;
    for (int i = 0; i <= s.length() - k; i++) {
      string subs = s.substr(i, k);
      se.insert(subs);
    }

    return se.size() == num;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->hasAllCodes(s, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
