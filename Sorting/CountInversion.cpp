#include <bits/stdc++.h>
using namespace std;

long long bruteForce(int arr[], int n){
	long long inv = 0;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]) inv++;
		}
	}

	return inv;
	//O(n^2)
}

long long merge(int arr[], int l, int mid, int r){
	long long inv = 0;
	int n1 = mid-l+1;
	int n2 = r-mid;

	int a[n1];
	int b[n2];

	for(int i=0;i<n1;i++){
		a[i] = arr[l+i];
	}

	for(int i=0;i<n2;i++){
		b[i] = arr[mid+1+i];
	}

	int i=0;
	int j=0;
	int k=l;

	while(i<n1 and j<n2){
		if(a[i]<b[j]){
			arr[k] = a[i];
			i++;
			k++;
		}
		else{
			arr[k] = b[j];
			inv+=n1-i;
			// a[i] > b[j] and i < j
			j++;
			k++;
		}
	}

	while(i<n1){
		arr[k] = a[i];
		k++;
		i++;
	}

	while(j<n2){
		arr[k] = b[j];
		k++;
		j++;
	}

	return inv;
}

long long countInv(int arr[],int l, int r){
	long long inv = 0;
	if(l<r){

		int mid = (l+r)/2;
		inv+=countInv(arr, l, mid);
		inv+=countInv(arr, mid+1, r);

		inv+=merge(arr, l, mid, r);
	}
	return inv;
}

int main(){

	int arr[] = {3,5,6,9,1,2,7,8}; //10

	int n = sizeof(arr)/sizeof(arr[0]);

	long long ans = countInv(arr,0,n-1);

	// long long ans = bruteForce(arr, n);

	cout<<ans<<endl;

	return 0;
}