#include <bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int n){
	//insert the element on the right position
	for(int i=1;i<n;i++){
		int current  = arr[i];
		int j = i-1;
		while(arr[j]>current and j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}

}

int main(){
	int arr[6] = {12, 45, 23, 51, 19, 8};

	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, n);

	for(auto x : arr){
		cout<<x<<" ";
	}

	return 0;
}