#include <bits/stdc++.h>
using namespace std;

int countElement(int arr[], int x, int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] <= x)
			cnt++;
	}
	return cnt;
}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	int arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int k;
	cin >> k;

	int minElement = arr[0];
	for (int i = 1; i < N; i++)
		minElement = min(minElement, arr[i]);

	int maxElement = arr[0];
	for (int i = 1; i < N; i++)
		maxElement = max(maxElement, arr[i]);

	//cout << minElement;

	int l = minElement, h = maxElement;

	while (l <= h) {
		int m = (l + h) / 2;
		int cnt = countElement(arr, m, N);

		if (cnt < k)
			l = m + 1;
		else
		{
			int cnt1 = countElement(arr, m - 1, N);
			if (cnt1 < k) {
				cout << m;
				break;
			} else {
				h = m - 1;
			}
		}
	}


	return 0;
}
