#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
	int students = 1;
	int curr = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>mid) return false;
		if(arr[i]+curr>mid){
			curr = arr[i];
			students++;
			if(students>m) return false;
		}
		else curr+=arr[i];
	}

	return true;
}

int findPages(int A [], int N, int M)
{
	if (N < M) return -1;
	int res = -1;

	int mx = INT_MIN;
	int sum = 0;

	for (int i = 0; i < N; i++)	{
		sum += A[i];
		mx = max(mx, A[i]);
	}

	int left = mx;
	int right = sum;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (isPossible(A, N, M, mid)) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	return res;
}

int main() {

	int N = 4;
	int A[] = {12, 34, 67, 90};
	int M = 2;

	        cout << findPages(A, N, M) << endl;
	return 0;
}