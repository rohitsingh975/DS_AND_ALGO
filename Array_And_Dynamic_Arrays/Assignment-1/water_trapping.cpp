//https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;



int trap(vector<int>& height) {

	int deciding_height = INT_MIN, amount = 0, n;
	n = height.size();
	if (n <= 0)
	{
		return 0;
	}

	int prefix_max[n], suffix_max[n];



	//Prefix max
	//0 1 1 2 2 2 2 3 3 3 3 3
	prefix_max[0] = height[0];

	for (int i = 1; i < n; i++)
	{
		prefix_max[i] = max(prefix_max[i - 1], height[i]);
	}

	//Suffix max
	//3 3 3 3 3 3 3 3 2 2 2 1
	suffix_max[n - 1] = height[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		suffix_max[i] = max(suffix_max[i + 1], height[i]);
	}

	//height - 0 1 0 2 1 0 1 3 2 1 2 1
	for (int i = 1; i < n; i++)
	{
		deciding_height = min(prefix_max[i], suffix_max[i]);

		if (deciding_height > height[i])
		{
			amount += (deciding_height - height[i]);
		}
	}

	return amount;
}


int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	vector<int> height;
	int input, amount = INT_MIN;

	while (cin >> input)
		height.push_back(input);

	amount = trap(height);
	cout << amount;
}


/*class Solution {
public:
    int trap(vector<int>& height) {
        int deciding_height = INT_MIN, amount = 0, n;
        n = height.size();
       
        if (n <= 0)
        {
            return 0;
        }
        
         int prefix_max[n], suffix_max[n];
        
        //Prefix max
        prefix_max[0] = height[0];

        for (int i = 1; i < n; i++)
        {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        //Suffix max
        suffix_max[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }

        for (int i = 1; i < n; i++)
        {
            deciding_height = min(prefix_max[i], suffix_max[i]);

            if (deciding_height > height[i])
            {
                amount += (deciding_height - height[i]);
            }
        }

	    return amount;
    }
};*/