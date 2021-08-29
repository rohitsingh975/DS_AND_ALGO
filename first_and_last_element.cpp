/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/


#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int ans = -1;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else  {
                if (mid == 0) {
                    ans = mid;
                    e = mid - 1;
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

    int findLast(vector<int>& nums, int target)
    {
        int ans = -1;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
            else  {
                if (mid == nums.size() - 1) {
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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result(2);
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);
        return result;
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
    vector<int> ans = ob.searchRange(N, target);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}



// for (int i = 0; i < n; i++)
//  cout << frequency[i] << " ";