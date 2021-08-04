#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
		// code here

		int i = 0 , j = m - 1, count = 0, total_count = INT_MIN, ans = -1;

		while (i < n && j >= 0)
		{
			if (arr[i][j] == 1)
			{
				count++;

				j--;

				if (count > total_count)
				{
					total_count = count;
					ans = i;
				}
			}
			else
			{
				i++;
				j = m - 1;
				count = 0;
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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// for (int i = 0; i < m; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	Solution ob;

	auto ans = ob.rowWithMax1s(arr, n, m);

	cout << ans << endl;

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
