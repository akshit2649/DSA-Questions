#include <bits/stdc++.h>

using namespace std;

vector <int> calculateSpan(int price[], int n)
{
	stack<pair<int,int>> st;
	vector<int> res;

	for(int i=0;i<n;i++){
		int days =1;
		while(!st.empty() && st.top().first <= price[i]){
			days+=st.top().second;
			st.pop();
		}
		st.push(make_pair(price[i], days));
		res.push_back(days);
	}

	return res;
}

int main() {

	int price[] =  {100, 80, 60, 70, 60, 75, 85};

	int n = sizeof(price) / sizeof(price[0]);

	vector<int> ans = calculateSpan(price, n);

	for (auto it : ans) {
		cout << it << " ";
	} cout << endl;

	return 0;
}