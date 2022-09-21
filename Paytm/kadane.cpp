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

long long maxSubarraySum(int arr[], int n) {
	int maxSum = INT_MIN;
	int curSum = 0;

	for (int i = 0; i < n; i++) {
		curSum+=arr[i];
		if(curSum> maxSum) maxSum = curSum;
		if (curSum < 0) {
			curSum = 0;
		}
	}

	return maxSum;

}

int main() {
	int Arr[] = {-1,-2,-3,-4};

	cout<<maxSubarraySum(Arr, sizeof(Arr)/sizeof(Arr[0]))<<endl;

	return 0;
}