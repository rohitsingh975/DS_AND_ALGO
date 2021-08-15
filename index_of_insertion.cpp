/*
*https://leetcode.com/problems/search-insert-position/
*Input: nums = [1,3,5,6], target = 5
*Output: 2
*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0, h = (nums.size() - 1), m = 0;

        while (l <= h)
        {
            m = (l + h) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                h = m - 1;
        }

        return h + 1;
    }
};


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
    freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
    freopen("Output.txt", "w", stdout);
#endif

    vector<int> N;
    int input, target;

    cin >> target;

    while (cin >> input)
        N.push_back(input);

    Solution ob;
    int ans = ob.searchInsert(N, target);

    cout << ans;

    return 0;
}



// for (int i = 0; i < n; i++)
//  cout << frequency[i] << " ";