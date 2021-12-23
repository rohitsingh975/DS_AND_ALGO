#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int N = nums.size();

		if (N == 1)
			return 0;

		int l = 0, h = N - 1;

		while (l <= h)
		{
			int m = (l + h) / 2;

			if (m == 0 && nums[m] > nums[m + 1])
			{
				return m;
			}
			else if (m == N - 1 && nums[m] > nums[m - 1])
			{
				return m;
			}
			else if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1])
			{
				return m;
			}
			else
			{
				if (nums[m + 1] > nums[m])
					l = m + 1;
				else
					h = m - 1;
			}
		}

		return -1;
	}
};

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	vector<int> vec;
	int input;

	while (cin >> input)
		vec.push_back(input);

	Solution ob;
	int ans = ob.findPeakElement(vec);
	cout << ans;
	return 0;
}
