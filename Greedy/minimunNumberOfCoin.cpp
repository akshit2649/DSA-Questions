#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N) {
	int curr[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int idx = 9;
	vector<int> res;
	int temp = N;
	while (temp) {
		if (temp == curr[idx]) {
			res.push_back(curr[idx]);
			return res;
		}
		else if (temp < curr[idx]) {
			idx--;
		}
		else {
			res.push_back(curr[idx]);
			temp = temp - curr[idx];
		}
	}
	return res;
}

int main() {
	int N = 43;
	vector<int> res = minPartition(N);
	for (auto it : res) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}