#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif
	int n, target, l = 0, h;

	cin >> n;

	h = n - 1;

	int arr[n] = {0};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> target;

	while (l < h) {

		if (arr[l] + arr[h] == target) {
			break;
		} else if (arr[l] + arr[h] < target) {
			l  = l + 1;
		} else {
			h = h - 1;
		}
	}
	cout << (l + 1) << " " << (h + 1);
	return 0;
}