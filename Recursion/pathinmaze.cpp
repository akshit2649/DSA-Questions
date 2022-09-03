#include <bits/stdc++.h>
using namespace std;

int countPathMaze(int n, int i, int j){
	int ans=0;
	if(i==n-1 and j == n-1){
		return 1;
	}

	if(i>=n || j>=n) return 0;

	ans+=countPathMaze(n, i+1, j);
	ans+=countPathMaze(n, i, j+1);
	
	return ans;
}

int main(){

	cout<<countPathMaze(3,0,0)<<endl;

	return 0;
}