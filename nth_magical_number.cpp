#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
	int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
public:
	int nthMagicalNumber(int n, int a, int b) {

		long long l = min(a, b);
		long long h = l * n;
		long long lcm = (a * b) / gcd(a, b);
		long long mid, factor;

		while (l < h) {
			mid = (l + h) / 2;
			factor = mid / a + mid / b - mid / lcm;
			if (factor < n)
				l = mid + 1;
			else
				h = mid;
		}
		int mod = 1e9 + 7;
		return l % mod;
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
		int N, A, B;
		cin >> N >> A >> B;
		Solution ob;
		auto ans = ob.nthMagicalNumber(N, A, B);
		cout << ans << "\n";
	}

	return 0;

}