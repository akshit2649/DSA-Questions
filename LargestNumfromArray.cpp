#include <bits/stdc++.h>
using namespace std;
int maxDistToClosest(vector<int>& seats) {
	int left = -1;
	int maxDis = 0;

	for(int right = 0; right<seats.size();right++){
		if(seats[right] == 1){
			if(left == -1) maxDis = right;
			else{
				maxDis = max(maxDis, (right-left)/2);
			}
			left = right;
		}
	}

	int n = seats.size();

	if(seats[seats.size()-1] == 0){
		maxDis = max(maxDis, n - left -1);
	}


	return maxDis;
}

int main() {

	vector<int> seats ={1,0,0,0,1,0,1};

	int ans = maxDistToClosest(seats);

	cout<<ans<<endl;

	return 0;
}