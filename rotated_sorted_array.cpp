#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int N, int target) {

    int l = 0, h = N - 1;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == target)
            return m;
        else if (arr[m] >= arr[l])
        {
            if (target <= arr[m] && target >= arr[l])
                h = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (target >= arr[m] && target <= arr[h])
                l = m + 1;
            else
                h = m - 1;
        }
    }

    return -1;
}

int main() {

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("Input.txt", "r", stdin);
    // for writing output to output1.txt
    freopen("Output.txt", "w", stdout);
#endif

    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int t;
    cin >> t;

    while (t--)
    {
        int target;
        cin >> target;
        
        int ans = binarySearch(arr, N, target);
        cout << ans << "\n";
    }

    return 0;
}

