#include <bits/stdc++.h>
using namespace std;

vector<int> verticalOrder(Node *root) {
	// vector<int> res;
	// if(!root) return res;
	// map<int, map<int, multiset<int>>> m;
	// queue<pair<Node*,pair<int,int>>> q; //node, vertical, level
	// q.push({root,{0,0}});
	// while(!q.empty()){
	// 	Node* node = q.front().first;
	// 	int x = q.front().second.first;
	// 	int y = q.front().second.second;
	// 	q.pop();
	// 	m[x][y].insert(node->data);
	// 	if(node->left) p.push({node->left,{x-1,y+1}});
	// 	if(node->right) p.push({node->right,{x+1,y+1}});
	// }
	// vector<vector<int>> ans;
	// for(auto p : m){
	// 	vector<int> col;
	// 	for(auto q : p.second){
	// 		col.insert(col.end(), q.second.begin(), q.second.end());
	// 	}
	// 	ans.push_back(col);
	// }
	// for(auto it : ans){
	// 	res.insert(res.end(), it.begin(), it.end());
	// }
	// return res;
	map<int, vector<int>> m;
	queue<pair<Node*, int>> q;
	vector<int> ans;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		pair<Node*, int> temp = q.front();
		q.pop();
		Node *frontNode = temp.first;
		int hd = temp.second;
		m[hd].push_back(frontNode->data);
		if (frontNode->left) q.push(make_pair(frontNode->left, hd - 1));
		if (frontNode->right) q.push(make_pair(frontNode->right, hd + 1));
	}
	for (auto i : m) {
		for (auto j : i.second) {
			ans.push_back(j);
		}
	}
	return ans;
}

int main() {
	return 0;
}