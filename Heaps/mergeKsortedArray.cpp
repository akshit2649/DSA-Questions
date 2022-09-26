#include <bits/stdc++.h>
using namespace std;

class data {
public:
	int val; int ap; int vp;
	data(int v, int apos, int vpos) {
		val = v;
		ap = apos;
		vp = vpos;
	}
};

struct myComparator {
	bool operator()(data &d1, data &d2) {
		return d1.val > d2.val;
	}
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
	vector<int> ans;
	priority_queue<data, vector<data>, myComparator> pq;
	for (int i = 0; i < k; i++) {
		data d(arr[i][0], i, 0);
		pq.push(d);
	}
	while (!pq.empty()) {
		data curr = pq.top();
		pq.pop();
		ans.push_back(curr.val);
		int apos = curr.ap;
		int vpos = curr.vp;
		if (vpos + 1 < arr[apos].size()) {
			data d(arr[apos][vpos + 1], apos, vpos + 1);
			pq.push(d);
		}
	}
	return ans;
}

int main() {
	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int k = 3;
	vector<int> ans = mergeKArrays(v, k);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}