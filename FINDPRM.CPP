#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

int sieve[N + 5];
int prefixPrime[N + 5];

void computeSieve() {
	sieve[0] = sieve[1] = 1;

	for (int i = 2; i * i <= N; i++) {
		if (sieve[i] == 0) {
			for (int j = i; j * i <= N; j++) {
				sieve[i * j] = 1;
			}
		}
	}
}

void computePrefixPrime() {
	for (int i = 2; i <= N; i++) {
		if (sieve[i] == 0) {
			prefixPrime[i] = prefixPrime[i - 1] + 1;
		} else {
			prefixPrime[i] = prefixPrime[i - 1];
		}
	}
}

int countPrimes(int l, int r) {
	return prefixPrime[r] - prefixPrime[l - 1];
}


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	computeSieve();
	computePrefixPrime();

	while (t--) {

		int n;
		scanf("%d", &n);

		printf("%d\n", countPrimes(n / 2 + 1, n));
	}

	return 0;
}
