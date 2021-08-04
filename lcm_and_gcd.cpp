#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<long long> lcmAndGcd(long long A, long long B) {

		vector<long long> ans;

		long long maximum = max(A, B);
		long long minimum = min(A, B);

		while (maximum % minimum != 0) {

			int temp = maximum;
			maximum = minimum;
			minimum = temp % minimum;
		}

		long long gcd = minimum;
		long long lcm = (A * B) / gcd;

		ans.push_back(lcm);
		ans.push_back(gcd);

		return ans;

	}

};

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	long long A, B;

	cin >> A >> B;

	Solution ob;

	vector<long long> ans = ob.lcmAndGcd(A, B);

	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}