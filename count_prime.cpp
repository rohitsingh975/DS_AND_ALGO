#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {

		if (n == 0)
			return 0;
		else if (n == 1)
			return 0;
		else
		{
			int primes[n + 1];
			for (int i = 1; i <= n; i++)
				primes[i] = 1;

			//primes[1] = 0;
			for (int i = 2; i * i < n; i++)
			{
				if (primes[i] == 1)
				{
					for (int j = i; i * j < n; j++)
						primes[i * j] = 0;
				}
			}

			int count = 0;
			for (int i = 2; i < n; i++)
				if (primes[i] == 1)
					count++;

			return count;

		}

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

	cout << ob.countPrimes(n) << endl;

	return 0;
}



// for (int i = 0; i < n; i++)
// 	cout << frequency[i] << " ";