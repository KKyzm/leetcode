// Created by Yaniru at 2023/09/30 20:55
// leetgo: dev
// https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int max_prefix = 0;
    int dp[m][n];

    for (int i = m - 1; i >= 0; i--) {
      dp[i][n - 1] = (nums1[i] == nums2[n - 1]) ? 1 : 0;
      max_prefix = max(max_prefix, dp[i][n - 1]);
    }
    for (int j = n - 1; j >= 0; j--) {
      dp[m - 1][j] = (nums1[m - 1] == nums2[j]) ? 1 : 0;
      max_prefix = max(max_prefix, dp[m - 1][j]);
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
          max_prefix = max(max_prefix, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return max_prefix;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums1;
  LeetCodeIO::scan(cin, nums1);
  vector<int> nums2;
  LeetCodeIO::scan(cin, nums2);

  Solution *obj = new Solution();
  auto res = obj->findLength(nums1, nums2);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
