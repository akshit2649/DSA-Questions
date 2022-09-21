#include <bits/stdc++.h>
using namespace std;

bool myComp(string &s1, string &s2) {
	return s1 + s2 >  s2 + s1;
}

string printLargest(vector<string> &arr) {
	sort(arr.begin(), arr.end(), myComp);
	string ans = "";
	for (auto &e : arr) {
		ans += e;
	}
	return ans;
}

int main() {

	int N = 5;
	vector<string> Arr = {"3", "30", "34", "5", "9"};

	cout << printLargest(Arr) << endl;
	return 0;
}