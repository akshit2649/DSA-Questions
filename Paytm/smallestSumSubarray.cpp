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

int smallestSumSubarray(vector<int>& a){
      int minSum = INT_MAX;
      int curSum = 0;

      for(int i=0;i<a.size();i++){
      	curSum+=a[i];
      	if(curSum<minSum) minSum = curSum;
      	if(curSum>0) curSum = 0;
      }
      return minSum;
 }

int main() {
	vector<int> arr = {2, 6, 8, 1, 4};

	int ans = smallestSumSubarray(arr);

	cout<<ans<<endl;

	return 0;
}