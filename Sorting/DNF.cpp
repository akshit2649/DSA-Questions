#include <bits/stdc++.h>
using namespace std;

void dnf(int arr[], int n){
	int lo = 0;
	int hi = n;
	int mid = 0;

	while(mid<=hi){
		if(arr[mid] == 0){
			swap(arr[lo], arr[mid]);
			lo++;
			mid++;
		}
		if(arr[mid] == 1) mid++;
		if(arr[mid] == 2) {
			swap(arr[hi], arr[mid]);
			hi--;
		}
	}
}

int main(){
	int arr[] = {1,1,2,0,0,1,2,2,1,0};

	int n = sizeof(arr)/sizeof(arr[0]);

	dnf(arr, n-1);

	for(auto x : arr){
		cout<<x<<" ";
	}

	return 0;
}