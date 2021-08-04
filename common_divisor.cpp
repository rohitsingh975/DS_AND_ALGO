#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int countDivisor[N + 5];

void computeDivisorCount() {
	countDivisor[1] = 1;

	for (int i = 2; i <= N; i++)
		countDivisor[i] = 2;

	for (int i = 2; i <= N; i++) {
		for (int j = 2 * i; j <= N; j += i) {
			countDivisor[j]++;
		}
	}
}

int findDivisorCount(int x) {
	return countDivisor[x];
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
	computeDivisorCount();

	while (t--) {

		int a, b;
		scanf("%d %d", &a, &b);

		//Find gcd of a and b
		int gcd = __gcd(a, b);

		//Find number of divisor of gcd
		printf("%d\n", findDivisorCount(gcd));

	}

	return 0;
}
