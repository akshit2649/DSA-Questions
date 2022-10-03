#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	if(intervals.size() == 0) return res;
	sort(intervals.begin(), intervals.end());
	int first = intervals[0][0];
	int second = intervals[0][1];
	for(auto it : intervals){
		if(it[0]<=second){
			second = max(it[1],second);
		}else{
			res.push_back({first,second});
			first = it[0];
			second = it[1];
		}
	}
	res.push_back({first, second});
	return res;
}

int main() {
	vector<vector<int>> intervals =  {{6,8},{1,9},{2,4},{4,7}}; //{{1,9},{2,4},{4,7},{6,8}}
	vector<vector<int>> ans = overlappedInterval(intervals);
	for(auto it : ans){
		for(auto x : it){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
