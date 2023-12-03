// Created by Yaniru at 2023/11/10 10:59
// leetgo: dev
// https://leetcode.cn/problems/groups-of-special-equivalent-strings/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int numSpecialEquivGroups(vector<string> &words) {
    auto m = map<string, int>{};
    for (auto word : words) {
      auto even = string(26, '0');
      auto odds = string(26, '0');
      for (int i = 0; i < word.length(); i += 2) {
        even[word[i] - 'a']++;
      }
      for (int i = 1; i < word.length(); i += 2) {
        odds[word[i] - 'a']++;
      }
      auto key = even + "-" + odds;
      m[key]++;
    }
    return m.size();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> words;
  LeetCodeIO::scan(cin, words);

  Solution *obj = new Solution();
  auto res = obj->numSpecialEquivGroups(words);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
