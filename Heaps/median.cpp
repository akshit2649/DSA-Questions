#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	priority_queue<int>s; //max heap
	priority_queue<int, vector<int>, greater<int>>g; //min heap
	//Function to insert heap.
	void insertHeap(int &x)
	{
		if (s.size() == 0) {
			s.push(x);
			return;
		}

		if (s.size() > g.size()) {
			if (x < s.top()) {
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else g.push(x);
		}
		else{
			if(x<s.top()){
				s.push(x);
			}
			else{
				g.push(x);
				s.push(g.top());
				g.pop();
			}
		}
	}
	//Function to balance heaps.
	void balanceHeaps()
	{

	}
	//Function to return Median.
	double getMedian()
	{
		if (s.size() == g.size()) {
			return (double)(s.top() + g.top()) / 2.0;
		}
		else return s.top();
	}
};

int main() {
	Solution obj;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		obj.insertHeap(x);
		cout << floor(obj.getMedian()) << endl;
	}
	return 0;
}

