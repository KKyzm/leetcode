// Created by Yaniru at 2023/10/14 17:54
// leetgo: dev
// https://leetcode.cn/problems/median-of-two-sorted-arrays/

#include "LC_IO.h"
#include <bits/stdc++.h>
using namespace std;

// @lc code=begin

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    double res = 0;
    set<int> tar;
    int len = nums1.size() + nums2.size();
    tar.insert(len / 2 + 1);
    if (len % 2 == 0) {
      tar.insert(len / 2);
    }
    int n = 0;

    int i = 0;
    int j = 0;
    while (i < nums1.size() or j < nums2.size()) {
      n++;
      int num;
      // num equal to the n_th number of nums1 and nums2
      if (j >= nums2.size() or (i < nums1.size() and nums1[i] < nums2[j])) {
        num = nums1[i];
        i++;
      } else {
        num = nums2[j];
        j++;
      }
      // if num is the middle number of nums1 and nums2
      if (tar.count(n) != 0) {
        res += num;
      }
    }

    if (len % 2 == 0) {
      return res / 2.0;
    } else {
      return res;
    }
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
  auto res = obj->findMedianSortedArrays(nums1, nums2);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
