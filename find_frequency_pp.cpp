#include <iostream>
using namespace std;
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

int main() {
	// your code goes here

#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("Input.txt", "r", stdin);
// for writing output to output1.txt
	freopen("Output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int arr[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int T;
	cin >> T;
	while (T--) {
		int target;
		cin >> target;
		auto ans = count(arr, n, target);
		cout << ans << "\n";
	}
	return 0;
}