#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)

{
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

int main() {
#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	long long t, n;

	cin >> t;

	while (t--)
	{

		cin >> n;

		long long arr[n];

		for (long long i = 0; i < n; i++)
			cin >> arr[i];


		long long answer = arr[0];

		for (long long i = 1; i < n; i++)
			answer = gcd(answer, arr[i]);


		if (answer == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}


	return 0;
}