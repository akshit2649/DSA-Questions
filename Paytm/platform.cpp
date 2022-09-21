#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <string>
#include <numeric>
#include <functional>
#include <map>
#include <iterator>


using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,  arr + n);
    sort(dep, dep + n);

    int plat = 1;
    int maxPlat = 1;

    int i =1;
    int j =0;

    while(i<n && j<n){
        if(arr[i]<=dep[j])
        {
            plat++;
            i++;
            
        }
        else if(arr[i]>dep[j]){
            plat--;
            j++;
        }

        if(plat>maxPlat) maxPlat = plat;

    }

    return maxPlat;
}

int main() {
    int arr[] = {900, 1100, 1235};
    int dep[] = {1000, 1200, 1240};

    cout<<findPlatform(arr, dep, 6)<<endl;
    return 0;
}