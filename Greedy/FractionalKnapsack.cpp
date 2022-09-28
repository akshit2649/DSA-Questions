#include <bits/stdc++.h>
using namespace std;

struct  Item {
	int value;
	int weight;
};

bool cmp(Item a, Item b) {
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r2 > r1;
}

double fractionalKnapsack(int W, Item arr[], int n) {
	sort(arr, arr + n, cmp);

	int currW = 0;
	double finalValue = 0.0;

	for (int i = 0; i < n; i++) {
		if (currW + arr[i].weight <= W) {
			currW += arr[i].weight;
			finalValue += arr[i].value;
		}
		else {
			int rem = W - currW;
			finalValue = (double)(arr[i].value / (double)arr[i].weight) * (double)rem;
			return finalValue;
		}
	}
	return finalValue;
}

int main() {
	int n;
	int W;
	cin >> n;
	cin >> W;
	Item arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].value >> arr[i].weight;
	}
	cout << fractionalKnapsack(W, arr, n) << endl;
	return 0;
}