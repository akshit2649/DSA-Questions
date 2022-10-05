#include <bits/stdc++.h>
using namespace std;

bool findA(Node* root, int a, vector<Node*> one) {
	if (!root) return false;

	one.push_back(root);
	if (root->data == a) return true;
	if (findA(root->left, a, one) || findA(root->right, a, one)) return true;

	one.pop_back();
	return false;
}

bool findB(Node* root, int b, vector<Node*> two) {
	if (!root) return false;

	two.push_back(root);
	if (root->data == b) return true;
	if (findB(root->left, b, two) || findB(root->right, b, two)) return true;

	two.pop_back();
	return false;
}

int findDist(Node* root, int a, int b) {
	vector<Node*> one;
	vector<Node*> two;

	findA(root, a, one);
	findB(root, b, two);

	int i = 0;
	int j = 0;
	int idx = 0;

	while (i < one.size() && j < two.size()) {
		if(one[i]->data == two[j]->data){
			idx = i;
		}	
	}

	return ((one.size()-idx+1) + (two.size()-idx+1));
}

int main() {
	return 0;
}