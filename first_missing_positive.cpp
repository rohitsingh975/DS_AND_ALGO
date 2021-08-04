#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

	int firstMissingPositive(vector<int>& nums) {

		int n = nums.size();

		// Loop to traverse the whole array
		for (int i = 0; i < n; i++) {

			// Loop to check boundary
			// condition and for swapping
			while (nums[i] >= 1 && nums[i] <= n
			        && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}

		// Checking any element which
		// is not equal to i+1
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}

		// Nothing is present return last index
		return n + 1;
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

	cout << ob.firstMissingPositive(nums) << endl;

	return 0;
}