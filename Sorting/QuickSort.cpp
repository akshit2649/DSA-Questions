#include <bits/stdc++.h>
using namespace std;

//For worst case O(N^2) pivot is at the end
//Best O(nlogn)

// Important notes
// not stable
// in place
// merge sort is better for linked list due to memory allocation

void swap(int arr[], int i, int j ){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}

int partition(int arr[], int l, int r){
	int pivot = arr[r];
	int i = l-1; //store the last element that is smaller than pivot

	for(int j=l;j<r;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr, i, j);
		}
	}

	swap(arr, i+1, r);
	return i+1;
}

void quickSort(int arr[], int l, int r){

	if(l<r){

		int pi = partition(arr, l, r);

		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, r);
	}
}

int main(){

	int arr[5] = {5,4,3,2,1};

	quickSort(arr, 0,4);

	for(auto x : arr){
		cout<<x<<" ";
	}

	return 0;
}