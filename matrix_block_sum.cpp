#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector < vector <int>> answer;
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {

		int m = mat.size();

		int n = mat[0].size();

		//Initialilzing array of size m * n
		answer = vector < vector <int>>(m, vector <int> (n));
		vector<vector<int>> dp(m, vector<int>(n, 0));

		//row wise sum
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				answer[i][j] = j - 1 < 0 ? mat[i][j] : answer[i][j - 1] + mat[i][j];
			}
		}

		//column wise sum
		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				answer[i][j] += answer[i - 1][j];
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int row1 = max(i - K, 0);
				int col1 = max(j - K, 0);
				int row2 = min(i + K, m - 1);
				int col2 = min(j + K, n - 1);
				dp[i][j] = sumRegion(row1, col1, row2, col2);
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		return dp;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		int ans = answer[row2][col2];
		int sub1 = col1 - 1 < 0 ? 0 : answer[row2][col1 - 1];
		int sub2 = row1 - 1 < 0 ? 0 : answer[row1 - 1][col2];
		int add = row1 - 1 < 0 || col1 - 1 < 0 ? 0 : answer[row1 - 1][col1 - 1];

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

	vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int K;
	cin >> K;

	Solution ob;

	ob.matrixBlockSum(mat, K);

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