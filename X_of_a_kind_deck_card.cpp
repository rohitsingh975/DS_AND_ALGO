#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {

		int n = deck.size();

		unordered_map<int, int> frequency;

		for (int i = 0; i < n; i++)
			frequency[deck[i]]++;

		int gcd = 0;

		for (auto it : frequency) {

			int freq = it.second;

			if (gcd == 0)
				gcd = freq;
			else
				gcd = __gcd(gcd, freq);
		}

		if (gcd == 1)
			return false;
		else
			return true;
	}
};


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> deck;
	int input;

	while (cin >> input)
		deck.push_back(input);

	Solution ob;

	cout << ob.hasGroupsSizeX(deck) << endl;

	return 0;
}



// for (int i = 0; i < n; i++)
// 	cout << frequency[i] << " ";