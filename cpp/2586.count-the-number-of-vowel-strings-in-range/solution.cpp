// Created by Yaniru at 2023/11/07 14:50
// leetgo: dev
// https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
  bool isVowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
  }

public:
  int vowelStrings(vector<string> &words, int left, int right) {
    int ans = 0;
    while (left <= right) {
      auto word = words[left];
      if (isVowel(word[0]) and isVowel(word[word.length() - 1])) {
        ans++;
      }
      left++;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> words;
  LeetCodeIO::scan(cin, words);
  int left;
  LeetCodeIO::scan(cin, left);
  int right;
  LeetCodeIO::scan(cin, right);

  Solution *obj = new Solution();
  auto res = obj->vowelStrings(words, left, right);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
