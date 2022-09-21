#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){

	vector<int> v = {1,3,-1,-3,5,3,6,7};
	int k =3;
	deque<int> q;
	int i=0,j=0;
	vector<int> ans;
	
	while(j<v.size()){
		while(!q.empty() && q.back()<v[j]) q.pop_back();
		q.push_back(v[j]);	
		if(j-i+1<k) j++;
		else{
			ans.push_back(q.front());
			if(q.front() == v[i]) q.pop_front();
			i++;
			j++;
		}
	}

	for(auto i : ans){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}