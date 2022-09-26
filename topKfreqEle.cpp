#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		m[nums[i]]++;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto it : m) {
		pq.push({it.second, it.first});
		if(pq.size()>k) pq.pop();
	}
	vector<int> res;
	while(!pq.empty()){
		res.push_back(pq.top().second);
		pq.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	vector<int>  nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> ans = topKFrequent(nums, k);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout<<endl;
	return 0;
}