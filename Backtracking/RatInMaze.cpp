#include <bits/stdc++.h>
using namespace std;

#define n 5

bool isSafe(int arr[n][n], int x, int y){
	if(x<n and y<n and arr[x][y] == 1) return true;
	return false;
}

bool ratInMaze(int arr[n][n], int x, int y, int solArr[n][n]){

	if(x==n-1 and y==n-1) {
		solArr[x][y] = 1;
		return true;
	}
	if(isSafe(arr, x, y)){
		solArr[x][y] = 1;
		if(ratInMaze(arr, x+1, y, solArr)){
			return true;
		}
		if(ratInMaze(arr, x, y+1, solArr)){
			return true;
		}
		solArr[x][y] = 0;
		return false;
	}

	return false;
}


int main(){

	int arr[n][n] = {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}};

	 int solArr[n][n] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

	ratInMaze(arr,0, 0,solArr);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<solArr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}