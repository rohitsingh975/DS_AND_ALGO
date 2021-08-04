#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int i, j, k;
	int n, m, t;

	long long x, y;

	scanf("%d%d", &n, &m);
	scanf("%d%d", &k, &t);

	set<long long> s;
	vector<long long> vec;

	while (k--) {
		scanf("%lld%lld", &x, &y);
		x--;
		vec.push_back(x * m + y);
	}

	sort(vec.begin(), vec.end());

	long long pos;

	while (t--) {
		scanf("%lld%lld", &x, &y);
		x--;
		pos = x * m + y;
		k = 0, j = 0;
		for (int e : vec) {
			if (e < pos)
				k++;
			else if (e == pos)
				j = 1;
			else
				break;
		}

		pos -= k;
		pos = pos % 3;

		if (j)
			printf("Waste\n");
		else if (pos == 1)
			printf("Carrots\n");
		else if (pos == 2)
			printf("Kiwis\n");
		else
			printf("Grapes\n");
	}
	return 0;
}
