#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> arr;
	int input;

	while (cin >> input)
		arr.push_back(input);

	int n = arr.size();

	for (int i = 0; i < n; i++) {

		int old_value = arr[i] % n;
		arr[old_value] = n * i + arr[old_value];
	}

	for (int i = 0; i < n; i++)
		arr[i] /= n;

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";


	return 0;
}
