#include <bits/stdc++.h>
using namespace std;

void cycleSort(int arr[], int n){
	int i = 0;
	while(i<n){
		int correct = arr[i]-1;
		if(arr[i]!=arr[correct]){
			swap(arr[i], arr[correct]);
		}
		else i++;
	}
}

int main(){
	//when given numbers from range 1,N
	int arr[] = {3,5,2,1,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	cycleSort(arr, n);//puts the elements on their correct indexes

	for(auto x : arr) cout<<x<<" ";
}