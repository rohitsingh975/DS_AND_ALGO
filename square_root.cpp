#include <bits/stdc++.h>
using namespace std;

int squareRoot(long long N)
{
	int l = 0;
	long long h = N;

	while (l <= h) {
		long long m = (l + h) / 2;

		if (m * m > N)
			h = m - 1;
		else {
			if ((m + 1) * (m + 1) > N)
				return m;
			else
				l = m + 1;
		}
	}

	return 0;
}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {

		long long N;
		cin >> N;
		cout << squareRoot(N) << "\n";

	}

	return 0;
}
