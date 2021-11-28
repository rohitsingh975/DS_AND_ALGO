#include <iostream>
using namespace std;

int indexOfFirstOne(int arr[], int l, int h)
{
	while (l <= h) {
		int m = (l + h) / 2;
		if (arr[m] == 1 && (m == 0 || arr[m - 1] == 0))
			return m;
		else if (arr[m] == 1)
			h = m - 1;
		else
			l  = m + 1;
	}
	return -1;
}

int main() {
	// your code goes here
#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n] = {0};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << indexOfFirstOne(arr, 0, n - 1);

	return 0;
}