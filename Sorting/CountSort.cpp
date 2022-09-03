#include <bits/stdc++.h>
using namespace std;

int main(){

	int arr[] = {1,3,2,3,4,1,6,4,3};
	int countArr[7];
	memset(countArr, 0, sizeof(countArr));

	for(auto x : arr){
		countArr[x]++;
	}

	for(int i=1;i<7;i++){
		countArr[i] = countArr[i-1]+countArr[i];
	}

	int ans[9];

	for(int i=8;i>=0;i--){
		int val = arr[i];
		countArr[val]--;
		ans[countArr[val]] = val;
	}		
	for(auto x : ans){
		cout<<x<<" ";
	}
	return 0;
}