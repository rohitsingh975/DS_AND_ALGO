#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int m = matrix.size();

		if (m == 0)
			return false;

		int n = matrix[0].size();

		int i = 0 , j = n - 1;

		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
			{
				return true;
			}
			else if (matrix[i][j] > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return false;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

	int target;
	cin >> target;

	Solution ob;

	cout << ob.searchMatrix(mat, target) << endl;

	return 0;
}


/*for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << matrix[i][j] << " ";
	}
	cout << endl;
}*/
