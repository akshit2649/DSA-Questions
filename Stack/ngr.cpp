#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans;
        stack<int> s;

        for(int i=n-1;i>=0;i--){
        	if(s.empty()) ans.push_back(-1);
        	else if(!s.empty() && s.top()>arr[i]) ans.push_back(s.top());
        	else if(!s.empty() && s.top()<arr[i]){
        		while(!s.empty() && s.top()<arr[i]) s.pop();
        		if(s.empty()) ans.push_back(-1);
        		else ans.push_back(s.top());
        	}
        	s.push(arr[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
}

int main(){

	vector<long long> v = {1,3,2,4};

	vector<long long> ans;

	ans = nextLargerElement(v, v.size());

	for(auto i : ans){
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}