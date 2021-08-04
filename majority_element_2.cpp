#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n = nums.size();

		vector<int> v;

		if (n == 0)
		{
			v.push_back(0);
			return v;
		}

		int x = INT_MIN, y = INT_MIN, countx = 0, county = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (x == nums[i])
				countx++;
			else if (y == nums[i])
				county++;
			else if (countx == 0)
			{
				x = nums[i];
				countx = 1;
			}
			else if (county == 0)
			{
				y = nums[i];
				county = 1;
			}
			else
			{
				countx--;
				county--;
			}
		}

		int count = nums.size() / 3;

		countx = 0, county = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (x == nums[i])
				countx++;
			else if (y == nums[i])
				county++;
		}

		if (countx > count)
			v.push_back(x);

		if (county > count)
			v.push_back(y);

		return v;
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

	vector<int> ans = ob.majorityElement(nums);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}




/*for (int i = 0; i < n; i++)
		cout << maxArr[i] << " ";*/