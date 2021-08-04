#include <bits/stdc++.h>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int i, int j)
{
	while (i < j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;

		i++;
		j--;
	}
}

void rotate(vector<int>& nums, int k) {

	int n;
	n = nums.size();

	k = k % n;

	//part 1
	reverse(nums, 0, n - k - 1);

	//part 2
	reverse(nums, n - k, n - 1);

	//all
	reverse(nums, 0 , n - 1);

	for (int j = 0; j < n; j++)
		cout << nums[j] << " ";
}


int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> nums;
	int input, k;

	cin >> k;

	while (cin >> input)
		nums.push_back(input);

	rotate(nums, k);
}