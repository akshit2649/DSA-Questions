#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

vector<long long> r(long long arr[], int n){  

    stack<pair<int, int>> s;
     vector<long long> v;

     for(int i=n-1;i>=0;i--){
     	if(s.empty()) v.push_back(n);
     	else if(!s.empty() && s.top().first<arr[i]) v.push_back(s.top().second);
     	else if(!s.empty() && s.top().first>=arr[i]){
			while(!s.empty() && s.top().first>=arr[i]) s.pop();	
			if(s.empty()) v.push_back(n);
     		else v.push_back(s.top().second);
			}
     	
     	s.push(make_pair(arr[i],i));
     }
     reverse(v.begin(), v.end());
     return v;
}
    
vector<long long> l(long long arr[], int n){

     stack<pair<int, int>> s;
     vector<long long> v;

     for(int i=0;i<n;i++){
     	if(s.empty()) v.push_back(-1);
     	else if(!s.empty() && s.top().first<arr[i]) v.push_back(s.top().second);
     	else if(!s.empty() && s.top().first>=arr[i]){
			while(!s.empty() && s.top().first>=arr[i]) s.pop();	
			if(s.empty()) v.push_back(-1);
     		else v.push_back(s.top().second);
			}
     	
     	s.push(make_pair(arr[i],i));
     }

     return v;
}

long long getMaxArea(long long arr[], int n){

	vector<long long> right = r(arr, n);
    vector<long long> left = l(arr, n);
    vector<long long> w(n);

    for(int i=0;i<n;i++){
    	w[i] = right[i] - left[i] - 1;
    }
    
	long long ans = INT_MIN;
	long long area;

	for(int i=0;i<n;i++){
		area = arr[i] * w[i];
		if(area>ans){
			ans = area;
		}
	}

	return ans;    

 }

int main(){

	long long arr[] = {6,2,5,4,5,1,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	long long ans = getMaxArea(arr, n);
	cout<<ans<<endl;

	return 0;
}
