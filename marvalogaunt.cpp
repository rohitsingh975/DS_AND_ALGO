#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n, p, q, r, i;

	cin >> n >> p >> q >> r;

	long long ans = LLONG_MIN, arr[n], pmax[n], smax[n];

	for (i = 0; i < n; i++)
		cin >> arr[i];

	// calculating prefix max and populating the array
	pmax[0] = p * arr[0];

	for (i = 1; i < n; i++)
		pmax[i] = max(pmax[i - 1], p * arr[i]);


	// calculating suffix max and populating the array
	smax[n - 1] = r * arr[n - 1];

	for (i = n - 2; i >= 0; i--)
		smax[i] = max(smax[i + 1], r * arr[i]);

	// calculating max value
	for (i = 0; i < n; i++)
		ans = max(ans, pmax[i] + q * arr[i] + smax[i]);

	cout << ans << endl;

	return 0;
}
