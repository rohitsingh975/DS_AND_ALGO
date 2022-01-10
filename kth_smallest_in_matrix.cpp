#include <bits/stdc++.h>
using namespace std;

const int N = 3;
int arr[N][N];
int countElement(int arr[][N], int x, int N) {

	int cnt = 0;
	for (int i = 0; i < N; i++) {

		int lo = 0, hi = N - 1;

		while (lo <= hi) {

			int mid = (lo + hi) / 2;

			cnt += lo;
			if (arr[i][mid] <= x) {
				lo = mid + 1;
			} else {
				if (mid == 0 || arr[i][mid - 1] < x) {
					cnt += mid;
					lo = 0;
					break;
				} else {
					hi = mid - 1;
				}
			}

		}
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int k;
	cin >> k;

	//Minimum element from first column
	int minElement = arr[0][0];
	for (int i = 1; i < N; i++)
		minElement = min(minElement, arr[i][0]);


	//Maximum element from last column
	int maxElement = arr[0][N - 1];

	for (int i = 1; i < N; i++)
		maxElement = max(maxElement, arr[i][N - 1]);

	//cout << maxElement;

	int l = minElement, h = maxElement;

	while (l <= h) {
		int midElement = (l + h) / 2;
		//cout << midElement << "\n";
		int cnt = countElement(arr, midElement, N);
		//cout << cnt << "\n";
		if (cnt < k)
			l = midElement + 1;
		else
		{
			int cnt1 = countElement(arr, midElement - 1, N);
			if (cnt1 < k) {
				cout << midElement;
				break;
			} else {
				h = midElement - 1;
			}
		}
	}

	return 0;
}
