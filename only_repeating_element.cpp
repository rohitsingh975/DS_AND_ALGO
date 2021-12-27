#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	vector<int> vec;
	int input;

	while (cin >> input)
		vec.push_back(input);

	int l = 0, h = N - 1;

	while (l <= h)
	{
		int m = (l + h) / 2;

		if (vec[m] == m)
			h = m - 1;
		else
		{
			if (vec[m + 1] == vec[m])
			{
				cout << vec[m];
				break;
			}
			else
				l = m + 1;
		}
	}
	return 0;
}