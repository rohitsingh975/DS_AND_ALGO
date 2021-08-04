#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {

	int n, max_numberof_chunks = 0, current_max = INT_MIN;
	n = arr.size();

	if (n <= 0)
	{
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		current_max = max(current_max, arr[i]);
		if (current_max == i)
			max_numberof_chunks++;
	}

	return max_numberof_chunks;
}

int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> arr;
	int input, max_numberof_chunks = INT_MIN;

	while (cin >> input)
		arr.push_back(input);

	max_numberof_chunks = maxChunksToSorted(arr);
	cout << max_numberof_chunks;
}