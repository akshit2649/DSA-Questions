#include <bits/stdc++.h>
using namespace std;
vector<int> topView(Node *root){
	 vector<int> res;
	if(!root) return res;
	map<int,Node*> m;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
    	Node* temp = q.front().first;
    	int level = q.front().second;
    	q.pop();
    	if(m.find(level) == m.end()) m[level] = temp;	
    	if(temp->left) q.push({temp->left,level-1});
    	if(temp->right) q.push({temp->right,level+1});
    } 
    for(auto it : m){
    	res.push_back(it.second->data);
    }
    return res;
        
  }
int main(){

	return 0;
}