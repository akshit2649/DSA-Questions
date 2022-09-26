#include <bits/stdc++.h>
using namespace std;

int findSubArraySum(int arr[], int n, int k) {
	int ans = 0;
	unordered_map<int, int> m;
	int currSum = 0;
	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		if (currSum == k) ans++;
		if (m.find(currSum - k) != m.end()) {
			ans+=m[currSum-k];
		}
		m[currSum]++;
	}
	return ans;
}

int main() {
	int N = 5;
	int Arr[] = {10 , 2, -2, -20, 10};
	int k = -10;
	cout << findSubArraySum(Arr, N, k) << endl;
	return 0;
}