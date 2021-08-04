#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int sieve[N + 1];

void computeSieve() {

	sieve[0] = sieve[1] = 1;

	for (long long i = 2; i * i <= N; i++) {

		if (sieve[i] == 0) {

			for (long long j = i; j * i <= N; j++) {
				sieve[i * j] = 1;

			}
		}
	}
}

bool checkSquare(long long n) {

	long long x = sqrt(n);
	return x * x == n;
}

int checkSquareRootPrime(long long n) {

	long long x = sqrt(n);
	return !sieve[x];
}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	computeSieve();

	int m;

	cin >> m;

	long long arr[m + 1];

	for (int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++) {

		if (checkSquare(arr[i]) && checkSquareRootPrime(arr[i])) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
