#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;

	while (t--) {
		long long n, a, b, k, x, y, z;
		cin >> n >> a >> b >> k;
		x = n / a;
		y = n / b;

		long long maximum = max(a, b);
		long long minimum = min(a, b);

		if (minimum != 0) {

			while (maximum % minimum != 0) {

				long long temp = maximum;
				maximum = minimum;
				minimum = temp % minimum;
			}

		} else {
			minimum = maximum;
		}


		long long gcd = minimum;
		long long lcm = (a * b) / gcd;

		z = n / lcm;

		cout << (x + y - 2 * z >= k ? "Win\n" : "Lose\n");
	}

	return 0;
}


/*template<class T>
T lcm(T a, T b) {
	return (a * b) / __gcd(a, b);
}*/