/*
*https://codeforces.com/contest/727/problem/A
*Recursion Homework 1
*/

#include <bits/stdc++.h>
using namespace std;

bool transform(vector<int>& path, int a, int b)
{
	if (a == b) {
		path.push_back(b);
		return true;
	} else if (a > b) {
		return false;
	}


	if (transform(path, (a * 10) + 1, b)) {
		path.push_back(a);
		return true;
	}

	if (transform(path, 2 * a, b)) {
		path.push_back(a);
		return true;
	}

	return false;

}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from Input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to Output.txt
	freopen("Output.txt", "w", stdout);
#endif

	int a, b;
	vector<int> path;
	cin >> a >> b;

	if (transform(path, a, b)) {

		reverse(path.begin(), path.end());

		cout << "YES" << "\n";
		cout << path.size() << "\n";
		for (auto i : path)
			cout << i << " ";

	} else {
		cout << "NO";
	}

	return 0;
}