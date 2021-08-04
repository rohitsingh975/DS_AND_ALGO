#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long subarraySum(long long a[], long long n)
	{
		// Your code goes here
		long long m = 1e9 + 7;
		long long ans = 0;


		for (long long i = 0; i < n; i++)
		{
			long long contrib = ((((i + 1) % m * (n - i) % m) % m) * a[i] % m) % m;
			ans = (ans % m + contrib % m) % m;
		}
		return ans;
	}
};


int main()
{
#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	long long n;
	cin >> n;
	long long a[n + 5];
	for (long long i = 0; i < n; i++)
		cin >> a[i];
	Solution ob;
	cout << ob.subarraySum(a, n) << endl;
	return 0;
}