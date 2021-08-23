/*
*https://www.hackerrank.com/challenges/recursive-digit-sum/problem
int superDigit(string n, int k) {
    if(n.size() == 1)
        return stoi(n);

    long super = 0;
    for(char& c:n)
        super += c-48;

    super *= k;
    return superDigit(to_string(super), 1);

    cout << n;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	int super_digit(int nums) {
		int sum = 0;

		if (nums < 10) {
			return nums;
		} else {

			while (nums != 0) {
				sum = sum + nums % 10;
				nums = nums / 10;
			}
		}
		sum = super_digit(sum);
		return sum;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	int nums = 9875, ans;


	Solution ob;
	ans = ob.super_digit(nums);

	cout << ans;

	return 0;
}