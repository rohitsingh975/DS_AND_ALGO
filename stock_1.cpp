#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n, profit = 0, new_profit = 0, min_price;
	n = prices.size();

	if (n <= 0)
	{
		return 0;
	}

	min_price = prices[0];

	for (int i = 1; i < n; i++)
	{
		new_profit = prices[i] - min_price;
		profit = max(profit, new_profit);
		min_price = min(min_price, prices[i]);
	}

	return profit;
}


int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> prices;
	int input, profit = INT_MIN;

	while (cin >> input)
		prices.push_back(input);

	profit = maxProfit(prices);
	cout << profit;
}