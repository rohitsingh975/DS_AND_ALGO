#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> primeFactors(int N) {

		int c = 0;
		vector<int> sol;
		for (int i = 2; i <= sqrt(N); i++) {
			c = 0;
			while (N > 1 && N % i == 0) {
				N /= i;
				c++;
			}
			if (c > 0) {
				sol.emplace_back(i);
				sol.emplace_back(c);
			}
		}
		if (N >= 2) {
			sol.emplace_back(N);
			sol.emplace_back(1);
		}
		return sol;
	}
};


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int t;

	cin >> t;

	while (t--) {

		int N;

		cin >> N;

		Solution ob;
		vector<int> ans = ob.primeFactors(N);
		for (int u : ans)
			cout << u << " ";
		cout << endl;
	}

	return 0;
}



// for (int i = 0; i < n; i++)
// 	cout << frequency[i] << " ";