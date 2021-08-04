#include <bits/stdc++.h>
#include <vector>
using namespace std;

class NumMatrix {
public:
	vector < vector <int>> dp;
	NumMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();

		if (n == 0)
			return;

		int m = matrix[0].size();

		//Initialilzing array of size n * m
		dp = vector < vector <int>>(n, vector <int> (m));

		//row wise sum
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				dp[i][j] = j - 1 < 0 ? matrix[i][j] : dp[i][j - 1] + matrix[i][j];
			}
		}

		//column wise sum
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				dp[i][j] += dp[i - 1][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		int ans = dp[row2][col2];
		int sub1 = col1 - 1 < 0 ? 0 : dp[row2][col1 - 1];
		int sub2 = row1 - 1 < 0 ? 0 : dp[row1 - 1][col2];
		int add = row1 - 1 < 0 || col1 - 1 < 0 ? 0 : dp[row1 - 1][col1 - 1];

		return ans - sub1 - sub2 + add;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<vector<int>> mat = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

	NumMatrix ob(mat);

	cout << ob.sumRegion(2, 1, 4, 3) << endl;
	cout << ob.sumRegion(1, 1, 2, 2) << endl;
	cout << ob.sumRegion(1, 2, 2, 4) << endl;

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