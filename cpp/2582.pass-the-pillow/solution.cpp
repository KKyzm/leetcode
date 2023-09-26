// Created by Yaniru at 2023/09/26 17:31
// leetgo: dev
// https://leetcode.cn/problems/pass-the-pillow/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int passThePillow(int n, int time) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	int time;
	LeetCodeIO::scan(cin, time);

	Solution *obj = new Solution();
	auto res = obj->passThePillow(n, time);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
