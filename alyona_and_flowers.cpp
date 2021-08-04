#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n, m, l, r, sum_of_subarray, total_happiness = 0;

	cin >> n >> m;

	int a[n + 1];

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	// calculating prefix sum and populating the array
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];

	//Calculating max happiness of alyona
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;

		sum_of_subarray = a[r] - a[l - 1];

		sum_of_subarray += total_happiness;

		total_happiness = max(total_happiness, sum_of_subarray);

	}

	if (total_happiness < 0)
		total_happiness = 0;

	cout << total_happiness << endl;

	return 0;
}
