//Alternate approach available
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {

		int n = nums.size(), total_sum = 0;

		for (int i = 0; i < n; i++) {

			int number = nums[i], count = 0, sum = 0;

			for (int j = 1; j * j <= number; j++) {

				if (number % j == 0) {

					if (j * j == number) {
						count += 1;
						sum += j;
					} else {
						count += 2;
						sum += j;
						sum += number / j;
					}
				}
			}

			if (count == 4)
				total_sum += sum;
		}

		return total_sum;
	}
};


int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> nums;
	int input;

	while (cin >> input)
		nums.push_back(input);

	Solution ob;

	cout << ob.sumFourDivisors(nums) << endl;

	return 0;
}



// for (int i = 0; i < n; i++)
// 	cout << frequency[i] << " ";