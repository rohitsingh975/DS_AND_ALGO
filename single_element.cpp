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

	if (l == h) {
		cout << vec[0];
		return 0;
	}

	while (l <= h)
	{
		int m = (l + h) / 2;

		if (m == 0)
		{
			if (vec[m + 1] != vec[m]) {
				cout << vec[m];
				break;
			} else
				l = m + 1;
		}
		else if (m == N - 1)
		{
			if (vec[m - 1] != vec[m]) {
				cout << vec[m];
				break;
			}
			else
				h = m - 1;
		}
		else if (vec[m] != vec[m + 1] && vec[m] != vec[m - 1])
		{
			cout << vec[m];
			break;
		}
		else
		{
			int fo;

			if (vec[m] == vec[m + 1])
			{
				fo = m;
			}
			else
			{
				fo = m - 1;
			}

			if (fo % 2 == 0)
				l = m + 1;
			else
				h = m - 1;
		}
	}
	return 0;
}