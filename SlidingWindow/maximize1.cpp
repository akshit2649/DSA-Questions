#include <bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int k) {
	int ans = 0;
	int zeroCount = 0;
	int i = 0;
	for(int j=0;j<n;j++){
		if(arr[j] == 0 ){
			zeroCount++;
		}

		while(zeroCount>k){
			if(arr[i] == 0){
				zeroCount--;
			}
			i++;
		}

		ans = max(ans,j-i+1);
	}
	return ans;
}

int main() {
	int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findZeroes(arr, n, 2) << endl;

	return 0;
}