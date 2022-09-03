#include <bits/stdc++.h>
using namespace std;

void pivot(int arr[], int l, int r){
	int p = arr[1];

	int i = l-1;

	for(int j = l;j<r;j++){
		if(arr[j]<p){
			i++;
			swap(arr[j], arr[i]);
		}
	}

	swap(arr[i+1],arr[r]);
}

int main(){

	int arr[] = {5,4,3,2,1};

	pivot(arr, 0, 4);

	for(auto x : arr){
		cout<<x<<" ";
	}

	return 0;
}