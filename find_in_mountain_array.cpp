#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums, int target) {
		int N = nums.size();
		//cout << N;
		if (N == 1)
			return 0;

		int l = 0, h = N - 1, peak = 0;

		while (l < h)
		{
			int m = (l + h) / 2;
			if (nums[m] < nums[m + 1])
				l = m + 1;
			else
				h = m;
		}
		peak = l;
		//Binary search in left half
		l = 0, h = peak;
		while (l <= h)
		{
			int m = (l + h) / 2;

			if (nums[m] == target)
				return m;
			else if (nums[m] < target)
				l = m + 1;
			else
				h = m - 1;
		}

		//Binary search in second half
		l = peak + 1, h = N - 1;
		while (l <= h)
		{
			int m = (l + h) / 2;

			if (nums[m] == target)
				return m;
			else if (nums[m] > target)
				l = m + 1;
			else
				h = m - 1;
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


	int target = 1;

	vector<int> vec = {0,1,5,3,0};

	Solution ob;
	int ans = ob.findPeakElement(vec, target);
	cout << ans;
	return 0;
}
