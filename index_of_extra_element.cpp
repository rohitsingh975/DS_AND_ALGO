#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	int arr1[N];

	for (int i = 0; i < N; i++)
		cin >> arr1[i];

	int arr2[N - 1];

	for (int i = 0; i < N - 1; i++)
		cin >> arr2[i];

	int l = 0, h = N - 1;

	while (l <= h) {
		int m = (l + h) / 2;

		if (arr1[m] != arr2[m]) {

			if (arr1[m] != arr2[m - 1]) {
				cout << m;
				break;
			} else {
				h = m - 1;
			}

		} else if (arr1[m] == arr2[m]) {
			l = m + 1;
		}
	}

	return 0;
}