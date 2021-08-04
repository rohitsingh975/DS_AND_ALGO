#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxVowels(string s, int k) {

		int n = s.length(), cnt = 0, ans;

		for (int i = 0; i < k; i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				cnt++;
			}
		}

		ans = cnt;

		for (int j = k; j < n; j++)
		{
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
				cnt++;

			if (s[j - k] == 'a' || s[j - k] == 'e' || s[j - k] == 'i' || s[j - k] == 'o' || s[j - k] == 'u')
				cnt--;

			ans = max(ans, cnt);
		}


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

	string s;
	getline(cin, s);

	int k;
	cin >> k;

	Solution ob;

	cout << ob.maxVowels(s, k) << endl;

	return 0;
}
