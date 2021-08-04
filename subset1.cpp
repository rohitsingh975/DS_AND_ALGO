#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;

	void PASS(vector<int>& nums, int i, vector<int>& tmp) {

		if (i == nums.size()) {
			ans.push_back(tmp);
			return;
		}

		PASS(nums, i + 1, tmp);
		tmp.push_back(nums[i]);
		PASS(nums, i + 1, tmp);
		tmp.pop_back();
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty()) return {{}};
		int i = 0;
		vector<int> temp;
		PASS(nums, i, temp);
		return ans;
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