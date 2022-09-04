#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &a, int idx, vector<vector<int>> &ans){
    if(idx == a.size()) {
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        swap(a[i],a[idx]);
        permute(a, idx+1, ans);
        swap(a[i],a[idx]);
    }
}

int main(){

    vector<int> a = {1,2,3};

    vector<vector<int>> ans;

    permute(a, 0, ans);

    for(auto a : ans){
        for(auto x : a){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}