#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
	return a.size() < b.size();
}

int main() {
	vector<vector<int>> res;
	for (int i = 1; i <= 4; i++) {
		for (int j = i; j <= 4; j++) {
			vector<int> temp;
			for (int k = i; k <= j; k++) {
				temp.push_back(k);
			}
			res.push_back(temp);
		}
	}

	sort(res.begin(), res.end(),cmp);

	for (auto it : res) {
		for (auto x : it) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}