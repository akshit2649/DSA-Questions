#include <bits/stdc++.h>
using namespace std;

vector<int>MorrisTraversalInorder(Node* root){
	vector<int> res;
	Node* cur = root;
	while(cur!=NULL){
		if(cur->left == NULL){
			res.push_back(cur->data);
			cur = cur->right;
		}
		else{
			Node* prev = cur->left;
			while(prev->right && prev->right != cur){
				prev = prev->right;
			}
			if(prev->right == NULL){
				prev->right = cur;
				cur = cur->left;
			}
			else{
				//prev pointing to the cur
				prev->right = NULL;
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
	}
	return res;
}

vector<int>MorrisTraversalPreOrder(Node* root){
	vector<int> res;
	Node* cur = root;
	while(cur!=NULL){
		if(cur->left == NULL){
			res.push_back(cur->data);
			cur = cur->right;
		}
		else{
			Node* prev = cur->left;
			while(prev->right && prev->right != cur){
				prev = prev->right;
			}
			if(prev->right == NULL){
				prev->right = cur;
				res.push_back(cur->val);
				cur = cur->left;
			}
			else{
				//prev pointing to the cur
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
	return res;
}
int main(){
	return 0;
}