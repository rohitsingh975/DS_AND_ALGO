/*
*https://leetcode.com/problems/subsets/
*(using bit masking)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty()) return {{}};
		int size = nums.size();
		int subsetNum = (1 << size);

		vector<vector<int>> allsubsets;

		for (int subsetMask = 0; subsetMask < subsetNum; subsetMask++) {
			vector<int> subset;
			for (int i = 0; i < size; i++) {
				if ((subsetMask & (1 << i)) != 0) {
					subset.push_back(nums[i]);
				}
			}
			allsubsets.push_back(subset);
		}
		return allsubsets;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	vector<int> nums = {1, 2, 3};
	vector<vector<int>> ans;

	Solution ob;
	ans = ob.subsets(nums);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}