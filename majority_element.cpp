#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {

		int n = nums.size();

		int majority = nums[0], count = 1;

		for (int i = 1; i < n; i++)
		{
			if (majority == nums[i])
				count++;
			else
			{
				count--;
				if (count == 0)
				{
					majority = nums[i];
					count++;
				}
			}
		}

		return majority;
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

	cout << ob.majorityElement(nums) << endl;

	return 0;
}




/*for (int i = 0; i < n; i++)
		cout << maxArr[i] << " ";*/