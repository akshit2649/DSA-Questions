#include <bits/stdc++.h>
using namespace std;

//Using recursion
void flatten(TreeNode* root){

}

//using stacks
void flatten(TreeNode* root){
	stack<TreeNode*> st;
	st.push(root);
	while(!st.empty()){
		TreeNode* curr = st.top();
		st.pop();
		if(curr->right) st.push(curr->right);
		if(curr->left) st.push(curr->left);
		if(!st.empty()) curr->right = st.top();
		curr->left = null;
	}	
}

int main(){
	return 0;
}