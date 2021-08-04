#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {

		int n = nums.size();

		if (n < 2)
			return 0;

		int max_num = INT_MIN, min_num = INT_MAX;


		//Find max num and min num
		for (int i = 0; i < n; i++) {

			max_num = max(max_num, nums[i]);
			min_num = min(min_num, nums[i]);
		}

		if (min_num == max_num)
			return 0;

		int gap = (max_num - min_num) / (n - 1);

		if ((max_num - min_num) % (n - 1) != 0)
			gap++;

		vector<int> minArr(n, INT_MAX);
		vector<int> maxArr(n, INT_MIN);

		for (int i = 0; i < n; i++) {

			int bkt = (nums[i] - min_num) / gap;
			minArr[bkt] = min(minArr[bkt], nums[i]);
			maxArr[bkt] = max(maxArr[bkt], nums[i]);
		}

		int ans = INT_MIN;
		int prev = INT_MIN;

		for (int i = 0; i < n; i++) {

			if (minArr[i] == INT_MAX)
				continue;

			if (prev == INT_MIN) {

				prev = maxArr[i];

			} else {

				ans = max(ans, minArr[i] - prev);
				prev = maxArr[i];

			}
		}

		return ans;
	}
};


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> nums;
	int input;

	while (cin >> input)
		nums.push_back(input);

	Solution ob;

	cout << ob.maximumGap(nums) << endl;

	return 0;
}




/*for (int i = 0; i < n; i++)
		cout << maxArr[i] << " ";*/