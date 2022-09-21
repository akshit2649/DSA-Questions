#include <bits/stdc++.h>
using namespace std;

class node {
	int data;
public:
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};


vector<vector<int>> levelOrder(node* root){
	vector<vector<int>> ans;
	if(root ==  NULL) return ans;
	queue<node*> q;

	q.push(root);

	while(!q.empty()){
		int size = q.size();

		vector<int> level;

		for(int i=0;i<size;i++){
			node* temp = q.front();
			q.pop();
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
			level.push_back(temp->data);
		}
		ans.push_back(level);
	}
	return ans;
}

int main(){


	return 0;
}