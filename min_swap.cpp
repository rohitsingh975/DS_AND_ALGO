#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//int minSwap(int *arr, int n, int k);
int minSwap(int *arr, int n, int k) {
	// Complet the function

	int window_size = 0, cnt = 0, final_count = 0;

	//calculating window size
	for (int i = 0; i < n; i++)	{

		if (arr[i] <= k)
			window_size++;
	}

	for (int j = 0; j < window_size; j++)	{

		if (arr[j] > k)
			cnt++;
	}

	final_count = cnt;

	for (int j = window_size; j < n; j++)	{

		if (arr[j] > k)
			cnt++;

		if (arr[j - window_size] > k)
			cnt--;

		final_count = min(final_count, cnt);
	}

	return final_count;
}

int main() {

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int k, n;

	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	cout << minSwap(arr, n, k) << endl;

	return 0;
}




