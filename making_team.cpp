#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n, m, t;

	long long int a = 0;

	cin >> n >> m >> t;

	long long int f[31][31];

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				f[i][j] = 1;

			else
				f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
		}

	}

	for (int i = 4; i <= n; i++)
	{

		int g = t - i;

		if (g < 1 || g > m)
			continue;

		a += (f[n][i] * f[m][g]);

	}

	cout << a;

	return 0;
}
