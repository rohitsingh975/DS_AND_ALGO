#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector < vector <int>> ans( numRows );

		for (int i = 0; i < numRows; i++)
		{
			ans[i].resize(i + 1);
			ans[i][0] = ans[i][i] = 1;

			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
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

	int numRows;
	cin >> numRows;

	Solution ob;

	vector < vector <int>> ans( numRows , vector<int> (numRows));

	ans = ob.generate(numRows);


	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans.size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


/*
3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5

//row wise sum
3 3 4 8 10
5 11 14 16 17
1 3 3 4 9
4 5 5 6 13
1 1 4 4 9

//column wise sum
3 3 4 8 10
8 14 18 24 27
9 17 21 28 36
13 22 26 34 49
14 23 30 38 58
*/