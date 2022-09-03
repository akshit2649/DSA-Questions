//arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=......
#include <bits/stdc++.h>
using namespace std;
void waveSort(int arr[], int n){
	for(int i=1;i<n-1;i+=2){
		if(arr[i]>arr[i-1]){
			swap(arr[i], arr[i-1]);
		}
		if(i<=n-2 and arr[i]>arr[i+1]){
			swap(arr[i], arr[i+1]);
		}
	}
}

int main(){
	int arr[] = {1,3,4,7,5,6,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	waveSort(arr, n);
	waveSort(arr, n);

	for(auto x : arr){
		cout<<x<<" ";
	}

	return 0;
}
