#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
int divsum[N + 5];

void computeDivSum()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 2 * i; j <= N; j += i) {
			divsum[j] += i;
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

	int t;
	scanf("%d", &t);
	computeDivSum();

	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", divsum[n]);
	}

	return 0;
}
