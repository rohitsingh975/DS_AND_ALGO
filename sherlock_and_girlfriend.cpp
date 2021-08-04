#include <bits/stdc++.h>
using namespace std;

#define mx 1000005
bool primes[mx];
long long p[mx];

void sieve()
{
	primes[0] = primes[1] = 1;
	for (long long i = 4; i <= mx; i += 2)
	{
		primes[i] = 1;
	}

	for (long long i = 3; i * i <= mx; i += 2)
	{
		if (!primes[i] && i <= sqrt(mx))
		{
			for (long long j = i * i; j <= mx; j += 2 * i)
				primes[j] = 1;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	long long m, n, p, l, i;

	while (cin >> n)
	{
		sieve();

		if (n < 3)
			cout << "1" << endl;
		else
			cout << "2" << endl;

		for (i = 2; i <= n + 1; i++)
		{
			if (primes[i])
				cout << "2 ";
			else
				cout << "1 ";
		}
		cout << endl;
	}

	return 0;
}
