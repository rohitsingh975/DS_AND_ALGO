// C++ program to find valid paranthesisations of length n
// The majority of code is taken from method 3 of
// https://www.geeksforgeeks.org/program-nth-catalan-number/
#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
                                unsigned int k)
{
	unsigned long int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

// A Binomial coefficient based function to
// find nth catalan number in O(n) time
unsigned long int catalan(unsigned int n)
{
	// Calculate value of 2nCn
	unsigned long int c = binomialCoeff(2 * n, n);

	// return 2nCn/(n+1)
	return c / (n + 1);
}

// Function to find possible ways to put balanced
// parenthesis in an expression of length n
unsigned long int findWays(unsigned n)
{
	// If n is odd, not possible to
	// create any valid parentheses
	if (n & 1)
		return 0;

	// Otherwise return n/2'th Catalan Numer
	return catalan(n / 2);
}

// Driver program to test above functions
int main()
{
#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif
	int n = 6;
	cout << "Total possible expressions of length "
	     << n << " is " << findWays(6);
	return 0;
}
