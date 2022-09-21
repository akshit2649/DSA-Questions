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

vector<int> duplicates(int arr[], int n) {

        unordered_map<int,int> m;
        vector<int> v;

        for(int i=0;i<n;i++){
                m[arr[i]]++;
        }

        for(auto it : m){
                if(it.second>1) v.push_back(it.first);
        }

        if (v.size() == 0) return {-1};
        
        
        return v;
}

int main() {
        int a[] = {0,3,1,2};
        int n = sizeof(a)/sizeof(a[0]);

        vector<int> ans = duplicates(a, n);

        for(auto it : ans){
                cout<<it<<" ";
        }
        cout<<endl;
        return 0;
}