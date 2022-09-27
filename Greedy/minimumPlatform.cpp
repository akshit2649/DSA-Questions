#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
	int k=0;

        int i=1;

        int platform=1;

        sort(arr, arr+n);

        sort(dep, dep+n);

        while(i<n)

        {

            if(arr[i]<=dep[k])

            {

                platform++;

            }

            else k++;

            

        i++;

        }

        return platform;
}

int main() {
	int n = 6;
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	cout << findPlatform(arr, dep, n) << endl;
	return 0;
}