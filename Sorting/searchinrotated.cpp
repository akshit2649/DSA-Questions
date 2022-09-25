#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int key, int s, int e) {
	while (s <= e) {
		int mid = s + (e - s) / 2;
		// cout<<"mid->"<<mid<<endl;
		if (v[mid] == key) return mid;
		else if (v[mid] > key) e = mid - 1;
		else s = mid + 1;
	}
	return -1;
}

int getPivot(vector<int> v, int n) {
	int s = 0;
	int e = n;
	while (s <= e) {
		int mid = s + (e - s) / 2;		
		if (mid == 0 && v[mid] > v[mid + 1]) return mid;
		else if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1]) return mid;
		else if (v[mid] > v[n]) s = mid + 1;
		else e = mid - 1;
	}
	return e;
}

int Search(vector<int> vec, int key) {
	int n = vec.size();
	if (vec[0] < vec[n - 1]) return binarySearch(vec, key, 0, n - 1);
	if (vec[0] == key) return 0;
	else if (vec[n - 1] == key) return n - 1;
	int pivot = getPivot(vec, n - 1);
	if (vec[pivot] == key) return pivot;
	else if (vec[0] < key ) return binarySearch(vec, key, 0, pivot);
	else return binarySearch(vec, key, pivot + 1, n - 1);
	return -1;
}

int main() {
	vector<int> v = {4, 5, 1, 2, 3};
	int K = 1;
	cout << Search(v, K) << endl;
	return 0;
}