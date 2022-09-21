#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;

int trap(vector<int>& height) {
	int n = height.size();
	vector<int> maxR(n);
	vector<int> maxL(n);
	maxL[0] = height[0];

	for (int i = 1; i < n; i++) {
		if (height[i] > maxL[i - 1]) maxL[i] = height[i];
		else maxL[i] = maxL[i - 1];
	}

	maxR[0] = height[n - 1];
	int idx = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (height[i] > maxR[idx - 1]) maxR[idx] = height[i];
		else maxR[idx] = maxR[idx - 1];
		idx++;
	}

	reverse(maxR.begin(), maxR.end());

	vector<int> v;
	vector<int> water;

	for (int i = 0; i < n; ++i) {
		v.push_back(min(maxR[i], maxL[i]));
		water.push_back(v[i] - height[i]);
	}

	int ans = accumulate(water.begin(), water.end(), 0);
	return ans;
}

int main() {

	vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap(height) << endl;

	return 0;
	// https://leetcode.com/problems/trapping-rain-water/
}
