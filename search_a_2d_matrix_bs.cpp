#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector< vector<int> > &arr, int i, int j_low,
                  int j_high, int x)
{
    while (j_low <= j_high)
    {
        int j_mid = (j_low + j_high) / 2;

        // Element found
        if (arr[i][j_mid] == x)
        {
            cout << "true" << "\n";
            return;
        }

        else if (arr[i][j_mid] > x)
            j_high = j_mid - 1;

        else
            j_low = j_mid + 1;
    }

    // element not found
    cout << "false" << "\n";
}

void seach2DMatrix(vector< vector<int> > &arr, int n, int m, int x) {
    // Single row matrix
    if (n == 1)
    {
        binarySearch(arr, 0, 0, m - 1, x);
        return;
    }

    // Do binary search in middle column.
    // Condition to terminate the loop when the
    // 2 desired rows are found
    int i_low = 0;
    int i_high = n - 1;
    int j_mid = m / 2;
    while ((i_low + 1) < i_high)
    {
        int i_mid = (i_low + i_high) / 2;

        // element found
        if (arr[i_mid][j_mid] == x)
        {
            cout << "true" << "\n";
            return;
        }

        else if (arr[i_mid][j_mid] > x)
            i_high = i_mid;

        else
            i_low = i_mid;
    }

    // If element is present on the mid of the
    // two rows
    if (arr[i_low][j_mid] == x)
        cout << "true" << "\n";
    else if (arr[i_low + 1][j_mid] == x)
        cout << "true" << "\n";

    // search element on 1st half of 1st row
    else if (x <= arr[i_low][j_mid - 1])
        binarySearch(arr, i_low, 0, j_mid - 1, x);

    // Search element on 2nd half of 1st row
    else if (x >= arr[i_low][j_mid + 1]  &&
             x <= arr[i_low][m - 1])
        binarySearch(arr, i_low, j_mid + 1, m - 1, x);

    // Search element on 1st half of 2nd row
    else if (x <= arr[i_low + 1][j_mid - 1])
        binarySearch(arr, i_low + 1, 0, j_mid - 1, x);

    // search element on 2nd half of 2nd row
    else
        binarySearch(arr, i_low + 1, j_mid + 1, m - 1, x);
}

int main() {

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("Input.txt", "r", stdin);
    // for writing output to output1.txt
    freopen("Output.txt", "w", stdout);
#endif

    int M, N;
    cin >> M >> N;
    vector<vector<int>> arr( M , vector<int> (N));

    for (int a = 0; a < M; a++)
    {
        for (int b = 0; b < N; b++)
        {
            cin >> arr[a][b];
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int target;
        cin >> target;
        seach2DMatrix(arr, M, N, target);
    }

    return 0;
}