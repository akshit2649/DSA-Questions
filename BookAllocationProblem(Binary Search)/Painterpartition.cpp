#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossible(int arr[], int n, int k, ll mid) {
	int painter = 1;
	ll curr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) return false;
		if (arr[i] + curr > mid) {
			curr = arr[i];
			painter++;
			if (painter > k) return false;
		}
		else curr += arr[i];
	}
	return true;
}

long long minTime(int arr[], int n, int k)
{
	ll mx = INT_MIN;
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		mx = mx >= arr[i] ? mx : arr[i];
	}

	ll left = mx;
	ll right = sum;

	ll res = -1;

	while (left <= right) {
		ll mid = left + (right - left) / 2;

		if (isPossible(arr, n, k, mid)) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	return res;

}

int main() {
	int n = 5;
	int k = 3;
	int arr[] = {5, 10, 30, 20, 15};

	cout << minTime(arr, n, k) << endl;

	return 0;
}