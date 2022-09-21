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

void inorderTraversal(node* root) {
	//left root right

	if(root == NULL) return;

	inorderTraversal(root->left);
	cout<<root->data;
	inorderTraversal(root->right);

}

void preorderTraversal(node* root) {
	//root left right

	if(root == NULL) return;

	cout<<root->data;

	preorderTraversal(root->left);
	preorderTraversal(root->right);


}

void postorderTraversal(node* root) {
	// left right root

	if(root == NULL)return;
	
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data;

}

int main() {


	return 0;
}