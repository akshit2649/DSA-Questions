#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int* arr, int n){
	//repetedly sort two adjacent elements if they are in wrong order
	//after each iteration the max element will reach the end of the array
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(arr[j-1]>arr[j]) swap(arr[j-1], arr[j]);
		}
	}

}

void selectionSort(int* arr, int n){
	//find the minimum element in unsorted array and swap it with element at beginnig
	for(int i =0;i<n;i++){
		// int min = INT_MAX;
		// int index;

		for(int j = i; j<n;j++){
			if(arr[j]<arr[i]) {
				// index = j;
				// min=arr[j];
				swap(arr[i],arr[j]);
			}
		}

		// swap(arr[i], arr[index]);
	}

}

int main(){

	int arr[5] = {4,2,1,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	// selectionSort(arr, n);
	bubbleSort(arr, n);

	for(auto x:arr){
		cout<<x<<" ";
	}

return 0;
}