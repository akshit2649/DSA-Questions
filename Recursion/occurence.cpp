#include <bits/stdc++.h>
using namespace std;

int lastOcc(int arr[], int i, int x,int n){
	if(i == n) return -1;
	int liisa = lastOcc(arr, i+1, x,n);
	if(liisa == -1){
		if(arr[i] == x)return i;
		else return -1;
	}
	else return liisa;
}

int main(){
	int arr[] = {4,2,1,2,5,2,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<lastOcc(arr, 0 ,2,n)<<endl;
	return 0;
}