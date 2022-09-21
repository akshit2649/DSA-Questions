#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
	sort(A,A+n);

	for(int i=0;i<n;i++){
		int lo = i+1;
		int hi = n-1;

		while(lo < hi){
			int current = A[i] + A[lo] + A[hi];
			if(current == X) return true;
			else if( current < X) lo++;
			else hi--;
		}
	}
	return false;
}

int main() {

	int arr[] = {1, 2, 4, 3, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 10;
	cout << find3Numbers(arr, n, k)<<endl;
	return 0;
}