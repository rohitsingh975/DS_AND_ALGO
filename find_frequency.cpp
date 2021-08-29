/*
https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int findFirst(int nums[], int n, int target)
    {
        int ans = -1;
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else  {
                if (mid == 0) {
                    ans = mid;
                    s = mid + 1;
                } else if (nums[mid - 1] != target) {
                    ans = mid;
                    e = mid - 1;
                }
                else
                    e = mid - 1;
            }
        }
        return ans;
    }

    int findLast(int nums[], int n, int target)
    {
        int ans = -1;
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else  {
                if (mid == n - 1) {
                    ans = mid;
                    e = mid - 1;
                }
                else if (nums[mid + 1] != target) {
                    ans = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
        }
        return ans;
    }

    int count(int arr[], int n, int x) {
        // code here
        int firstOccur = findFirst(arr, n, x);
        int lastOccur = findLast(arr, n, x);

        //cout << lastOccur;

        if (firstOccur == -1 && lastOccur == -1)
            return 0;
        else
            return lastOccur - firstOccur + 1;
    }
};

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
    freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
    freopen("Output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;
    int arr[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.count(arr, n, x);
    cout << ans << "\n";

    return 0;

}