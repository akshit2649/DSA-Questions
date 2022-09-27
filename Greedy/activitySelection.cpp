#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	return b.second > a.second;
}

int activitySelection(vector<int> start, vector<int> end, int n) {
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) v.push_back({start[i], end[i]});
	sort(v.begin(), v.end(), cmp);
	int r = v[0].second;
	vector<int> res;
	res.push_back(v[0].first);	
	for(int i=1;i<v.size();i++){
		if(v[i].first > r){
			r = v[i].second;
			res.push_back(v[i].first);
		}
	}
	return res.size();
}

int main() {
	int n = 4;
	vector<int> start = { 1, 3, 2, 5};
	vector<int> end = { 2, 4, 3, 6};
	cout << activitySelection(start, end, n)<<endl;
	return 0;
}