#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool checkInclusion(string s1, string s2) {

		int n = s1.size();
		int m = s2.size();

		if (m < n)
			return false;

		//Declaring the size of each character array
		int freq1[30]; //Maintaining frequency for s1
		int freq2[30]; //Maintaining frequency of current window of s2

		for (int i = 0; i < 26; i++)
			freq1[i] = freq2[i] = 0;

		//Updating the frequency of array of s1
		for (int i = 0; i < n; i++)
			freq1[s1[i] - 'a']++;

		//Updating frequency array for first window of s2
		for (int i = 0; i < n; i++)
			freq2[s2[i] - 'a']++;

		//Compare now and check if first window itself is permutation
		if (checkAnagram(freq1, freq2)) {
			return true;
		}

		int window_end = n;

		while (window_end < m) {

			//added and removed to get the new frequencies
			freq2[s2[window_end] - 'a']++;
			freq2[s2[window_end - n] - 'a']--;

			//check if current window is anagram or not
			if (checkAnagram(freq1, freq2))
				return true;

			//move the window forward
			window_end++;

		}

		return false;

	}

	bool checkAnagram(int freq1[], int freq2[])	{
		for (int i = 0; i < 26; i++) {
			if (freq1[i] != freq2[i])
				return false;
		}
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

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	Solution ob;

	cout << ob.checkInclusion(s1, s2) << endl;

	return 0;
}
