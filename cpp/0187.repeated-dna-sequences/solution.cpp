// Created by Yaniru at 2023/09/30 20:17
// leetgo: dev
// https://leetcode.cn/problems/repeated-dna-sequences/

#include "LC_IO.h"
#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() <= 10)
      return {};

    vector<string> ans;
    unordered_map<string, int> m;
    for (int i = 0; i <= s.length() - 10; i++) {
      string seq = s.substr(i, 10);
      if (m.find(seq) == m.end()) {
        m[seq] = 0;
      } else if (m[seq] == 0) {
        ans.push_back(seq);
        m[seq] = 1;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->findRepeatedDnaSequences(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
