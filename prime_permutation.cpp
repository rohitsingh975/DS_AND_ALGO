#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

class Solution {
public:

	long long factorial(int n)
	{
		// single line to find factorial
		return (n == 1 || n == 0) ? 1 : (n * factorial(n - 1)) % M;
	}

	int numPrimeArrangements(int n) {
		vector<bool> isprime(n + 1, true);
		int count = 0, no_of_prime, no_of_composite;
		// Sieve
		isprime[0] = isprime[1] = false;

		for (int i = 2; i * i <= n; i++) {
			if (isprime[i]) {
				for (int j = i; i * j <= n; j++) {
					isprime[i * j] = false;
				}
			}
		}

		for (int i = 2; i <= n; i++) {
			if (isprime[i])
				count++;
		}

		return (factorial(count) * factorial(n - count)) % M;
	}
};

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	Solution ob;
	cout << ob.numPrimeArrangements(n) << "\n";

	return 0;
}
