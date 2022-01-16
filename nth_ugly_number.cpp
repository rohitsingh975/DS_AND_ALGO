#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
	long long gcd(long long a, long long b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	long long lcm(long long a, long long b)
	{
		return (a * b) / gcd(a, b);
	}

	long long count(long long m, long a, long b, long c)
	{
		long long t = lcm(b, c);
		return m / a + m / b + m / c - (m / lcm(a, b)) - (m / t) - (m / lcm(a, c)) + (m / lcm(a, t));
	}
public:
	int nthUglyNumber(int n, int a, int b, int c) {

		long long l = min(c, min(a, b));
		long long h = l * n;
		long long mid;

		while (l < h) {
			mid = (l + h) / 2;
			long long factor = count(mid, a, b, c);
			if (factor < n)
				l = mid + 1;
			else
				h = mid;
		}
		return l;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T--) {
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		Solution ob;
		auto ans = ob.nthUglyNumber(N, A, B, C);
		cout << ans << "\n";
	}

	return 0;

}