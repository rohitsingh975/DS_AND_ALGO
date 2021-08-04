#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int T, B, L, R, dir;

		T = 0;
		B = matrix.size() - 1;
		L = 0;
		R = matrix[0].size() - 1;
		dir = 0;
		int i;

		vector<int> ans;

		while (T <= B && L <= R)
		{
			if (dir == 0)
			{
				for (i = L; i <= R; i++)
					ans.push_back(matrix[T][i]);
				T++;
			}
			else if (dir == 1)
			{
				for (i = T; i <= B; i++)
					ans.push_back(matrix[i][R]);
				R--;
			}
			else if (dir == 2)
			{
				for (i = R; i >= L; i--)
					ans.push_back(matrix[B][i]);
				B--;
			}
			else if (dir == 3)
			{
				for (i = B; i >= T; i--)
					ans.push_back(matrix[i][L]);
				L++;

			}
			dir = (dir + 1) % 4;
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

	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	Solution ob;

	vector<int> ans;

	ans = ob.spiralOrder(matrix);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
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