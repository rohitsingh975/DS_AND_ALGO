#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> digitMap;

class Solution {
public:
	vector<string> ans;
	void getAllCombination(string tmp, string& digits, int i, vector<vector<char>>& digitMap)
	{
		if (digits[i] == '\0') {
			ans.push_back(tmp);
			return;
		}

		for (int j = 0; j < digitMap[digits[i] - '2'].size(); j++)
		{
			getAllCombination(tmp + digitMap[digits[i] - '2'][j], digits, i + 1, digitMap);
		}


	}

	vector<string> letterCombinations(string digits) {

		if (digits.empty())
			return {};

		string tmp;

		digitMap.push_back({'a', 'b', 'c'});
		digitMap.push_back({'d', 'e', 'f'});
		digitMap.push_back({'g', 'h', 'i'});
		digitMap.push_back({'j', 'k', 'l'});
		digitMap.push_back({'m', 'n', 'o'});
		digitMap.push_back({'p', 'q', 'r', 's'});
		digitMap.push_back({'t', 'u', 'v'});
		digitMap.push_back({'w', 'x', 'y', 'z'});

		getAllCombination(tmp, digits, 0, digitMap);
		return ans;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	vector<string> abc;



	string digits;
	getline(cin, digits);

	Solution ob;
	abc = ob.letterCombinations(digits);

	for (int i = 0; i < abc.size(); i++) {

		cout << abc[i] << " ";

		cout << "\n";
	}

	return 0;
}