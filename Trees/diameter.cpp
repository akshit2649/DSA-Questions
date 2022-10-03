#include <bits/stdc++h>
using namespace std;

int height(Node* root, int& maxi){
	if(root == NULL) return 0;
	int lh = height(root->left, maxi);
	int rh = height(root->right, maxi);
	maxi = max(maxi, lh+rh);
	return 1+max(lh, rh);
}

int diameter(Node* root) {
	int maxi = 1;
	height(root, maxi);
	return maxi;
}

int main(){
	return 0;
}