#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {

		int res = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (nums[i] != INT_MAX) {

				int start = nums[i], count = 0;

				while (nums[start] != INT_MAX) {

					int temp = start;
					start = nums[start];
					count++;
					nums[temp] = INT_MAX;
				}

				res = max(res, count);
			}
		}

		return res;
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

	cout << ob.arrayNesting(nums) << endl;

	return 0;
}




/*for (int i = 0; i < n; i++)
		cout << maxArr[i] << " ";*/


/*int count = 0, temp = INT_MAX, ans = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != INT_MAX) {

			while (nums[i] != INT_MAX)
			{
				int temp = nums[i];

				if (temp < 0)
					break;

				nums[i] = INT_MAX;
				i = temp;
				count++;
			}
			ans = max(ans, count);
		}
	}

	return ans;*/