#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left < n and arr[largest] < arr[left]) {
		largest = left;
	}
	if (right < n and arr[largest] < arr[right]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

int main() {
	int arr[] = { -1, 51, 53, 55, 59, 58};
	int n = 5;
	for (int i = n / 2; i > 0; i--) {
		heapify(arr, n ,i);
	}
	cout <<"Printing the array"<< endl;
	for (int i = 1; i <=n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}