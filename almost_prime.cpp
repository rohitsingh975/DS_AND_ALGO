#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n, count = 0;
	cin >> n;

	int spf[3001] = {0};

	for (int i = 2; i <= n; ++i)
	{
		if (spf[i] == 0)
		{
			for (int j = i + i; j <= n; j += i)
			{
				spf[j] += 1;
			}
		}

		if (spf[i] == 2)
		{
			count += 1;
		}
	}

	cout << count;

	return 0;
}
