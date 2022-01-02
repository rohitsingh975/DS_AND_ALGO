//https://codeforces.com/problemset/problem/855/B
//Maxmimize the expression p.a[i]+ q.a[j]+r.a[k]
// I/P: 5 1 2 -3
//-1 -2 -3 -4 -5
// O/P: 12

#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int n, p, q, r, i;

	cin >> n >> p >> q >> r;

	long long ans = LLONG_MIN, arr[n], pmax[n], smax[n];

	for (i = 0; i < n; i++)
		cin >> arr[i];

	// calculating prefix max with value p and populating pmax array
	//-1 -1 -1 -1 -1
	pmax[0] = p * arr[0];

	for (i = 1; i < n; i++)
		pmax[i] = max(pmax[i - 1], p * arr[i]);

	// calculating suffix max with value r and populating smax array
	//15 15 15 15 15
	smax[n - 1] = r * arr[n - 1];

	for (i = n - 2; i >= 0; i--)
		smax[i] = max(smax[i + 1], r * arr[i]);

	// calculating max value
	for (i = 0; i < n; i++)
		ans = max(ans, pmax[i] + q * arr[i] + smax[i]);

	cout << ans << endl;

	return 0;
}
