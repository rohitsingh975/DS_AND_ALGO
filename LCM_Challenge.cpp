#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	long long n, lcm, num1, num2, num3;
	cin >> n;

	if (n == 2)
		lcm = 2;
	else if (n == 1)
		lcm = 1;
	else
	{
		if (n % 2 == 0)
		{
			if (n % 3 == 0) {

				num1 = n - 1;
				num2 = n - 2;
				num3 = n - 3;

			} else {
				num1 = n;
				num2 = n - 1;
				num3 = n - 3;

			}

		}
		else
		{
			num1 = n;
			num2 = n - 1;
			num3 = n - 2;
		}

		lcm = num1 * num2 * num3;
	}

	cout << lcm << endl;

	//return lcm;
}
