#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int count4Divisibiles(int arr[], int n) {

		int k = 4;
		int cnt[k];

		for (int i = 0; i < k; i++)
			cnt[i] = 0;

		for (int i = 0; i < n; i++)
			cnt[arr[i] % k]++;

		int ans = 0;

		ans += (cnt[0] * (cnt[0] - 1)) / 2;

		for (int i = 1; i <= (k / 2) - 1; i++)
			ans += cnt[i] * cnt[k - i];

		if (k % 2 == 0)
			ans += (cnt[k / 2] * (cnt[k / 2] - 1)) / 2;
		else
			ans += cnt[k / 2] * cnt[k / 2 + 1];

		return ans;

	}
};

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		Solution ob;
		cout << ob.count4Divisibiles(arr, n) << endl;
	}
	return 0;
}
