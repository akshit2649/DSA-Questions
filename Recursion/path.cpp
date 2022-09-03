#include <bits/stdc++.h>
using namespace std;

int path(int s, int e){
	int ans=0;

	if(s==e){
		return 1;
	}
	if(s>e) return 0;

	for(int i=1;i<=6;i++){
		ans+=path(s+i,e);
	}

	return ans;
}

int main(){
	cout<<path(0,3)<<endl;
	return 0;
}