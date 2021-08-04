#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n, min_price, max_price, profit = 0, prefix_profit = 0;

	n = prices.size();

	if (n <= 0)
	{
		return 0;
	}

	int suffix_profit[n + 1];

	suffix_profit[n - 1] = 0;
	max_price = prices[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		int new_profit = max_price - prices[i];
		suffix_profit[i] = max(suffix_profit[i + 1], new_profit);
		max_price = max(max_price, prices[i]);
	}


	min_price = prices[0];
	profit = suffix_profit[0];

	for (int i = 1; i < n; i++)
	{
		int new_profit = prices[i]  - min_price;
		prefix_profit = max(prefix_profit, new_profit);
		min_price = min(min_price, prices[i]);

		int profit_with_two_transaction = prefix_profit + suffix_profit[i];
		profit = max(profit, profit_with_two_transaction);
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